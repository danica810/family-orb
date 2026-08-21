#include <FastLED.h>

#define NUM_LEDS   16
#define DATA_PIN   6
#define VIB_PIN    5
#define ROTARY_PIN A1
#define BUTTON_PIN 4

// ★ 2700K Warm White (like a living room lamp)
#define WARM_R 255
#define WARM_G 165
#define WARM_B 67

CRGB leds[NUM_LEDS];

int angleBuffer          = 512;
uint8_t currentHue       = 0;
int freqMode             = 0;
int pressCount           = 0;
bool flashOn             = false;
int lastButtonState      = LOW;
bool isPressing          = false;
bool longPressHandled    = false;
uint8_t breathBrightness = 0;
bool breathingUp         = true;

unsigned long lastRotaryRead    = 0;
unsigned long lastFlashToggle   = 0;
unsigned long lastBreathUpdate  = 0;
unsigned long buttonPressedTime = 0;

const unsigned long LONG_PRESS_TIME = 1000;
const unsigned long DEBOUNCE_TIME   = 30;

// 4 Modes
const char* freqLabels[] = {
  "Warm Steady",
  "Color Steady",
  "Breathing",
  "Fast Flash"
};
const int NUM_MODES = 4;

void showWarmWhite();
void updateDisplay(unsigned long now);
void cycleFreq();
void sendSignal();
void effectBreathing(unsigned long now);
String getColorName(uint8_t hue);

void setup() {
  Serial.begin(9600);
  Serial.println("Family Orb v4.2 | Red → Purple Palette");
  Serial.println("Short press = cycle mode | Long press = SEND");

  pinMode(BUTTON_PIN, INPUT);
  pinMode(VIB_PIN, OUTPUT);

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(80);

  showWarmWhite();
  FastLED.show();
  Serial.println("Ready!");
}

void loop() {
  unsigned long now = millis();

  if (now - lastRotaryRead > 50) {
    int angle = analogRead(ROTARY_PIN);
    angleBuffer = (angleBuffer * 7 + angle * 3) / 10;
    // Fix Bug #2: match updateDisplay() range 0→192 (Red→Purple)
    currentHue = map(angleBuffer, 0, 660, 0, 192);
    lastRotaryRead = now;
  }

  int reading = digitalRead(BUTTON_PIN);

  if (reading == HIGH && lastButtonState == LOW) {
    buttonPressedTime = now;
    isPressing        = true;
    longPressHandled  = false;
  }

  if (reading == LOW && lastButtonState == HIGH) {
    if (isPressing && !longPressHandled) {
      unsigned long dur = now - buttonPressedTime;
      if (dur > DEBOUNCE_TIME && dur < LONG_PRESS_TIME) {
        cycleFreq();
      }
    }
    isPressing = false;
  }

  if (isPressing && !longPressHandled &&
      (now - buttonPressedTime >= LONG_PRESS_TIME)) {
    sendSignal();
    longPressHandled = true;
  }

  lastButtonState = reading;

  updateDisplay(now);
  FastLED.show();
  delay(10);
}

void updateDisplay(unsigned long now) {
  // Red(0) → Purple(192), avoids pink/white overshoot
  uint8_t smoothHue = map(angleBuffer, 0, 660, 0, 192);
  CRGB userColor = CRGB(CHSV(smoothHue, 255, 255));

  switch (freqMode) {
    case 0: // Warm Steady
      showWarmWhite();
      break;

    case 1: // Color Steady
      fill_solid(leds, NUM_LEDS, userColor);
      break;

    case 2: // Breathing
      effectBreathing(now);
      break;

    case 3: // Fast Flash
      if (now - lastFlashToggle > 200) {
        flashOn = !flashOn;
        lastFlashToggle = now;
      }
      fill_solid(leds, NUM_LEDS, flashOn ? userColor : CRGB::Black);
      break;
  }
}

// Breathing / Pulse effect
void effectBreathing(unsigned long now) {
  if (now - lastBreathUpdate > 10) {
    // Fix Bug #1: check before subtracting to prevent uint8_t underflow
    if (breathingUp) {
      breathBrightness += 2;
      if (breathBrightness >= 254) breathingUp = false;
    } else {
      if (breathBrightness <= 2) {
        breathBrightness = 0;
        breathingUp = true;
      } else {
        breathBrightness -= 2;
      }
    }
    lastBreathUpdate = now;
  }

  uint8_t smoothHue = map(angleBuffer, 0, 660, 0, 192);
  CRGB userColor = CRGB(CHSV(smoothHue, 255, breathBrightness));
  fill_solid(leds, NUM_LEDS, userColor);
}

void cycleFreq() {
  // Fix Bug #5: cap pressCount to avoid unbounded growth
  pressCount = (pressCount + 1) % NUM_MODES;
  freqMode = pressCount;
  flashOn = true;
  lastFlashToggle = millis();
  breathBrightness = 0;
  breathingUp = true;
  Serial.print("Mode → "); Serial.println(freqLabels[freqMode]);
}

void sendSignal() {
  // Apple-style haptic: short tap + pause + longer tap
  digitalWrite(VIB_PIN, HIGH); delay(100);
  digitalWrite(VIB_PIN, LOW);  delay(100);
  digitalWrite(VIB_PIN, HIGH); delay(350);
  digitalWrite(VIB_PIN, LOW);

  Serial.println("══════════════════");
  Serial.print("SENT | Color: ");  Serial.println(getColorName(currentHue));
  Serial.print("       Hue=");     Serial.println(currentHue);
  Serial.print("       Mode=");    Serial.println(freqLabels[freqMode]);
  Serial.println("══════════════════");

  freqMode   = 0;
  pressCount = 0;
  flashOn    = false;
  showWarmWhite();
  FastLED.show();
}

// 12-bucket color names across hue range 0–192 (Red → Purple)
String getColorName(uint8_t hue) {
  if      (hue < 16)  return "Red";
  else if (hue < 32)  return "Red-Orange";
  else if (hue < 48)  return "Orange";
  else if (hue < 64)  return "Amber";
  else if (hue < 80)  return "Yellow";
  else if (hue < 96)  return "Lime";
  else if (hue < 112) return "Green";
  else if (hue < 128) return "Teal";
  else if (hue < 144) return "Cyan";
  else if (hue < 160) return "Blue";
  else if (hue < 176) return "Indigo";
  else                return "Purple";  // 176–192
}

void showWarmWhite() {
  fill_solid(leds, NUM_LEDS, CRGB(WARM_R, WARM_G, WARM_B));
}
