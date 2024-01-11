<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# Getting Started with the 8-Bit MDFU Client for AVR128DA48 (MPLAB X)

This repository provides the MPLAB® X projects needed to configure some basic MDFU bootloader solutions for the AVR128DA48 Curiosity Nano Evaluation Board using code generated from the MPLAB® Code Configurator (MCC).

The Microchip Device Firmware Update (MDFU) is a device firmware update ecosystem that uses a device agnostic host application to update the application firmware. The application image that is loaded into the host follows a custom file format that includes the device and application-specific parameters needed to perform the update. This repository provides the basic starting point to configure and customize the MCC Melody 8-Bit MDFU Client library on the AVR128DA48 Curiosity Nano development board and also provides instructions for running the examples.

## Related Documentation

- [AVR128DA48 Family Product Page](https://www.microchip.com/en-us/product/AVR128DA48)
- [8-Bit MDFU Client Getting Started](https://onlinedocs.microchip.com/oxy/GUID-67539092-2179-43C1-8600-118A85E49693-en-US-2/index.html)
- [8-Bit MDFU Client v1.0.0-beta.1 Release Note](https://onlinedocs.microchip.com/oxy/GUID-9CE46BA1-9CDF-4B9C-9C73-4793B27ED320-en-US-2/index.html)
- [8-Bit MDFU Client v1.0.0-beta.1 API Documentation](https://onlinedocs.microchip.com/oxy/GUID-01EC9542-92FF-436D-91FB-7CBEEE66D701-en-US-2/index.html)

## Software Used

- MPLAB® X IDE 6.15.0 [(MPLAB® X IDE 6.15)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic16f18446-cnano-8bit-mdfu-client-mplab-mcc-github)
- MPLAB® XC8 2.45.0 [(MPLAB® XC8 2.45)](https://www.microchip.com/en-us/development-tools-tools-and-software/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_MPAE_Examples&utm_content=pic16f18446-cnano-8bit-mdfu-client-mplab-mcc-github)
- MPLAB® Code Configurator (MCC) 5.4.1 [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- MPLAB® Code Configurator (MCC) Device Libraries AVR AND ATtiny MCUs [(microchip.com/mplab/mplab-code-configurator)](https://www.microchip.com/mplab/mplab-code-configurator)
- Python 3.8 or later [(Python)](https://www.python.org/downloads/)
- pyfwimagebuilder v1.0.1.14 [(pyfwimagebuilder)](https://pypi.org/project/pyfwimagebuilder/)
- pymdfu v1.0.1.5 [(pymdfu)](https://pypi.org/project/pymdfu/)

## Hardware Used

- AVR128DA48 Curiosity Nano [(DM164151)](https://www.microchip.com/en-us/development-tool/DM164151)

[![AVR128DA48_CNano](images\230928-mcu8-photo-dm164151-front-transparent.png)](images\230928-mcu8-photo-dm164151-front-transparent.png)

## Setup

The following project setup steps have been followed for each example project pair. If something goes wrong in running these examples, validate that the settings in your project are consistent with the options seen in this section.

### Client Setup
[![mdfu-builder](images\ProjectConfigurationOverview.PNG)](images\ProjectConfigurationOverview.PNG)

**Clock Control**
- Prescaler enable: **Disabled**
- Internal Oscillator Frequency: **20_MHz**

[![CLK](images\ClockSetup.PNG)](images\ClockSetup.PNG)

**Configuration Bits**

On Configuration Bits UI, configure the BOOT FUSE to an acceptable size.
For example, if the Program Flash Memory size is 0x20000, then the BOOT FUSE for an AVR device with a page size of 512 would need to be 254 (1 less than the MAX). This will initialize the bootloader partition to be in the address range from 0x00 to 0x1FC00. This will leave 1 page in the  CODE partition.

For AVR128DA48,
- BOOTSIZE: **254**

[![CFG](images\ConfigBitsSetup.PNG)](images\ConfigBitsSetup.PNG)

**NVM**
- Generate Flash APIs: **Enabled**
- Generate EEPROM APIs: **Enabled**
- Generate Signature Row APIs: **Enabled**

[![NVM](images\NVMSetup.PNG)](images\NVMSetup.PNG)



## Operation

<!-- Explain how to operate the example. Depending on complexity, step-by-step instructions and/or tables and/or images can be used -->

## Summary

<!-- Summarize what the example has shown -->
