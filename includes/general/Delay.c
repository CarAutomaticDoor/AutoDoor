/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Delay.h"

#include "Bsp.h"
#include "Platform_Types.h"
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
sint32 Ms_To_Stm_Ticks(uint32 millis) {
    return IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, millis);
}

sint32 Us_To_Stm_Ticks(uint32 micros) {
    return IfxStm_getTicksFromMicroseconds(BSP_DEFAULT_TIMER, micros);
}

void Delay_Sec(uint32 second) {
    Ifx_TickTime ticks = Ms_To_Stm_Ticks(second * 1000);
    waitTime(ticks);
}

void Delay_Ms(uint32 millis) {
    Ifx_TickTime ticks = Ms_To_Stm_Ticks(millis);
    waitTime(ticks);
}

void Delay_Us(uint32 micros) {
    Ifx_TickTime ticks = Us_To_Stm_Ticks(micros);
    waitTime(ticks);
}

uint64 Get_Cur_Seconds(void) {
    return IfxStm_get(&MODULE_STM0) / IfxStm_getFrequency(&MODULE_STM0);
}

uint64 Get_Cur_Millis(void) {
    return IfxStm_get(&MODULE_STM0) / IfxStm_getFrequency(&MODULE_STM0) * 1000;
}

uint64 Get_Cur_Micros(void) {
    return IfxStm_get(&MODULE_STM0) / IfxStm_getFrequency(&MODULE_STM0) * 1000000;
}
