# Family Orb

A tangible ambient communication device that helps older adults send low-effort, personalized signals to geographically distant family members.

## Overview

Family Orb is a research prototype designed to support intergenerational communication without requiring fluent smartphone use or synchronous availability. An older adult can rotate the orb to select a color, choose a light pattern, and press a button to send a signal. Family members can interpret the signal using meanings they have agreed upon together.

The project explores how tangible and ambient interaction can support older adults as active initiators of communication rather than passive recipients of monitoring technologies.

> **Project status:** Family Orb is an HCI research prototype. It is not a medical alert system, emergency-response device, or clinical product.

## Motivation

Older adults may experience barriers when using conventional communication technologies, including:

- Small or complex smartphone interfaces.
- Reduced fine-motor control or visual acuity.
- Different technology preferences across generations.
- Time-zone differences and mismatched schedules.
- The effort required to start a phone or video call.

Family Orb investigates whether a simple physical interaction can make small, asynchronous family check-ins easier.

## Interaction

1. Rotate the orb to select a color.
2. Short-press the button to cycle through light patterns.
3. Long-press the button for at least one second to send the signal.
4. Receive vibration feedback when the signal is sent.
5. Let the recipient interpret the signal according to a shared family vocabulary.

The prototype supports steady light, breathing-pulse, and fast-flicker signals. The meanings are intentionally customizable rather than fixed by the system.

## Prototype

The current prototype includes:

- Arduino Uno.
- 16-pixel WS2812B RGB LED ring.
- FastLED library.
- Rotary encoder for color selection.
- Push button for mode selection and sending.
- Vibration motor for haptic confirmation.
- 3D-printed pedestal enclosure with a crystal-ball orb.
- Multiple firmware versions for different color-display needs.

### Firmware versions

The `firmware/` folder contains two versions of the Family Orb firmware:

| Version | Description |
|---|---|
| `rainbow_version.ino` | Uses a broader rainbow color palette for general prototype testing. |
| `blueyellow_version.ino` | Uses a blue-and-yellow color palette as an alternative for users with color-vision deficiency. |

The blue-and-yellow version is intended to reduce reliance on a broad range of hue distinctions. However, color should not be the only way to communicate meaning. Future versions should also explore brightness, flicker patterns, labels, and haptic feedback so that signals remain understandable across different visual abilities.

During the usability study, signals were logged locally instead of being transmitted to remote family members. The communication network is part of future development.

## Research Questions

- Can older adults understand the interaction of rotating to select a color and pressing to change or send a signal?
- Do self-defined color and flicker meanings align with older adults’ mental models?
- What feedback, personalization, error-recovery, and accessibility features are needed for everyday use?

## Study

The project included a single-session usability study with eight adults aged 60 or older at two senior centers in the northeastern United States.

Each session included:

- An unstructured familiarization period.
- Structured signal-composition tasks.
- Tasks involving steady light, slow flicker, and fast flicker.
- Assignment of personal meanings to colors and patterns.
- A short semi-structured interview.

The study combined observation logs with interview data. Participation was voluntary, and the research protocol included informed consent and confidentiality procedures.

## Findings

- The core interaction model was broadly learnable, although some participants needed support while composing and sending signals.
- Steady signals were often associated with calm or routine status updates.
- Fast flicker was more readily associated with urgency or strong emotion.
- Slow flicker was ambiguous for some participants; three participants did not assign it a use case.
- Participants viewed Family Orb as a complement to the phone, especially when a phone call was inconvenient, inaccessible, or too effortful.
- Participants emphasized that senders and recipients need to agree on signal meanings in advance.
- Reference cards or cheat sheets may help families remember their shared signal vocabulary.
- Error recovery remains an open design challenge. Participants suggested cancel codes, resend behavior, clearer confirmation, and a small display.
- Five participants spontaneously identified possible value for DHH people, people with low vision, people with dexterity limitations, residents of nursing homes or hospitals, and non-native English speakers.

## Accessibility Directions

Future work should use participatory co-design with the communities who may use or benefit from the device. Possible directions include:

- Haptic and vibration alternatives for blind and low-vision users.
- Signal designs that do not depend on color alone.
- Larger, easier-to-grip controls.
- Reduced force requirements for turning and pressing.
- Clear feedback for selected, sent, and received states.
- Optional voice input for people who cannot easily reach or operate a phone.
- Additional testing with DHH users, people with low vision, people with dexterity limitations, and multilingual families.

## Repository Structure

```text
family-orb/
├── README.md
├── docs/
│   ├── concept.md
│   ├── research-questions.md
│   ├── findings.md
│   └── accessibility.md
├── firmware/
│   ├── family_orb.ino
│   └── README.md
├── hardware/
│   ├── bill-of-materials.md
│   ├── wiring.md
│   └── enclosure.md
├── study-materials/
│   ├── usability-script.md
│   └── survey-questions.md
├── analysis/
│   └── README.md
├── data/
│   └── README.md
└── media/
    └── README.md
```

## Privacy and Research Ethics

This repository should contain only public, de-identified, and approved materials.

Do not upload:

- Participant names or contact information.
- Signed consent forms.
- Raw audio recordings.
- Identifiable photographs.
- Raw interview transcripts with identifying details.
- Private interaction logs.
- IRB materials that are not approved for public distribution.
- Passwords, API keys, Wi-Fi credentials, or other secrets.

Store research records in the secure location approved by the study protocol. Share only de-identified summaries, reproducible code, and materials that are appropriate for public release.

## Future Work

- Connect multiple Family Orb devices over a network.
- Test signal delivery and confirmation with remote family members.
- Improve error recovery and message cancellation.
- Explore a small display or other non-color feedback.
- Investigate haptic, voice, and multimodal interaction.
- Conduct participatory co-design with diverse accessibility communities.
- Study longer-term use within intergenerational households.

## Citation

Lin, Yu-Chieh (Danica), et al. “Tangible Ambient Communication for Older Adults: Design and Usability of a Color-Based Intergenerational Signaling Device.” Manuscript submitted to ACM, 2026.

## License

A license has not yet been selected. Choose a license after deciding which parts of the project—such as firmware, hardware files, documentation, and research materials—you want others to reuse.
