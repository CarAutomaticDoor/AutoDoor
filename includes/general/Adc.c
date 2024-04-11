/**********************************************************************************************************************
 * \file ADC_Background_Scan.c
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
#include "Adc.h"

#include "IfxVadc_Adc.h"
#include "Platform_Types.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
void Init_Vadc_Module(void);                      /* Function to initialize the VADC module with default parameters   */
void Init_Vadc_Group(void);                       /* Function to initialize the VADC group                            */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
IfxVadc_Adc g_vadc;                                           /* Global variable for configuring the VADC module    */
IfxVadc_Adc_Group g_vadc_group;                                /* Global variable for configuring the VADC group     */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Function to initialize the VADC module */
void Init_Vadc(void) {
    Init_Vadc_Module();                                                   /* Initialize the VADC module               */
    Init_Vadc_Group();                                                    /* Initialize the VADC group                */

}

/* Function to initialize the VADC module with default parameters */
void Init_Vadc_Module(void) {
    IfxVadc_Adc_Config adc_config;                                         /* Define a configuration structure         */
    IfxVadc_Adc_initModuleConfig(&adc_config, &MODULE_VADC);               /* Fill it with default values              */
    IfxVadc_Adc_initModule(&g_vadc, &adc_config);                          /* Apply the configuration                  */
}

/* Function to initialize the VADC group */
void Init_Vadc_Group(void) {
    IfxVadc_Adc_GroupConfig adc_group_config;                               /* Define a configuration structure         */
    IfxVadc_Adc_initGroupConfig(&adc_group_config, &g_vadc);                /* Fill it with default values              */

    adc_group_config.groupId = IfxVadc_GroupId_4;                           /* Select the Group 4                       */
    adc_group_config.master = adc_group_config.groupId;                         /* Set the same group as master group       */

    /* Enable the background scan source and the background auto scan functionality */
    adc_group_config.arbiter.requestSlotBackgroundScanEnabled = TRUE;
    adc_group_config.backgroundScanRequest.autoBackgroundScanEnabled = TRUE;

    /* Enable the gate in "always" mode (no edge detection) */
    adc_group_config.backgroundScanRequest.triggerConfig.gatingMode = IfxVadc_GatingMode_always;

    IfxVadc_Adc_initGroup(&g_vadc_group, &adc_group_config);                 /* Apply the configuration                  */
}

/* Function to initialize the VADC used channels */
void Init_Vadc_Channel(IfxVadc_Adc_Channel *adc) {
    IfxVadc_Adc_ChannelConfig adc_channel_config;             /* Array of configuration structures        */

    /* Fill the configuration with default values */
    IfxVadc_Adc_initChannelConfig(&adc_channel_config, &g_vadc_group);

    /* Set the channel ID and the corresponding result register */
    adc_channel_config.channelId = adc->channel;          /* The channels 4..7 are initialized        */
    adc_channel_config.resultRegister = adc->resultreg;
    adc_channel_config.backgroundChannel = TRUE;                   /* Enable background scan for the channel   */

    /* Apply the channel configuration */
    IfxVadc_Adc_initChannel(adc, &adc_channel_config);

    /* Add the channel to background scan */
    unsigned chn_enable_bit = (1 << adc_channel_config.channelId);   /* Set the the corresponding input channel  */
    unsigned mask = chn_enable_bit;                                   /* of the respective group to be added in   */
    IfxVadc_Adc_setBackgroundScan(&g_vadc, &g_vadc_group, chn_enable_bit, mask); /* the background scan sequence.  */
}

/* Function to read the VADC measurement */
uint16 Read_Adc_Value(IfxVadc_Adc_Channel *adc) {
    Ifx_VADC_RES conversionResult;
    do {
        conversionResult = IfxVadc_Adc_getResult(adc);
    } while(!conversionResult.B.VF);

    return conversionResult.B.RESULT;
}

void Start_Adc_Scan(void) {
    IfxVadc_Adc_startBackgroundScan(&g_vadc);
}
