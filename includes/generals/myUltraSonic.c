/**********************************************************************************************************************
 * \file myUltraSonic.c
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
#include "myUltrasonic.h"

#include "IfxPort.h"
#include "IfxCpu.h"
#include "IfxStm.h"

#include "myDelay.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

Ultra_struct g_ultra[2];

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
uint32 pulseIn(IfxPort_Pin pin, uint8 state, uint32 timeout);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void initUltraSonic(int num, IfxPort_Pin trig, IfxPort_Pin echo)
{
    g_ultra[num].trig = trig;
    g_ultra[num].echo = echo;
    IfxPort_setPinModeOutput(g_ultra[num].trig.port, g_ultra[num].trig.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeInput(g_ultra[num].echo.port, g_ultra[num].echo.pinIndex, IfxPort_InputMode_pullUp);
//    g_pinTrigger = trig;
//    g_pinEcho    = echo;
//    IfxPort_setPinModeOutput(g_pinTrigger.port, g_pinTrigger.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
//    IfxPort_setPinModeInput(g_pinEcho.port, g_pinEcho.pinIndex, IfxPort_InputMode_pullUp);
}

float32 getUltraSonicDistance(uint8 num))
{

    IfxPort_setPinLow(g_ultra[num].trig.port, g_ultra[num].trig.pinIndex);
    delayUs(2);
    IfxPort_setPinHigh(g_ultra[num].trig.port, g_ultra[num].trig.pinIndex);
    delayUs(10);
    IfxPort_setPinLow(g_ultra[num].trig.port, g_ultra[num].trig.pinIndex);

    boolean interruptState = IfxCpu_disableInterrupts();

    uint32 micros = pulseIn(g_ultra[num].echo, 1, 23529);

    IfxCpu_restoreInterrupts(interruptState);

    return (float32)micros / 58.8235f;
}

uint32 pulseIn(IfxPort_Pin pin, uint8 state, uint32 timeout)
{
    uint32 startMicros = getCurMicros();

    // wait for any previous pulse to end
    while (__getbit(&pin.port->IN.U, pin.pinIndex) == state)
    {
        if (getCurMicros() - startMicros >= timeout)
        {
            return 0;
        }
    }

    // wait for the pulse to start
    while (__getbit(&pin.port->IN.U, pin.pinIndex) != state)
    {
        if (getCurMicros() - startMicros >= timeout)
        {
            return 0;
        }
    }

    // wait for the pulse to stop
    uint32 estimationStart = getCurMicros();
    while (__getbit(&pin.port->IN.U, pin.pinIndex) == state)
    {
        if (getCurMicros() - startMicros >= timeout)
        {
            return 0;
        }
    }
    uint32 estimationEnd = getCurMicros();

    return estimationEnd - estimationStart;
}