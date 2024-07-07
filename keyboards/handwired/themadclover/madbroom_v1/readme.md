# MadBroom V1

![MadBroom V1](/keyboards/handwired/themadclover/madbroom_v1/images/madBroomV1_1.jpg)

A handwired keyboard designed drawing inspiration from the Ferris, designed by [Pierre Chavalier](https://github.com/pierrechevalier83/ferris).  Case design done by myself (ametuer hour here boys and girls...but I learned a lot).  Designed to use the RP2040 Zero, and direct wired (diodeless), this was a project that stretched my abilities in both CAD, and working with QMK and Vial.

* Keyboard Maintainer: [TheMadClover](https://github.com/TheMadClover)
* Hardware Supported: Handwired, RP2040 Zero
* Hardware Availability:  3D printed case, supplies sourced from both Amazon and AliExpress.

Make example for this keyboard (after setting up your build environment):

    make handwired/themadclover/madbroom:default

Flashing example for this keyboard:

    make handwired/themadclover/madbroom:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Press and hold **BOOT** and then press **RESET** on MCU.  Requires opening case.
* **Keycode in layout**: ~~Press the key mapped to `QK_BOOT` if it is available~~ Future version...maybe?
