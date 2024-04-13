/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Audio.h"

#include "Pwm.h"

#include "Platform_Types.h"
#include "IfxGtm_PinMap.h"
#include "Bsp.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define TOM_AUDIO   {IfxGtm_Tom_0, IfxGtm_Tom_Ch_15, IfxGtm_ToutSel_a, 7, {&MODULE_P02, 7}, IfxPort_OutputIdx_alt1}

#define WAIT_TIME 10

#define DANGER_SOUND 1
#define OPEN_CLOSE_SOUND 2
#define WELCOME_SOUND 3

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/

IfxGtm_Tom_ToutMap g_tom_audio = TOM_AUDIO;
Pwm g_audio;
uint8 g_hz_idx = 0;

/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
//soundDo(hz) {
//    Set_Duty_Cycle(&config);
//}

void Init_Audio(void) {
    // 초기값 세팅 필요
    uint16 period;
    uint16 duty_cycle;

    // 부저 2개 사용 -> 2개 Setting
    Init_Pwm(&g_audio, &g_tom_audio, period, duty_cycle); // 부저1 PWM pin 9 연결

    return;
}

void Make_Sound(uint32 idx) {
    float32 buzzer[2] = {261.686f, 500.262f};
    uint32 uPeriod = (uint32)(100000000/buzzer[idx]);

    Set_Duty_Period(&g_audio, uPeriod);
    Set_Duty_Ratio(&g_audio, 50);
}

void Play_Door_CloseOpen_Sound(void) {
    /* Initialize a time variable */
    Ifx_TickTime ticksFor10ms = IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME);

    Make_Sound(0);
    waitTime(ticksFor10ms * 100);
    Make_Sound(1);
    waitTime(ticksFor10ms * 100);
}

void Play_Danger_Sound(void) {
    // "삐~~~~" 출력은 주기에 관계없이 듀티비 100이기만 하면되기에 임의의 262.686Hz인가 시킴
    unsigned int uPeriod = (unsigned int)(100000000/262.686f);

    Set_Duty_Period(&g_audio, uPeriod);
    Set_Duty_Ratio(&g_audio, 100);

    return;
}

void Play_Open_Close_Sound(void) {
    // 주기만 변경해주면서 소리 출력.
    float buzzer[2] = {261.686f, 500.262f};

    // TODO: idx 미 선언으로 인한 빌드 에러
//    unsigned int uPeriod = (unsigned int)(100000000/buzzer[idx]);

    // TODO: uPeriod 미 선언으로 인한 빌드 에러
//    Set_Duty_Period(&g_audio, uPeriod);
    Set_Duty_Ratio(&g_audio, 50);
    return;
}
// ------------------------- 부저 2개 각기 다른 period 인가가 되는지 확인하는 코드 ---------------------------------
void Make_sound_two_buzzer(uint32 idx1, uint32 idx2) {
    float buzzer[2] = {261.686f, 100.262f};
    unsigned int uPeriod1 = (unsigned int)(100000000/buzzer[idx1]);
    unsigned int uPeriod2 = (unsigned int)(100000000/buzzer[idx2]);

    Set_Duty_Period(&g_audio, uPeriod1);
    Set_Duty_Period(&g_audio, uPeriod2);

    Set_Duty_Ratio(&g_audio, 50);
    Set_Duty_Ratio(&g_audio, 50);
}

void Play_DoorOpen_Sound_two_buzzer(void){
    /* Initialize a time variable */
    Ifx_TickTime ticksFor10ms = IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME);

    Make_sound_two_buzzer(0, 1);
    waitTime(ticksFor10ms * 100);
    Make_sound_two_buzzer(1, 0);
    waitTime(ticksFor10ms * 100);
}
// ------------------------- 부저 2개 각기 다른 period 인가가 되는지 확인하는 코드 ---------------------------------

// ------------------------- LED 2개로 주기는 동일하게하고 듀티비를 다르게해서 테스트한 코드 ----------------------------
//void test_led_init(void){
//    initGtm();
//    initGtmTomPwm(&g_audio); // PWM PIN 6
//    initGtmTomPwm(&g_audio); // PWM PIN 7
//}

// ------------------------- LED 2개로 주기는 동일하게하고 듀티비를 다르게해서 테스트한 코드 ----------------------------
