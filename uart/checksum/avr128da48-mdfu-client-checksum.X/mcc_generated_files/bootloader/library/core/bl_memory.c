/**
 * © 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms
 * applicable to your use of third party software (including open
 * source software) that may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 * MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL,
 * PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE
 * OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED,
 * EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE
 * DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW,
 * MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO
 * THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU
 * HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 *  @file    bl_memory.h
 *  @ingroup bl_memory Memory Helper
 *  @brief   This file contains implementation for the helper functions used with the NVM peripheral driver
 */
#include "bl_memory.h"

#if defined (BL_EEPROM_READ_ENABLED)
/**@misradeviation{@advisory, 17.8} - The parameter is passed to this wrapper API to decrement and
 * write or erase bytes/words from consecutive memory locations until its value is zero. 
 * Assigning the value to a different local variable for each API will increase redundancy.
 */
/**@misradeviation{@advisory, 8.9} - The static buffer should not be declared at local scope
 * due to portability concerns between various architectures.
 */

bl_mem_result_t BL_EEPROMRead(eeprom_address_t address, eeprom_data_t * buffer, size_t length)
{

    bl_mem_result_t result = BL_MEM_FAIL;
#if defined(DIAG_AVR_Dx_DEVICE) 
    NVM_StatusClear();
#endif
    if (buffer == NULL) //Check the valid buffer
    {
        result = BL_MEM_INVALID_ARG;
    }
    else if ((length <= (size_t) 0) || ((address + length) > (EEPROM_END + 1))) //Check valid length
    {
        result = BL_MEM_INVALID_ARG;
    }
    else if ((address < EEPROM_START) || (address > (EEPROM_START + EEPROM_SIZE))) //Check invalid address
    {
        result = BL_MEM_INVALID_ARG;
    }
    else
    {
        for (uint16_t index = 0; index <= length; index++)
        {
            buffer[index] = EEPROM_Read(address);
            /* cppcheck-suppress misra-c2012-17.8 */
            address++;
            while (EEPROM_IsBusy())
            {

            }
            if (NVM_OK == NVM_StatusGet())
            {
                result = BL_MEM_PASS;
            }
            else
            {
                result = BL_MEM_FAIL;
                break;
            }
        }
    }
    return result;
}
#endif

#if defined (BL_EEPROM_WRITE_ENABLED)
bl_mem_result_t BL_EEPROMWrite(eeprom_address_t address, eeprom_data_t * buffer, size_t length)
{
    bl_mem_result_t result = BL_MEM_FAIL;
#if defined(DIAG_AVR_Dx_DEVICE)
    NVM_StatusClear();
#endif

    if (buffer == NULL) //Check the valid buffer
    {
        result = BL_MEM_INVALID_ARG;
    }
    else if ((length <= (size_t) 0) || ((address + length) > (EEPROM_END + 1))) //Check valid length
    {
        result = BL_MEM_INVALID_ARG;
    }
    else if ((address < EEPROM_START) || (address > (EEPROM_START + EEPROM_SIZE))) //Check valid address
    {
        result = BL_MEM_INVALID_ARG;
    }
    else
    {
        for (uint16_t index = 0; index <= length; index++)
        {
            EEPROM_Write(address, buffer[index]);
            /* cppcheck-suppress misra-c2012-17.8 */
            address++;
            while (EEPROM_IsBusy())
            {

            }
            if (NVM_OK == NVM_StatusGet())
            {
                result = BL_MEM_PASS;
            }
            else
            {
                result = BL_MEM_FAIL;
                break;
            }
        }
    }
    return result;
}
#endif

