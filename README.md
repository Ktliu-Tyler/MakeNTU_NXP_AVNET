# MakeNTU Robot Face and Control Interface

An embedded interface project combining an animated robot face with touch interactions and hardware-control hooks. Built around NXP GUI Guider and LVGL, it explores how a small device can communicate its state through expressions and provide controls on the same display.

## What the interface contains

- Face and state screens including Normal, Thinking, Sleep, Speaking, Music, and Focus.
- A startup screen, weather-themed screen, and control panel.
- Eye and mouth animations, touch responses, and gesture-based screen changes.
- Custom panel behavior that formats fan-speed commands for UART output.
- Pitch/yaw servo-control functions and UART monitor infrastructure.

## Design approach

GUI Guider project files describe the visual design, while generated C files define screens and events. Custom C modules extend those generated components with device-specific behavior. The project includes desktop simulation support and embedded SDK/build assets, allowing the interface work and hardware integration work to be kept together.

The weather and speaking screens represent interface states; their presence alone does not mean the repository includes a weather service or speech-generation system.

## Repository guide

| Path | Purpose |
| --- | --- |
| [MakeNTU_FACE.guiguider](MakeNTU_FACE.guiguider) | Editable GUI Guider design |
| [generated](generated) | Generated screens, widgets, assets, and event handlers |
| [custom/custom.c](custom/custom.c) | Custom interface behavior and UART command formatting |
| [custom/servo.c](custom/servo.c), [custom/servo.h](custom/servo.h) | Servo-control implementation and interface |
| [custom/Monitor.c](custom/Monitor.c) | UART monitor infrastructure |
| [lvgl-simulator](lvgl-simulator) | Desktop simulation components |
| [sdk](sdk) | Embedded SDK and build support |

## Project context

This repository captures the robot-face/control-panel portion of the MakeNTU work. The related [MAKENTU_robotFace](https://github.com/Ktliu-Tyler/MAKENTU_robotFace) repository preserves a broader workspace with GUI experiments and MCXN947 board tests.

Generated and bundled vendor components retain their own notices. The repository includes an [NXP software license](LICENSE.txt); this overview does not replace those terms.
