/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Servo.h"

#include "IfxPort.h"
#include "IfxGtm_Tom_Timer.h"
#include "Pin_Map.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define ISR_PRIORITY    1                       /* Interrupt priority number                                    */
#define ISR_FREQ        10000.0f

#define DUTY_20MS       200
/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxGtm_Tom_Timer g_timerDriver;                     /* TOM driver                                                   */
uint32 g_duty_door = 30;
uint32 g_duty_lock = 30;

/*********************************************************************************************************************/
/*--------------------------------------------Function Implementations-----------------------------------------------*/
/*********************************************************************************************************************/
/* Macro to define the Interrupt Service Routine. */
IFX_INTERRUPT(Isr_Servo, 0, ISR_PRIORITY);

/* Interrupt Service Routine of the TOM */
void Isr_Servo(void)
{
    static uint32 counter = 0;
    IfxGtm_Tom_Timer_acknowledgeTimerIrq(&g_timerDriver);                       /* Clear the timer event            */
    if (counter == 0) {
        SET_PIN(PIN_DOOR_CTRL, HIGH);
        SET_PIN(PIN_LOCK_CTRL, HIGH);
    }
    if (counter == g_duty_door) {
        SET_PIN(PIN_DOOR_CTRL, LOW);
    }
    if (counter == g_duty_lock) {
        SET_PIN(PIN_LOCK_CTRL, LOW);
    }

    if (counter >= DUTY_20MS - 1) {
        counter = 0;
    } else {
        counter++;
    }
}

/* This function initializes the TOM */
void Init_Servos(void)
{

    IfxGtm_Tom_Timer_Config timerConfig;                                        /* Timer configuration              */
    IfxGtm_Tom_Timer_initConfig(&timerConfig, &MODULE_GTM);                     /* Initialize timer configuration   */

    timerConfig.base.frequency       = ISR_FREQ;                                /* Set timer frequency              */
    timerConfig.base.isrPriority     = ISR_PRIORITY;                        /* Set interrupt priority           */
    timerConfig.base.isrProvider     = IfxSrc_Tos_cpu0;                         /* Set interrupt provider           */
    timerConfig.tom                  = IfxGtm_Tom_1;                            /* Define the timer used            */
    timerConfig.timerChannel         = IfxGtm_Tom_Ch_0;                         /* Define the channel used          */
    timerConfig.clock                = IfxGtm_Tom_Ch_ClkSrc_cmuFxclk3;          /* Define the CMU clock used        */
    IfxGtm_Tom_Timer_init(&g_timerDriver, &timerConfig);                        /* Initialize the TOM               */

    PIN_MODE(PIN_DOOR_CTRL, OUTPUT_MODE);  /* Set pin mode         */
    PIN_MODE(PIN_LOCK_CTRL, OUTPUT_MODE);
    IfxGtm_Tom_Timer_run(&g_timerDriver); /* Start the TOM */
}

void Set_Duty_Door(uint32 n) {
    g_duty_door = n;
}

void Set_Duty_Lock(uint32 n) {
    g_duty_lock = n;
}
