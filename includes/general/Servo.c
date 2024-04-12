/**********************************************************************************************************************
 * \file GTM_TOM_Interrupt.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxPort.h"
#include "IfxGtm_Tom_Timer.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define ISR_PRIORITY_TOM    1                       /* Interrupt priority number                                    */
#define TOM_FREQ            100000.0f                    /* TOM frequency                                                */
#define LED                 &MODULE_P00, 5          /* LED which will be toggled in Interrupt Service Routine (ISR) */
//#define LED2                &MODULE_P00, 4

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxGtm_Tom_Timer g_timerDriver;                     /* TOM driver                                                   */
uint32 g_on_time_1 = 200;
uint32 g_on_time_2 = 200;

/*********************************************************************************************************************/
/*--------------------------------------------Function Implementations-----------------------------------------------*/
/*********************************************************************************************************************/
/* Macro to define the Interrupt Service Routine. */
IFX_INTERRUPT(interruptGtmTom, 0, ISR_PRIORITY_TOM);

/* Interrupt Service Routine of the TOM */
void interruptGtmTom(void)
{
    static uint32 counter = 0;
    IfxGtm_Tom_Timer_acknowledgeTimerIrq(&g_timerDriver);                       /* Clear the timer event            */
    if (counter == 0) {
        IfxPort_setPinHigh(LED);
//        IfxPort_setPinHigh(LED2);
    }
    if (counter == g_on_time_1) {
        IfxPort_setPinLow(LED);
    }
//    if (counter == g_on_time_2) {
//        IfxPort_setPinLow(LED2);
//    }

    if (counter >= (uint32)2000 - 1) {
        counter = 0;
    } else {
        counter++;
    }
}

/* This function initializes the TOM */
void initGtmTom(void)
{

    IfxGtm_Tom_Timer_Config timerConfig;                                        /* Timer configuration              */
    IfxGtm_Tom_Timer_initConfig(&timerConfig, &MODULE_GTM);                     /* Initialize timer configuration   */

    timerConfig.base.frequency       = TOM_FREQ;                                /* Set timer frequency              */
    timerConfig.base.isrPriority     = ISR_PRIORITY_TOM;                        /* Set interrupt priority           */
    timerConfig.base.isrProvider     = IfxSrc_Tos_cpu0;                         /* Set interrupt provider           */
    timerConfig.tom                  = IfxGtm_Tom_1;                            /* Define the timer used            */
    timerConfig.timerChannel         = IfxGtm_Tom_Ch_0;                         /* Define the channel used          */
    timerConfig.clock                = IfxGtm_Tom_Ch_ClkSrc_cmuFxclk3;          /* Define the CMU clock used        */
    IfxGtm_Tom_Timer_init(&g_timerDriver, &timerConfig);                        /* Initialize the TOM               */

    IfxPort_setPinModeOutput(LED, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);  /* Set pin mode         */
//    IfxPort_setPinModeOutput(LED2, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxGtm_Tom_Timer_run(&g_timerDriver); /* Start the TOM */
}

void setOnTime1(uint32 n) {
    g_on_time_1 = n;
}

uint32 getOnTime1(void) {
    return g_on_time_1;
}

void setOnTime2(uint32 n) {
    g_on_time_2 = n;
}

uint32 getOnTime2(void) {
    return g_on_time_2;
}
