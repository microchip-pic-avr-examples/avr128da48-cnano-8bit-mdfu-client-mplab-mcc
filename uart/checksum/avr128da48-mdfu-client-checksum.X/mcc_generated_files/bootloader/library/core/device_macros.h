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
 * @file    device_macros.h
 * @defgroup device_macros Device Macros
 * @brief   This file contains user-defined device macros and macro groups for the MDFU client library.
 *
 */

//User-defined device macros
// AVR DA Family:

//For all AVR32DAxx devices
#if defined (__AVR_AVR32DA28__) || defined (__AVR_AVR32DA32__) || defined (__AVR_AVR32DA48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR32DAxx_DEVICE
#endif

//For all AVR64DAxx devices
#if defined (__AVR_AVR64DA28__) || defined (__AVR_AVR64DA32__) || defined (__AVR_AVR64DA48__) || defined (__AVR_AVR64DA64__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64DAxx_DEVICE
#endif

//For all AVR128DAxx devices
#if defined (__AVR_AVR128DA28__) || defined (__AVR_AVR128DA32__) || defined (__AVR_AVR128DA48__) || defined (__AVR_AVR128DA64__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR128DAxx_DEVICE
#endif

//For all AVR DA Family devices
#if defined (DIAG_AVR32DAxx_DEVICE) || defined (DIAG_AVR64DAxx_DEVICE) || defined (DIAG_AVR128DAxx_DEVICE)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR_DA_DEVICE
#endif


//AVR DB Family:

//For all AVR32DBxx devices
#if defined (__AVR_AVR32DB28__) || defined (__AVR_AVR32DB32__) || defined (__AVR_AVR32DB48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR32DBxx_DEVICE
#endif

//For all AVR64DBxx devices
#if defined (__AVR_AVR64DB28__) || defined (__AVR_AVR64DB32__) || defined (__AVR_AVR64DB48__) || defined (__AVR_AVR64DB64__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64DBxx_DEVICE
#endif

//For all AVR128DBxx devices
#if defined (__AVR_AVR128DB28__) || defined (__AVR_AVR128DB32__) || defined (__AVR_AVR128DB48__) || defined (__AVR_AVR128DB64__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR128DBxx_DEVICE
#endif

//For all AVR DB Family devices
#if defined (DIAG_AVR32DBxx_DEVICE) || defined (DIAG_AVR64DBxx_DEVICE) || defined (DIAG_AVR128DBxx_DEVICE)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR_DB_DEVICE
#endif

//AVR DD Family:

//For all AVR16DDxx devices
#if defined (__AVR_AVR16DD14__) || defined (__AVR_AVR16DD20__) || defined (__AVR_AVR16DD28__) || defined (__AVR_AVR16DD32__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR16DDxx_DEVICE
#endif

//For all AVR32DDxx devices
#if defined (__AVR_AVR32DD14__) || defined (__AVR_AVR32DD20__) || defined (__AVR_AVR32DD28__) || defined (__AVR_AVR32DD32__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR32DDxx_DEVICE
#endif

//For all AVR64DDxx devices
#if defined (__AVR_AVR64DD14__) || defined (__AVR_AVR64DD20__) || defined (__AVR_AVR64DD28__) || defined (__AVR_AVR64DD32__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64DDxx_DEVICE
#endif

//For all AVR DD Family devices
#if defined (DIAG_AVR64DDxx_DEVICE) || defined (DIAG_AVR32DDxx_DEVICE) || defined (DIAG_AVR16DDxx_DEVICE)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR_DD_DEVICE
#endif

//AVR EA Family
#if defined (__AVR_AVR64EA28__) || defined (__AVR_AVR64EA32__) || defined (__AVR_AVR64EA48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64EAxx_DEVICE
#endif

#if defined (__AVR_AVR32EA28__) || defined (__AVR_AVR32EA32__) || defined (__AVR_AVR32EA48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64EAxx_DEVICE
#endif

#if defined (__AVR_AVR16EA28__) || defined (__AVR_AVR16EA32__) || defined (__AVR_AVR16EA48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64EAxx_DEVICE
#endif

//For all AVR EA Family devices
#if defined (DIAG_AVR64EAxx_DEVICE) || defined (DIAG_AVR32EAxx_DEVICE) || defined (DIAG_AVR16EAxx_DEVICE)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR_EA_DEVICE
#endif

//AVR EB Family
#if defined (__AVR_AVR64EB28__) || defined (__AVR_AVR64EB32__) || defined (__AVR_AVR64EB48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64EBxx_DEVICE
#endif

#if defined (__AVR_AVR32EB28__) || defined (__AVR_AVR32EB32__) || defined (__AVR_AVR32EB48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64EBxx_DEVICE
#endif

#if defined (__AVR_AVR16EB28__) || defined (__AVR_AVR16EB32__) || defined (__AVR_AVR16EB48__)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR64EBxx_DEVICE
#endif

//For all AVR EB Family devices
#if defined (DIAG_AVR64EBxx_DEVICE) || defined (DIAG_AVR32EBxx_DEVICE) || defined (DIAG_AVR16EBxx_DEVICE)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR_EB_DEVICE
#endif

//For all defined AVR Dx devices
#if defined (DIAG_AVR_DA_DEVICE) || defined (DIAG_AVR_DB_DEVICE) || defined (DIAG_AVR_DD_DEVICE) || defined (DIAG_AVR_EB_DEVICE) || defined (DIAG_AVR_EA_DEVICE)
/* cppcheck-suppress misra-c2012-2.5 */
#define DIAG_AVR_Dx_DEVICE
#endif