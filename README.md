# Immensive Bootloader

This repository is a CDC/DFU/UF2 bootloader for Immensive boards based on a Nordic nRF52 microcontroller.

It is a fork from [adafruit/Adafruit_nRF52_Bootloader](https://github.com/adafruit/Adafruit_nRF52_Bootloader) repository. This original documentation is available [here](./README_ORIGINAL.md).

Altough, the bootloader can be built from scratch, it also contains pre-compiled libraries in the `./bin/` directory. 

## Cloning this repository

Firstly clone this repo including its submodules with following command:

```
git clone --recurse-submodules https://github.com/adafruit/Adafruit_nRF52_Bootloader
```

For git versions before `2.13.0` you have to do that manually:
```
git clone https://github.com/adafruit/Adafruit_nRF52_Bootloader
cd Adafruit_nRF52_Bootloader
git submodule update --init
```

## Prerequisites

In order to compile and upload the Firmware, you need to:

- Have [Docker](https://www.docker.com) installed and operationnal on your machine for the ARM GCC compiler.

## Compilation from scratch

In order to compile the bootloader, you need to perform the following operations:

1. Retrieve the code of the repository with a `git clone https://github.com/gaetanmarti/Immensive_nRF52_Bootloader.git`.

2. Build the container for the compiler:
    ```sh
    docker build -t arm-bootloader-compiler .       
    ```

3. Run the container:
    ```sh
    docker run -it -v "$(pwd):/opt/project/armgcc" arm-bootloader-compiler
    ```

4. It will open the bash command-line of the container.
5. Compile the bootloader with:
    ```sh
    make BOARD=immensive_nrf52840 all
    make BOARD=sparkfun_nrf52840_micromod all
    ```
6. It will compile the bootloader (and further fail when trying to upload it). You can find it in `./_build/build-sparkfun_nrf52840_micromod/sparkfun_nrf52840_micromod_bootloader-0.9.2-29-g6a9a6a3-dirty_s140_6.1.1.hex`
7. You can now upload the bootloader with J-Link. 

## Create a DFU file

```sh
python3 uf2conv.py ./sparkfun_nrf52840_all_s140_6.1.1.hex -c -f 0xADA52840
```
## Pre-compiled binaries

| Name | Description |
|------|-------------|
| *sparkfun_nrf52840_all_s140_6.1.1.hex* | Origian version of the bootloader firmware for SparkFun nRF52840 with SoftDevice S140 v6.1.1 |
| *sparkfun_nrf52840_all_s140_6.1.1.uf2* | UF2 version of the previous firmware |
| **sparkfun_nrf52840_no_MSC_s140_6.1.1.hex** | Same as above but with deactivation of the MSC (Mass Storage Class) | 

### Diff of `no MSC` version

- tusb_config.h, line 56, `#define CFG_TUD_MSC 0`.
- usb.c, line 306, `usb_init(true);`

!!! Note Note this is the most stable version so far!

## Limitations of the current bootloader

- Firmware over the air (OTA) does not currently work with the BTLE stack stuck on `[GATTS ] attr's cccd = 0x0001`.
- Firmware may not allow to upload from Arduino depending on how it is stuck in the bluetooth stack. Use `reset` command on the serial debugger to restart the device in a mode that is not using Bluetooth.