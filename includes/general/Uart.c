/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxAsclin_Asc.h"
#include "IfxCpu_Irq.h"
#include "IfxPort_PinMap.h"
#include "Pin_Map.h"
#include "Uart.h"
#include "Platform_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define BAUDRATE           115200                                  /* UART baud rate in bit/s                  */

#define PIN_RX             IfxAsclin0_RXB_P15_3_IN                 /* UART receive port pin                    */
#define PIN_TX             IfxAsclin0_TX_P15_2_OUT                 /* UART transmit port pin                   */

/* Definition of the interrupt priorities */
#define INTPRIO_RX      18
#define INTPRIO_TX      19

#define RX_BUFFER_SIZE     64                                      /* Definition of the receive buffer size    */
#define TX_BUFFER_SIZE     64                                      /* Definition of the transmit buffer size   */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/* Declaration of the ASC handle */
static IfxAsclin_Asc g_uart_handler;

/* Declaration of the FIFOs parameters */
static uint8 g_tx_buffer[TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
static uint8 g_rx_buffer[RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];

uint32 g_rx_data = UART_NOINPUT;

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
IFX_INTERRUPT(TxISR, 0, INTPRIO_TX);
void TxISR(void) {
    IfxAsclin_Asc_isrTransmit(&g_uart_handler);
}

IFX_INTERRUPT(RxISR, 0, INTPRIO_RX);
void RxISR(void) {
    g_rx_data = g_uart_handler.asclin->RXDATA.U;
}

/* This function initializes the ASCLIN UART module */
void Init_Uart() {
//    *g_main = &g_rx_data;
    /* Initialize an instance of IfxAsclin_Asc_Config with default values */
    IfxAsclin_Asc_Config asc_config;
    IfxAsclin_Asc_initModuleConfig(&asc_config, &MODULE_ASCLIN0);

    /* Set the desired baud rate */
    asc_config.baudrate.baudrate = BAUDRATE;

    /* ISR priorities and interrupt target */
    asc_config.interrupt.txPriority = INTPRIO_TX;
    asc_config.interrupt.rxPriority = INTPRIO_RX;
    asc_config.interrupt.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

    /* FIFO configuration */
    asc_config.txBuffer = &g_tx_buffer;
    asc_config.txBufferSize = TX_BUFFER_SIZE;
    asc_config.rxBuffer = &g_rx_buffer;
    asc_config.rxBufferSize = RX_BUFFER_SIZE;

    /* Pin configuration */
    const IfxAsclin_Asc_Pins pins = {
        NULL_PTR,       IfxPort_InputMode_pullUp,     /* CTS pin not used */
        &PIN_RX,   IfxPort_InputMode_pullUp,     /* RX pin           */
        NULL_PTR,       IfxPort_OutputMode_pushPull,  /* RTS pin not used */
        &PIN_TX,   IfxPort_OutputMode_pushPull,  /* TX pin           */
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    asc_config.pins = &pins;

    IfxAsclin_Asc_initModule(&g_uart_handler, &asc_config); /* Initialize module with above parameters */
}

void Send_Uart_Msg(uint8 *msg, Ifx_SizeT count) {
    IfxAsclin_Asc_write(&g_uart_handler, msg, &count, TIME_INFINITE);   /* Transmit data via TX */
}
