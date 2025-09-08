# Immensive Bootloader

This repository is a CDC/DFU/UF2 bootloader for Immensive boards based on a Nordic nRF52 microcontroller.

It is a fork from [adafruit/Adafruit_nRF52_Bootloader](https://github.com/adafruit/Adafruit_nRF52_Bootloader) repository. This original documentation is available [here](./README_ORIGINAL.md).

Altough, the bootloader can be built from scratch, it also contains pre-compiled libraries in the `./bin/` directory. 

## Cloning this repository

Firstly clone this repo including its submodules with following command:

```
git clone --recurse-submodules https://github.com/gaetanmarti/Immensive_nRF52_Bootloader.git
```

For git versions before `2.13.0` you have to do that manually:
```
git clone https://github.com/gaetanmarti/Immensive_nRF52_Bootloader.git
cd Immensive_nRF52_Bootloader
git submodule update --init
```

## Prerequisites

In order to compile and upload the Firmware, you need to:

- Have [Docker](https://www.docker.com) installed and operationnal on your machine for the ARM GCC compiler.

## Compilation from scratch

In order to compile the bootloader, you need to perform the following operations:

1. [Clone this repository](#cloning-this-repository).

2. Build the container for the compiler:
    ```sh
    docker build -t arm-bootloader-compiler .       
    ```

3. Run the container:
    ```sh
    docker run -it -v "$(pwd):/opt/project/armgcc" arm-bootloader-compiler
    ```

4. It will open the bash command-line of the container like:
    ```sh
    root@5ff18c1c753b:/opt/project/armgcc#       
    ```

5. Compile the bootloader with:
    ```sh
    make BOARD=immensive_nrf52840 all
    ```
    See also chapter [Configuration Flags](#configuration-flags) .

6. It will compile the bootloader. You can find the `.hex` artifact in `./_build/build-immensive/immensive_nrf52840_bootloader-***GIT_TAG***_s140_6.1.1.hex`. Beware, there are several `.hex`files generated during the make process.

7. *[OPTIONNAL]* Erase the Eprom with J-Link.

8. *[OPTIONNAL]* Deconnect / reconnect USB cable on the board.

9. You can now upload the bootloader with J-Link. 

### Configuration Flags

The following flags can be used to enable/disable features:

| Name | Description |
|------|-------------|
|`USE_MSC=1` | Enable Firmware updates via MSC (Mass Storage Class). This method opens a USB disk to update the bootloader. By defaut - for security reasons - this feature is deactivated (`USE_MSC=0`). |
|`DEBUG=1`| Enable to Debug the Bootloader with the SEEGER RTT Viewer App. **DO NOT USE BECAUSE THIS OPTION WILL PLACE THE BOOTLOADER AT THE EPROM ADDRESS OF THE LITTLEFS.**|


## Pre-compiled binaries

| Name | Description | Makefile Command |
|------|-------------|------------------|
| nrf52840_bootloader_all-0.1.1_s140_6.1.1.hex | Origial version of the bootloader firmware with SoftDevice S140 v6.1.1 | `make BOARD=immensive_nrf52840 USE_MSC=1 all` | 
| nrf52840_bootloader_no_MSC-0.1.1_s140_6.1.1.hex | Original version without MCS. **Use this version in production** |`make BOARD=immensive_nrf52840 USE_MSC=0 all`|

## Releases

| Version | Changes |
|---------|---------|
| `0.1.0` | Working with electronic with no USB mux |
| `0.1.1` | Working with electronic with USB mux. |

## Known limitations

!!! Warning With version `0.1.1`, USB cable will only work on one side.

## Flash memory map

| Start |   End   | Description |
|-------|---------|-------------|
|0x00000 | 0x00AFF | MBR |
|0x01000 | 0x25DE7 | Soft Device |
|0x26000 | 0x3D2BB | *Application** |
|0xED000 | 0xF3FFF | *LittleFS*** |
|0xF4000 | 0xFB13B | Bootloader |
|0xFD800 | 0xFD857 | Bootloader options |

*This memory will be filled by the Arduino IDE
**Will be formated at first usage of the Application

## External ressources

- Flash [memory map](https://learn.adafruit.com/bluefruit-nrf52-feather-learning-guide/hathach-memory-map).

GMA 2025-09-08