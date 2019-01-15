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
#include "HL_system.h"

/* USER CODE BEGIN (1) */
#include "HL_sys_core.h"
#include "HL_spi.h"
#include "HL_mibspi.h"
#include "HL_reg_spi.h"
#include "HL_sci.h"
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

void sciDisplayText(sciBASE_t *sci, uint8 *text, uint32 length);
void wait(uint32 time);

/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
    uint32_t error = 0;
    uint16 TG0_TX_DATA[264] = {29871,     53848,  48686,  46903,  55692,  21772,  35488,  58030,  50628,  63620,  5259,
                             57873,  48115,  48008,  50445,  45035,  41746,  37209,  41773,  62181,  2996,   39774,
                             6286,   37569,  50435,  60418,  30586,  53741,  42316,  15955,  23992,  58613,  20292,
                             27866,  56101,  4069,   16024,  54752,  35216,  20260,  11708,  30265,  11063,  55957,
                             37558,  47241,  63825,  38494,  8927,   21772,  15491,  26685,  26495,  39144,  59264,
                             44392,  61122,  63039,  33721,  41320,  1499,   24172,  47467,  23454,  3593,   36858,
                             46073,  43633,  33762,  49038,  1527,   43950,  16181,  46698,  137,    33909,  6040,
                             35436,  8346,   31490,  38722,  41420,  39118,  21915,  20155,  57722,  39937,  40997,
                             62072,  27331,  61416,  55762,  30190,  42574,  40284,  50865,  56354,  58072,  12320,
                             64458,  19168,  50110,  24737,  1286,   55216,  63712,  28428,  17930,  42000,  18485,
                             58520,  52637,  37517,  14894,  16640,  56895,  28611,  58642,  63676,  50104,  46886,
                             22829,  28864,  41107,  36050,  45315,  23299,  26270,  59542,  38122,  24330,  1762,
                             2363,   29698,  8893,   4911,   21513,  55074,  48100,  41096,  32505,  36848,  60860,
                             53041,  52377,  17567,  42933,  58742,  3517,   20199,  57682,  44945,  12267,  45859,
                             49530,  38391,  60748,  64571,  24912,  21668,  27499,  65498,  58597,  23719,  55105,
                             41149,  20586,  5104,   23155,  37927,  57639,  163,    30442,  43459,  30562,  22315,
                             6130,   17719,  2723,   40186,  24042,  14218,  30083,  13480,  23902,  39483,  42510,
                             11585,  18133,  34558,  677,    27350,  4599,   15260,  60126,  36211,  15962,  29434,
                             64271,  15747,  30412,  64024,  31244,  2416,   48687,  37181,  52994,  26811,  50417,
                             53502,  9937,   11870,  55789,  25354,  2333,   14599,  44111,  11335,  20850,  63014,
                             15435,  51283,  58183,  56278,  52249,  52680,  43445,  31312,  29964,  57126,  7570,
                             20407,  11136,  1625,   59681,  3118,   1810,   22729,  24484,  2184,   27642,  9473,
                             61394,  57971,  51387,  51617,  23691,  50432,  42626,  26406,  45127,  52816,  49124,
                             45662,  19387,  54926,  56965,  28761,  33386,  50988,  33856,  28157,  25072,  7159

    };
    uint16 TG0_RX_DATA[264] = {0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
                               0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    // SPI configuration. Left to right: Chip select hold, WS_Delay, Data format, Chip select.
    spiDAT1_t config = {true, true, SPI_FMT_0, 0x00};

    /* Enable IRQ Interrupt in Cortex R4 CPU */
    _enable_interrupt_();

    spiInit();
    sciInit();

    spiTransmitAndReceiveData(spiREG1,&config,264,TG0_TX_DATA,TG0_RX_DATA);

/* USER CODE END */

    return 0;
}


/* USER CODE BEGIN (4) */
void sciDisplayText(sciBASE_t *sci, uint8 *text, uint32 length) {
    while(length--) {
        while ((sciREG1->FLR & 0x4) == 4); // Wait until busy
        sciSendByte(sciREG1, *text++); // Send text
    }
}
void wait(uint32 time) {
    time --;
}
/* USER CODE END */
