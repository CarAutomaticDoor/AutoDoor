/**********************************************************************************************************************
 * \file Uart.c
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
#include "IfxAsclin_Asc.h"
#include "IfxCpu_Irq.h"
#include "IfxPort_PinMap.h"
#include "Pin_Map.h"
#include "Servo.h"

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
#define SIZE               13
/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/* Declaration of the ASC handle */
static IfxAsclin_Asc g_uart_handler;

/* Declaration of the FIFOs parameters */
static uint8 g_tx_buffer[TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
static uint8 g_rx_buffer[RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];

uint32 g_rx_data = 0;
/*********************************************************************************************************************/
/*--------------------------------------------Private Variables/Constants--------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/

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
void Init_Uart(void) {
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
