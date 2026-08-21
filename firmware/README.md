# Family Orb Firmware

This folder contains Arduino firmware for the Family Orb tangible communication prototype.

## Files

### `rainbow_version.ino`

This version uses a broader rainbow color palette for general prototype testing. It is useful when exploring how users assign personal meanings to different hues.

### `blueyellow_version.ino`

This version uses blue and yellow as an alternative color palette for users with color-vision deficiency. It is intended to reduce reliance on distinguishing among many similar hues.

Color is not used as the only communication channel. Flicker patterns, brightness, and haptic feedback should also support interpretation.

## Hardware

The firmware is designed for a prototype using:

- Arduino Uno.
- WS2812B RGB LED ring.
- Rotary encoder.
- Push button.
- Vibration motor.

## Important note

These sketches are research-prototype firmware. They currently support local interaction and signal display. They do not provide medical monitoring, emergency response, or network communication.

Before uploading a sketch to the Arduino, confirm the pin definitions and hardware wiring in the source code.
