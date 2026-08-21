# Interaction Flow

Family Orb uses a simple rotational and press-based interaction.

```text
User rotates the orb
        ↓
Selects a color
        ↓
Short-presses to choose a light pattern
        ↓
Observes the selected signal
        ↓
Long-presses for at least one second
        ↓
Signal is sent locally
        ↓
Vibration confirms the send action
```

## Interaction states

- **Color selection:** Rotation changes the hue.
- **Mode selection:** A short button press cycles through the available light patterns.
- **Send action:** A long button press triggers a send event.
- **Feedback:** The vibration motor confirms that the signal was sent.
- **Signal meaning:** The sender and recipient define the meaning together.

## Current limitation

The current prototype logs send actions locally. It does not yet send signals over Wi-Fi to a remote family member.

## Future interaction

A networked version could send the selected color and pattern to a phone-side interface or another Family Orb device.
