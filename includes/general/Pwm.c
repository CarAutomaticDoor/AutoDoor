/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Pwm.h"

#include "Platform_Types.h"
#include "IfxGtm_Tom_Pwm.h"

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void Init_Pwm(Pwm *pwm, IfxGtm_Tom_ToutMap *tom, uint16 period, uint16 duty_cycle)
{
    /* Initialize the configuration structure with default parameters */
    IfxGtm_Tom_Pwm_initConfig(&pwm->config, &MODULE_GTM);

    pwm->config.tom = tom->tom;                                      /* Select the TOM depending on the LED          */
    pwm->config.tomChannel = tom->channel;                           /* Select the channel depending on the LED      */
    pwm->config.period = period;                                    /* Set the pwm period                           */
    pwm->config.dutyCycle = duty_cycle;                              /* Set the pwm duty cycle                       */
    pwm->config.pin.outputPin = tom;                               /* Set the LED port pin as output               */
    pwm->config.synchronousUpdateEnabled = TRUE;                                    /* Enable synchronous update                    */

    IfxGtm_Tom_Pwm_init(&pwm->driver, &pwm->config);                /* Initialize the GTM TOM                       */

    IfxGtm_Tom_Pwm_start(&pwm->driver, TRUE);                       /* Start the PWM                                */
}

void Set_Duty_Cycle(Pwm *pwm, uint32 duty_cycle)
{
    pwm->config.dutyCycle = duty_cycle;
    IfxGtm_Tom_Pwm_init(&pwm->driver, &pwm->config);                /* Initialize the GTM TOM                       */
}

void Set_Duty_Period(Pwm *pwm, uint32 period)
{
    pwm->config.period = period;                              /* Change the period           */
    IfxGtm_Tom_Pwm_init(&pwm->driver, &pwm->config);                /* Re-initialize the PWM                        */
}

void Set_Duty_Ratio(Pwm *pwm, uint8 duty_ratio)
{
    uint32 duty_cycle = (uint32)(0.01f * duty_ratio * pwm->config.period);
    Set_Duty_Cycle(pwm, duty_cycle);
}

void Set_Pwm_Period(Pwm *pwm, uint32 period) {
    // 듀티비는 유지하되, ticks 수만을 늘리는것.
    float32 ratio = (float32)pwm->config.dutyCycle / pwm->config.period;
    pwm->config.period = period;
    pwm->config.dutyCycle = (uint32)(period * ratio);
    IfxGtm_Tom_Pwm_init(&pwm->driver, &pwm->config);
}
