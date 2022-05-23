# DIY Macropad

![DIY Macropad Image](https://i.imgur.com/39OGKpb.jpg)

_A short description of the keyboard/project_

- Keyboard Maintainer: [polyhedra-hub](https://github.com/yourusername)
- Hardware Supported: _The PCBs, controllers supported_
- Hardware Availability: _Links to where you can find this hardware_

Make example for this keyboard (after setting up your build environment):

    make diymacropad:default

Flashing example for this keyboard:

    make diymacropad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

When importing this folder into qmk_firmware repo make sure that the folder name is diymacropad.

## For Windows Users

Making and compiling your QMK code can be done with the [QMK MSYS](https://msys.qmk.fm/) CLI.

the steps for making the new repository are:

```
qmk setup
qmk new-keyboard
qmk compile -kb <keyboard> -km default
```

For flashing the keyboard I suggest using [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases), as it downloads all the necessary drivers.

You just need to go to

> Tools

> Install Drivers

Restart your machine before proceeding to the next step

Select the correct MCU in the upper right corner window. For Arduino Pro Micro it is atmel32u4.

After that you need to

> upload the hex file

> restart the keyboard via pin

> click flash.

Please check your antivirus and open the program in admin mode if you have any problems flashing your hex file.

Cheers and
Happy hacking :feelsgood:
