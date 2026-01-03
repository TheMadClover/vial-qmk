# Unibroom Sweepy2

![Unibroom Sweepy2](/keyboards/handwired/themadclover/clover_unibroom_sweepy2/images/image_1.jpg)
![Sweepy2 OSM Keymap](/keyboards/handwired/themadclover/clover_unibroom_sweepy2/images/my_keymap.png)
*Keymap*

*A Vial enabled handwired mechanical keyboard.*

* Keyboard Maintainer: [TheMadClover](https://github.com/TheMadClover)
* Hardware Supported: *RP2040 Zero Supermini*
* Hardware Availability: *[RP2040 Zero Supermini-Aliexpress](https://share.google/7UdnPk3eajyDnip1M)*

Compile example for this keyboard (after setting up your build environment):

    qmk compile -kb handwired/themadclover/clover_unibroom/sweepy2 -km vial

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard.

* **Boot key on controller**:  Hold down the "**BOOT**" button on the controller and plug in the keyboard.

* **Keycode in layout**: Use vial web UI to add bootloader key to key on the keymap, then depress that key.  This is handy if you don't want to disassemble the board to access the "**BOOT**" button on the microcontroller. 

## Mad Clover Firmware

The firmware in this, my personal fork of Vial QMK, is a variation on the work of Callum Oakley.  It makes use of Callum's timerless one-shot mods, and the bulk of the keymap/code matches that found in his [QMK fork and Userspace](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum).
