#ifndef INCLUDES_APPLICATION_AUDIO_H_
#define INCLUDES_APPLICATION_AUDIO_H_

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Platform_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void Init_Audio(void);
void Make_Sound(uint32 idx);
void Play_Door_CloseOpen_Sound(void);
void Play_Danger_Sound(void);
void Play_Open_Close_Sound(void);
void Make_sound_two_buzzer(uint32 idx1, uint32 idx2);
void Play_DoorOpen_Sound_two_buzzer(void);

void test_led_init();
#endif /* INCLUDES_APPLICATION_AUDIO_H_ */