bl_mem_result_t BL_FlashRead(flash_address_t address, flash_data_t * buffer, size_t length)
{

    bl_mem_result_t result = BL_MEM_FAIL;
    if (buffer == NULL) //Check the valid buffer
    {
        result = BL_MEM_INVALID_ARG;
    }

    else if ((length <= (size_t) 0) || ((address + length) > (PROGMEM_SIZE + 1))) //Check valid length
    {
        result = BL_MEM_INVALID_ARG;
    }

    else if ((address < (flash_address_t) 0x00) || (address > PROGMEM_SIZE)) //Check valid address
    {
        result = BL_MEM_INVALID_ARG;
    }
    else
    {

#if defined(DIAG_AVR_Dx_DEVICE)
        NVM_StatusClear();
#endif
        for (uint16_t index = 0; index <= length; index++)
        {
            buffer[index] = FLASH_Read(address);
            /* cppcheck-suppress misra-c2012-17.8 */
            address++;
            while (FLASH_IsBusy())
            {

            }
            if (NVM_OK == NVM_StatusGet())
            {
                result = BL_MEM_PASS;
            } 
            else
            {
                result = BL_MEM_FAIL;
                break;
            }
        }
    }
    return result;
}

// Static Buffer Declared to Assist in writing blocks of any length upto 1 page
/* cppcheck-suppress misra-c2012-8.9 */
static flash_data_t writeBuffer[PROGMEM_PAGE_SIZE];

bl_mem_result_t BL_FlashWrite(flash_address_t address, flash_data_t * buffer, size_t length)
{
    bl_mem_result_t result = BL_MEM_FAIL;
    uint16_t offset;
    uint16_t index;
    uint16_t counter = 0;
    flash_address_t pageStartAddress;

    if (buffer == NULL) //Check the valid buffer
    {
        result = BL_MEM_INVALID_ARG;
    }

    else if ((length <= (size_t) 0) || ((address + length) > (PROGMEM_SIZE + 1))) //Check valid length
    {
        result = BL_MEM_INVALID_ARG;
    }

    else if ((address < (flash_address_t) 0x00) || (address > PROGMEM_SIZE)) //Check valid address
    {
        result = BL_MEM_INVALID_ARG;
    }
    else
    {
#if defined(DIAG_AVR_Dx_DEVICE)
        NVM_StatusClear();
#endif

        if (length < PROGMEM_PAGE_SIZE)
        {
            offset = FLASH_PageOffsetGet(address);
            pageStartAddress = FLASH_PageAddressGet(address);
            for (index = 0; index < PROGMEM_PAGE_SIZE; index++)
            {
                writeBuffer[index] = FLASH_Read(pageStartAddress);
                pageStartAddress++;
                while (FLASH_IsBusy())
                {

                }
                if (NVM_OK == NVM_StatusGet())
                {
                    result = BL_MEM_PASS;
                } 
                else
                {
                    result = BL_MEM_FAIL;
                    break;
                }
            }
            if (result != BL_MEM_FAIL)
            {
                //Append buffer elements at/from offset to the read page buffer
                while (length != (size_t) 0)
                {
                    writeBuffer[offset] = buffer[counter];
                    offset++;
                    counter++;
                    /* cppcheck-suppress misra-c2012-17.8 */
                    length--;
                }
                pageStartAddress = FLASH_PageAddressGet(address); //Get start address of the page with the address


                result = (bl_mem_result_t) FLASH_PageErase(pageStartAddress);
                while (FLASH_IsBusy())
                {

                }
                if ((bl_mem_result_t) NVM_OK == result)
                {
                    //Write data to Flash row
                    result = (bl_mem_result_t) FLASH_RowWrite(pageStartAddress, writeBuffer);
                }

                if ((bl_mem_result_t) NVM_OK == result)
                {
                    result = BL_MEM_PASS;
                }
                else
                {
                    result = BL_MEM_FAIL;
                }
            }
        }
        if (length == PROGMEM_PAGE_SIZE)
        {
            pageStartAddress = FLASH_PageAddressGet(address);
            result = (bl_mem_result_t) FLASH_PageErase(pageStartAddress);
            while (FLASH_IsBusy())
                {

                }
            if ((bl_mem_result_t) NVM_OK == result)
            {
                //Write data to Flash row
                result = (bl_mem_result_t) FLASH_RowWrite(pageStartAddress, buffer);
            }
            else
            {
                result = BL_MEM_FAIL;
            }


            if ((bl_mem_result_t) NVM_OK == result)
            {
                result = BL_MEM_PASS;
            }
            else
            {
                result = BL_MEM_FAIL;
            }
        }
    }
    return result;
}

