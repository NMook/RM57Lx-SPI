/** @file HL_sys_main.c 
*   @brief Application main file
*   @date 07-July-2017
*   @version 04.07.00
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2016 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "HL_sys_common.h"

/* USER CODE BEGIN (1) */
#include "HL_sys_core.h"
#include "HL_mibspi.h"
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */



uint32_t TG3_IS_Complete;
uint32_t i;

/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
    uint32_t error = 0;
    uint16 TG0_TX_DATA[8] = {0x1000, 0x1111, 0x1222, 0x1333, 0x1444, 0x1555, 0x1666, 0x1777};
    uint16 TG0_RX_DATA[8]= {0};

    /* Enable IRQ Interrupt in Cortex R4 CPU */
    _enable_interrupt_();

    /* - initializing mibspi - enabling tg 0,1,2,3 , length 8 bytes each
     * TG 0 - Configured for TICK Trigger
     * TG 1, 2, 3, are SOftware Triggered
     * CS 0 is used. - CS0 is in HOLD Mode,
     * CS 0 Toggles only after Each TG ( Every 8 byte) is complete
     * Trigger is One Shot, so only once the TG will transmit.
     */
    mibspiInit();

    /* Enable TG 0 complete interrupt to INT 0 */
    mibspiEnableGroupNotification(mibspiREG1,0,0);

    TG3_IS_Complete = 0x55555555;

    /* Enable TG0 to start, once tickCNT triggers */
    mibspiTransfer(mibspiREG1,0);

    // The following while-loop was inspired by the code uploaded at forum post:
    // https://e2e.ti.com/support/microcontrollers/hercules/f/312/t/613271
    while(1)
    {
        /* Wait until this flag is set in TG3 ISR */
        while(TG3_IS_Complete != 0xA5A5A5A5);

        mibspiGetData(mibspiREG1,0,TG0_RX_DATA);

        TG3_IS_Complete = 0x55555555;

        for (i = 0; i < 8; i++)
        {
            if (TG0_RX_DATA[i] != (TG0_TX_DATA[i] - 1))
                error++;
        }
    }

/* USER CODE END */

    return 0;
}


/* USER CODE BEGIN (4) */

void mibspiGroupNotification(mibspiBASE_t *mibspi, uint32 group)
{
    switch (group){
        case 0 :
            /* Enable TG1 to start, SW Trigger */
            TG3_IS_Complete = 0xA5A5A5A5;
            break;
        default :
            while(1);
            break;
    }
}

/* USER CODE END */
