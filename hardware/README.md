# Hardware and Enclosure

Family Orb combines a 3D-printed orb base, a snow globe DIY kit, and custom electronics to create a tangible ambient communication device.

## Enclosure concept

The physical enclosure was developed by combining:

- A commercially available 3D-printed magic orb base.
- A snow globe DIY kit.
- An Arduino Uno.
- A WS2812B RGB LED ring.
- A rotary encoder.
- A push button.
- A vibration motor.

The 3D-printed base and snow globe kit provided a practical starting point for the enclosure and worked well together as the physical form of the Family Orb.

## Modifications

The enclosure was adapted for the electronics through several physical modifications:

1. A side opening was drilled into the base to route the electronics wiring.
2. The internal components were positioned around the LED ring and Arduino board.
3. Parts were cut, glued, and secured during assembly.
4. The final enclosure was tested for stability and interaction comfort.

The photographs in the `images/` folder document this fabrication and assembly process.

## Component credit

The 3D-printed magic orb base was obtained from an existing online source and was not designed from scratch for this project. The snow globe component came from a commercially available DIY kit.

Source information:

- 3D-printed base: https://www.thingiverse.com/thing:6798213
- Snow globe DIY kit: https://www.amazon.com/dp/B0D98G982C?ref=ppx_yo2ov_dt_b_fed_asin_title

The components were modified and integrated with custom electronics for this HCI research prototype.

## Electronics

The current prototype uses an Arduino Uno for local interaction control. The LED ring displays color and flicker signals, while the rotary encoder and button support user input. A vibration motor provides haptic confirmation when a signal is sent.

## Future hardware direction

An ESP32-based version could support Wi-Fi connectivity and make the prototype more suitable for a complete multi-device communication system. The ESP32 includes Wi-Fi and Bluetooth capabilities, which could allow the orb to transmit signals to a remote family device or phone-side interface.

The current Arduino Uno version is intentionally documented as a local prototype and does not provide network communication.
