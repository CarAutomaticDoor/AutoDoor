/**********************************************************************************************************************
 * \file Buttons.c
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
#include "Buttons.h"

#include "IfxPort.h"
#include "Pin_Map.h"
#include "Platform_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define NUM_BUTTON   2 // 현재는 키즈락 안쓴다고 가정해서 (2)로 설정. -> 키즈락을 쓰게된다면 (3)으로 변경.

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
boolean g_prev[NUM_BUTTON] = { TRUE, TRUE };

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void Init_Buttons(void) // 버튼으로 사용되는 디지털 핀을 입력으로 설정.
{
    // set door open/close button as input/inputPullUp
    IfxPort_setPinModeInput(PIN_BTN_AUTO_LOCK.port, PIN_BTN_AUTO_LOCK.pinIndex, IfxPort_Mode_inputPullUp);

    // set auto door lock button as input/inputPullUp
    IfxPort_setPinModeInput(PIN_BTN_DOOR_OPCL.port, PIN_BTN_DOOR_OPCL.pinIndex, IfxPort_Mode_inputPullUp);

    // 키즈락 기능은 우선 없는 걸로 생각. <- 주석처리.
    // set kids lock button as input/inputPullUp
//    IfxPort_setPinModeInput(PIN_BTN_KIDS_LOCK.port, PIN_BTN_KIDS_LOCK.pinIndex, IfxPort_Mode_inputPullUp);
}


boolean Get_Button_State(IfxPort_Pin pin_num)
{
    /*
         pin_num : 3가지(잠금, Open/Close, 키즈락) 중 읽고자하는 값의 입력핀 -> Pin_Map.h 에서 확인.
    */

    // pin_num에 따라 인덱스가 매핑 -> if ~ else로 구현

    uint8 idx = 0;
    if(CMP_PINS(pin_num, PIN_BTN_AUTO_LOCK)) {
        idx = 0;
    }
    else if(CMP_PINS(pin_num, PIN_BTN_DOOR_OPCL)) {
        idx = 1;
    }

    // 초기값 : OFF -> FALSE 를 리턴. 스위치가 눌리면 ON : TRUE 리턴.
    boolean temp_SW = IfxPort_getPinState(pin_num.port, pin_num.pinIndex); /*Close Btn(Switch) 값 읽어와 tempSW에 저장  */

    if(g_prev[idx] && !(temp_SW)){ // 스위치가 눌렸으면 temp_SW : 0
        return TRUE;
    }

    g_prev[idx] = temp_SW;
    return FALSE;
}