#include "sl_types.h"
#include "sl_api.h"
#include "HL_sci.h"
#include "HL_gio.h"
#include "HL_rti.h"
#include "HL_adc.h"
#include "HL_mibspi.h"
#include "esm_application_callback.h"
#include "Application_Types.h"
#include "math.h"


uint32 periodicSTPassCount=0;
uint32 periodicSTFailCount=0;
uint32 maintaskcount = 0;
uint32 rtiCOMPARE2_PER,rtiCOMPARE1_PER_NEW,old_FCORERRCNT;
uint32  g_PotReading = 468750;
button USER1 = NONE, USER2 = NONE;
static unsigned char command;


uint32_t transfer_complete;

/* External Support Functions */
extern void sciDisplayText(sciBASE_t *sci, uint8 *text, uint32 length);
extern uint32 Get_Temp_Sensor_data(void);
void sciDisplayData(sciBASE_t *sci, uint8 *text,uint32 length);


void main()
{
    uint16_t txBuffer[10] = {0x0000, 0x0011, 0x0022, 0x0033, 0x0044, 0x0055, 0x0066, 0x0077, 0x0088, 0x0099};
    uint16_t rxBuffer[10];

    volatile boolean retVal; /* For function return values */
    periodicSTPassCount = 0;
    periodicSTFailCount = 0;

    _enable_IRQ();

    gioInit();
    adcInit();
    adcCalibration(adcREG1);
    rtiInit();
    sciInit();
    mibspiInit();
    mibspiEnableGroupNotification(mibspiREG1,0,0);

    mibspiSetData(mibspiREG1, 0, txBuffer);
    transfer_complete = 0x55555555;
    mibspiTransfer(mibspiREG1,0);

    while(1) {
        while(transfer_complete != 0xA5A5A5A5);

        mibspiGetData(mibspiREG1, 0, rxBuffer);

        transfer_complete = 0x55555555;
        /* Enable TG0 to start, once tickCNT triggers */
        mibspiTransfer(mibspiREG1,0);
    }
}

void mibspiGroupNotification(mibspiBASE_t *mibspi, uint32 group)
{
    switch (group){
        case 0 :
            transfer_complete = 0xA5A5A5A5;
            break;
        default :
            while(1);
    }
}

void sciNotification(sciBASE_t *sci, unsigned flags) {
    sciSend(sci, 1, (unsigned char *)&command);
    sciReceive(sci, 1, (unsigned char *)&command);
}
void esmGroup1Notification(int bit) {
    return;
}
void esmGroup2Notification(int bit) {
    return;
}
