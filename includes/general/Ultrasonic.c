/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ultrasonic.h"

#include "Platform_Types.h"
#include "IfxPort.h"
#include "IfxCpu.h"
#include "IfxStm.h"

#include "Delay.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define TIMEOUT     23529

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
uint32 Pulse_In(IfxPort_Pin pin, uint8 state, uint32 timeout);

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
void Init_Ultrasonic(Ultrasonic *config) {
    IfxPort_setPinModeOutput(config->trig.port, config->trig.pinIndex, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinModeInput(config->echo.port, config->echo.pinIndex, IfxPort_InputMode_pullUp);
}

float32 Get_Ultrasonic_Distance(Ultrasonic *config) {
    IfxPort_setPinLow(config->trig.port, config->trig.pinIndex);
    Delay_Us(2);
    IfxPort_setPinHigh(config->trig.port, config->trig.pinIndex);
    Delay_Us(10);
    IfxPort_setPinLow(config->trig.port, config->trig.pinIndex);

    boolean interrupt_state = IfxCpu_disableInterrupts();

    uint32 micros = Pulse_In(config->echo, TRUE, TIMEOUT);

    IfxCpu_restoreInterrupts(interrupt_state);

    return (float32)micros / 58.8235f;
}

uint32 Pulse_In(IfxPort_Pin pin, boolean state, uint32 timeout) {
    uint32 start_micros = Get_Cur_Micros();

    // wait for any previous pulse to end
    while (__getbit(&pin.port->IN.U, pin.pinIndex) == state) {
        if (Get_Cur_Micros() - start_micros >= timeout) {
            return 0;
        }
    }

    // wait for the pulse to start
    while (__getbit(&pin.port->IN.U, pin.pinIndex) != state) {
        if (Get_Cur_Micros() - start_micros >= timeout) {
            return 0;
        }
    }

    // wait for the pulse to stop
    uint32 estimation_start = Get_Cur_Micros();
    while (__getbit(&pin.port->IN.U, pin.pinIndex) == state) {
        if (Get_Cur_Micros() - start_micros >= timeout) {
            return 0;
        }
    }
    uint32 estimation_end = Get_Cur_Micros();

    return estimation_end - estimation_start;
}
