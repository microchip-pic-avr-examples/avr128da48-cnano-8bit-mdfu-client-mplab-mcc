[![MCHP](../images/microchip.png)](https://www.microchip.com)

# 8-Bit MDFU Client Setup for SPI Communication

[Go Back](../README.md)

## Required Hardware
- [Curiosity Nano Base for Click boards™](https://www.microchip.com/en-us/development-tool/AC164162)
- [MCP2210 Breakout Module](https://www.microchip.com/en-us/development-tool/ADM00419)
- Five female-to-female jumper wires

## Hardware Configuration
[![MDFU_SPI_HW](../images/HardwareSetup_SPI.png)](../images/HardwareSetup_SPI.png)

## 8-Bit MDFU Client SPI Communication

- Communication Protocol: SPI
- Application Start Address (Set through Configuration Bits UI): 0x3000
- Device ID: 0x1E9708 (automatically added)
- I/O Pin Indicator: Enabled
- I/O Pin Entry: Enabled
- Memory Verification: CRC32

[![MDFU](../images/MDFUClientSetup_SPI.PNG)](../images/MDFUClientSetup_SPI.PNG)

**SPI**
- Custom Name: SERCOM
- BOOT_CONFIG: Mode 0
- Interrupt Driven: Disabled

[![SPI](../images/SPIDriverSetup.PNG)](../images/SPIDriverSetup.PNG)

**SPI0 PLIB**
- Description: Refer to Abstract Driver for User Configurations

[![SPI_PLIB](../images/SPIPLIBSetup.PNG)](../images/SPIPLIBSetup.PNG)

**SPI Pins**
- MSSP SCK: RA6
- MSSP SDI (MOSI): RA4
- MSSP SDO (MISO): RA5
- MSSP SS (Chip Select): RA7
    - Custom Name: CHIP_SELECT

[![SPI_Pins](../images/SPIPortsSetup.PNG)](../images/SPIPortsSetup.PNG)

**8-Bit MDFU Client I/O**
- BOOT INDICATE: RC6
- BOOT ENTRY: RC7

[![IO-Pins](../images/IOPortSetup.PNG)](../images/IOPortSetup.PNG)

- BOOT INDICATE: Start High
- BOOT ENTRY: Weak Pullup

[![IO-Settings](../images/IOPinsSetup.PNG)](../images/IOPinsSetup.PNG)

**8-Bit MDFU Client Project Properties**

Set the linker options to restrict the bootloader compilation to the BOOT partition.
This step is different depending on the used compiler.

*AVR-GCC:*

- When using the AVR-GCC compiler, open the Project Properties window and apply the below settings where `<Application Start Address>` is the start address of the application.
 ```
  avr-ld>Additional options>-Wl,--defsym,__TEXT_REGION_LENGTH__=<Application Start Address>
 ```

*XC8:*

- When using the XC8 compiler, open the Project Properties window and apply the below settings where `<Application Start Address>` is the start address of the application.
 ```
   XC8 Linker>Additional options>Extra Linker Options>-Wl,--defsym,__TEXT_REGION_LENGTH__=<Application Start Address>
 ```

Replace the `<Application Start Address>` to the Application Start Address value as configured in the MDFU Client UI.

[![IO-Settings](../images/LinkerSettings_SPI.PNG)](../images/LinkerSettings_SPI.PNG)

### Application Setup
Refer to the [Application Setup](../README.md#application-setup) section in the main Readme file.

## Operation
This example shows how to execute the CRC32 verification example and update the device Flash memory with the CRC32 application image to demonstrate a successful device firmware update (DFU) over the SPI communication protocol.

**8-Bit MDFU Client Operation**

1. Open the MDFU client project.

[![OpenMDFU](../images/openBtnMDFU.png)](../images/openBtnMDFU.png)

[![OpenMDFUProject](../images/openProjectMDFU_SPI.PNG)](../images/openProjectMDFU_SPI.PNG)

2. Set MDFU client project as Main Project.

[![SetAsMainMDFUProject](../images/setAsMainProject_SPI.PNG)](../images/setAsMainProject_SPI.PNG)

3. Right click, then select Clean and Build.

[![CleanBuild](../images/CleanAndBuildMDFU_SPI.PNG)](../images/CleanAndBuildMDFU_SPI.PNG)

4. Program the MDFU client project.

[![ProgramMDFU](../images/ProgramMDFU_SPI.png)](../images/ProgramMDFU_SPI.png)

**Bootloader Operation after initial programming**

After initial programming, the LED must be on.

[![MDFU_BootMode](../images/AVR128DA48_BootMode_SPI.png)](../images/AVR128DA48_BootMode_SPI.png)

**Application Operation**
1. Open the Application Project that is configured for your selected verification scheme.

[![OpenApp](../images/openBtnApp_SPI.PNG)](../images/openBtnApp_SPI.PNG)

[![OpenAppProject](../images/openProjectApp_SPI.PNG)](../images/openProjectApp_SPI.PNG)

2. Set the application project as the Main Project.

[![MainAppProject](../images/setAppAsMainProject_SPI.PNG)](../images/setAppAsMainProject_SPI.PNG)

3. Build the required application project.

- Navigate to the Building tab of the application Project Properties and enable the "Execute this line after build" checkbox

[![EnablePostBuild_App](../images/EnablePostBuildApp_SPI.PNG)](../images/EnablePostBuildApp_SPI.PNG)

- Right click the project name, then select Clean and Build

[![CleanBuild_App](../images/CleanAndBuildApp_SPI.PNG)](../images/CleanAndBuildApp_SPI.PNG)

4. Build the Application Image File using [pyfwimagebuilder](https://pypi.org/project/pyfwimagebuilder/).

- To build the application image files, navigate to the Project tab and right click on *Important Files>`build_free_image.bat`* for Windows or *Important Files>`build_free_image.sh`* for Mac and Linux
- Select Run

[![Run_BuildScript](../images/RunBuildScript_SPI.PNG)](../images/RunBuildScript_SPI.PNG)

**Example Command:**

Below is an example of the command used in the above step.

`pyfwimagebuilder build -i "application_hex_file.hex"  -c "mdfu_config_file.toml" -o output.img`

[![build_img](../images/BuildTheImage_SPI.PNG)](../images/BuildTheImage_SPI.PNG)

> **Tip**: The configuration TOML file is generated by the MDFU Client project.

[![FindTheTOML_BL](../images/ConfigPathExample_SPI.PNG)](../images/ConfigPathExample_SPI.PNG)

5. Use the [pymdfu](https://pypi.org/project/pymdfu/) host tool to transfer the application image file to the bootloader.

- To run the update with the examples, navigate to the Project tab and right click, *Important Files>`pymdfu_update.bat`* for Windows or *Important Files>`pymdfu_update.sh`* for Mac and Linux. Double click to open the file.
- Edit the chip select number to the proper GPIO you have set on your MCP2210 Breakout Module
- Then right click on the script and select Run

[![UpdateScript_BL](../images/runUpdateScript_SPI.PNG)](../images/runUpdateScript_SPI.PNG)

**Example Command:**

Below is an example of the command used in the above step.

`pymdfu update --tool mcp2210 --image ./output.img --chip-select 7 --clk-speed 50000`

[![transfer_img](../images/SendTheImage_SPI.PNG)](../images/SendTheImage_SPI.PNG)

**Application Has Been Updated Successfully**

[![MDFU_AppMode](../images/AVR128DA48_AppMode_SPI.gif)](../images/AVR128DA48_AppMode_SPI.gif)

[Back to top](#8-bit-mdfu-client-setup-for-spi-communication)