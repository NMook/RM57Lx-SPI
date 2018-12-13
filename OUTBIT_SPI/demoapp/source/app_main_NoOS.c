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


// Stores each character given in the COM port through UART. (Currently disabled)
static unsigned char command;
// Sign whether the transfer of data is completed.
uint32_t transfer_complete;
// Counter used to actively wait before re-sending the message.
uint32_t i;

/* External Support Functions */
extern void sciDisplayText(sciBASE_t *sci, uint8 *text, uint32 length);
extern uint32 Get_Temp_Sensor_data(void);
void sciDisplayData(sciBASE_t *sci, uint8 *text,uint32 length);


void main()
{
    // Data to be send from this master to connected slave.
    uint16_t txBuffer[10] = {0x0000, 0x0011, 0x0022, 0x0033, 0x0044, 0x0055, 0x0066, 0x0077, 0x0088, 0x0099};
    // Buffer to store received data from slave. (Currently unused)
    uint16_t rxBuffer[10];

    _enable_interrupt_();
    volatile boolean retVal; /* For function return values */

    gioInit();
    adcInit();
    adcCalibration(adcREG1);
    rtiInit();
    sciInit();
    mibspiInit();

    // Enable to receive notifications of transfer completion.
    mibspiEnableGroupNotification(mibspiREG1,0,0);
    // Load to-be-sent data in transfer group.
    mibspiSetData(mibspiREG1, 0, txBuffer);

    while (1) {
        // Set completion sign to incomplete.
        transfer_complete = 0x55555555;
        // Start transferring data for transfer group 0.
        mibspiTransfer(mibspiREG1, 0);
        // Wait while the transfer is incomplete.
        while(transfer_complete != 0xA5A5A5A5);
        // Get received data from slave and write to rxBuffer.
        mibspiGetData(mibspiREG1, 0, rxBuffer);
        // Actively wait for 1000 ticks before sending new message.
        for (i = 0; i < 1000; i++) {
            ;
        }
    }
}

void mibspiGroupNotification(mibspiBASE_t *mibspi, uint32 group)
{
    switch (group){
        case 0 :
            // If an interrupt is given for transfer group 0, set completion sign to complete.
            transfer_complete = 0xA5A5A5A5;
            break;
        default :
            while(1);
    }
}

// Functions used to print received characters from UART back to COM port. (Currently unused)
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
