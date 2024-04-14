#ifndef INCLUDES_APPLICATION_PIN_MAP_H_
#define INCLUDES_APPLICATION_PIN_MAP_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxPort_PinMap.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PIN_BTN_AUTO_LOCK               IfxPort_P33_0
#define PIN_BTN_DOOR_OPCL               IfxPort_P11_10
#define PIN_BTN_KIDS_LOCK               IfxPort_P33_3
#define PIN_BTN_EMERGENCY_STOP          IfxPort_P11_3

#define PIN_FOOT_DETECTOR_TRIG          IfxPort_P00_0
#define PIN_FOOT_DETECTOR_ECHO          IfxPort_P00_1

#define PIN_OBSTACLE_DETECTOR_TRIG      IfxPort_P00_3
#define PIN_OBSTACLE_DETECTOR_ECHO      IfxPort_P00_4

#define PIN_DOOR_CTRL                   IfxPort_P00_5
#define PIN_LOCK_CTRL                   IfxPort_P00_6

#define PIN_LED_RED                     IfxPort_P10_4
#define PIN_LED_GREEN                   IfxPort_P02_1
#define PIN_LED_BLUE                    IfxPort_P02_0

#define PIN_AUDIO                                           // PWM10    PWMH3   P10_5

#define PIN_LED                         IfxPort_P10_2

#define INPUT_MODE              IfxPort_Mode_inputPullDown
#define OUTPUT_MODE             IfxPort_Mode_outputPushPullGeneral

#define HIGH                    IfxPort_State_high
#define LOW                     IfxPort_State_low

#define PIN_MODE(pin, mode)     IfxPort_setPinMode(pin.port, pin.pinIndex, mode)
#define SET_PIN(pin, state)     IfxPort_setPinState(pin.port, pin.pinIndex, state)
#define GET_PIN(pin)            IfxPort_getPinState(pin.port, pin.pinIndex)
#define TOGGLE_PIN(pin)         IfxPort_togglePin(pin.port, pin.pinIndex)
#define CMP_PINS(pin1, pin2)    (((pin1.port) == (pin2.port) && (pin1.pinIndex == pin2.pinIndex)))

#endif /* INCLUDES_APPLICATION_PIN_MAP_H_ */
