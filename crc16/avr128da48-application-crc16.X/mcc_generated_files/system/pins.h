/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.1.0
*/

/*
� [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set BTN aliases
#define BTN_SetHigh() do { PORTC_OUTSET = 0x80; } while(0)
#define BTN_SetLow() do { PORTC_OUTCLR = 0x80; } while(0)
#define BTN_Toggle() do { PORTC_OUTTGL = 0x80; } while(0)
#define BTN_GetValue() (VPORTC.IN & (0x1 << 7))
#define BTN_SetDigitalInput() do { PORTC_DIRCLR = 0x80; } while(0)
#define BTN_SetDigitalOutput() do { PORTC_DIRSET = 0x80; } while(0)
#define BTN_SetPullUp() do { PORTC_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define BTN_ResetPullUp() do { PORTC_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define BTN_SetInverted() do { PORTC_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define BTN_ResetInverted() do { PORTC_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define BTN_DisableInterruptOnChange() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define BTN_EnableInterruptForBothEdges() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define BTN_EnableInterruptForRisingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define BTN_EnableInterruptForFallingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define BTN_DisableDigitalInputBuffer() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define BTN_EnableInterruptForLowLevelSensing() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC7_SetInterruptHandler BTN_SetInterruptHandler

//get/set LED aliases
#define LED_SetHigh() do { PORTC_OUTSET = 0x40; } while(0)
#define LED_SetLow() do { PORTC_OUTCLR = 0x40; } while(0)
#define LED_Toggle() do { PORTC_OUTTGL = 0x40; } while(0)
#define LED_GetValue() (VPORTC.IN & (0x1 << 6))
#define LED_SetDigitalInput() do { PORTC_DIRCLR = 0x40; } while(0)
#define LED_SetDigitalOutput() do { PORTC_DIRSET = 0x40; } while(0)
#define LED_SetPullUp() do { PORTC_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LED_ResetPullUp() do { PORTC_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LED_SetInverted() do { PORTC_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define LED_ResetInverted() do { PORTC_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LED_DisableInterruptOnChange() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LED_EnableInterruptForBothEdges() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LED_EnableInterruptForRisingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LED_EnableInterruptForFallingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LED_DisableDigitalInputBuffer() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LED_EnableInterruptForLowLevelSensing() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)
#define PC6_SetInterruptHandler LED_SetInterruptHandler

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for BTN pin. 
 *        This is a predefined interrupt handler to be used together with the BTN_SetInterruptHandler() method.
 *        This handler is called every time the BTN ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void BTN_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for BTN pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for BTN at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void BTN_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for LED pin. 
 *        This is a predefined interrupt handler to be used together with the LED_SetInterruptHandler() method.
 *        This handler is called every time the LED ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void LED_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for LED pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for LED at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void LED_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */
