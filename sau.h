#ifndef __SAU_H
#define __SAU_H

#include "GlobalVar.h"
#include "string.h"
#include "stdlib.h"

#pragma interrupt r_uart0_interrupt_send(vect=INTST0)     
#pragma interrupt r_uart0_interrupt_receive(vect=INTSR0)
#pragma interrupt r_uart0_interrupt_error(vect=INTSRE0)

//#pragma interrupt r_uart0_interrupt_error(vect=INTSRE0)
//#pragma interrupt r_uart1_interrupt_send(vect=INTST1)
//#pragma interrupt r_uart1_interrupt_receive(vect=INTSR1)
//#pragma interrupt r_uart1_interrupt_error(vect=INTSRE1)
//#pragma interrupt r_csi00_interrupt(vect=INTCSI00)
//#pragma interrupt r_iic00_interrupt(vect=INTIIC00)


/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    The SPSm register is a 16-bit register that is used to select two types of operation clocks (CKm0, CKm1) that are
commonly supplied to each channel. (SPSm) 
*/
/* Section of operation clock (CKm0) (PRSm00,PRSm01,PRSm02,PRSm03,) */
#define _0000_SAU_CK00_fCLK_0                   (0x0000U) /* ck00-fCLK */
#define _0001_SAU_CK00_fCLK_1                   (0x0001U) /* ck00-fCLK/2^1 */
#define _0002_SAU_CK00_fCLK_2                   (0x0002U) /* ck00-fCLK/2^2 */
#define _0003_SAU_CK00_fCLK_3                   (0x0003U) /* ck00-fCLK/2^3 */
#define _0004_SAU_CK00_fCLK_4                   (0x0004U) /* ck00-fCLK/2^4 */
#define _0005_SAU_CK00_fCLK_5                   (0x0005U) /* ck00-fCLK/2^5 */
#define _0006_SAU_CK00_fCLK_6                   (0x0006U) /* ck00-fCLK/2^6 */
#define _0007_SAU_CK00_fCLK_7                   (0x0007U) /* ck00-fCLK/2^7 */
#define _0008_SAU_CK00_fCLK_8                   (0x0008U) /* ck00-fCLK/2^8 */
#define _0009_SAU_CK00_fCLK_9                   (0x0009U) /* ck00-fCLK/2^9 */
#define _000A_SAU_CK00_fCLK_10                  (0x000AU) /* ck00-fCLK/2^10 */
#define _000B_SAU_CK00_fCLK_11                  (0x000BU) /* ck00-fCLK/2^11 */
#define _000C_SAU_CK00_fCLK_12                  (0x000CU) /* ck00-fCLK/2^12 */
#define _000D_SAU_CK00_fCLK_13                  (0x000DU) /* ck00-fCLK/2^13 */
#define _000E_SAU_CK00_fCLK_14                  (0x000EU) /* ck00-fCLK/2^14 */
#define _000F_SAU_CK00_fCLK_15                  (0x000FU) /* ck00-fCLK/2^15 */
/* Section of operation clock (CKm1) (PRSm10,PRSm11,PRSm12,PRSm13,) */
#define _0000_SAU_CK01_fCLK_0                   (0x0000U) /* ck01-fCLK */
#define _0010_SAU_CK01_fCLK_1                   (0x0010U) /* ck01-fCLK/2^1 */
#define _0020_SAU_CK01_fCLK_2                   (0x0020U) /* ck01-fCLK/2^2 */
#define _0030_SAU_CK01_fCLK_3                   (0x0030U) /* ck01-fCLK/2^3 */
#define _0040_SAU_CK01_fCLK_4                   (0x0040U) /* ck01-fCLK/2^4 */
#define _0050_SAU_CK01_fCLK_5                   (0x0050U) /* ck01-fCLK/2^5 */
#define _0060_SAU_CK01_fCLK_6                   (0x0060U) /* ck01-fCLK/2^6 */
#define _0070_SAU_CK01_fCLK_7                   (0x0070U) /* ck01-fCLK/2^7 */
#define _0080_SAU_CK01_fCLK_8                   (0x0080U) /* ck01-fCLK/2^8 */
#define _0090_SAU_CK01_fCLK_9                   (0x0090U) /* ck01-fCLK/2^9 */
#define _00A0_SAU_CK01_fCLK_10                  (0x00A0U) /* ck01-fCLK/2^10 */
#define _00B0_SAU_CK01_fCLK_11                  (0x00B0U) /* ck01-fCLK/2^11 */
#define _00C0_SAU_CK01_fCLK_12                  (0x00C0U) /* ck01-fCLK/2^12 */
#define _00D0_SAU_CK01_fCLK_13                  (0x00D0U) /* ck01-fCLK/2^13 */
#define _00E0_SAU_CK01_fCLK_14                  (0x00E0U) /* ck01-fCLK/2^14 */
#define _00F0_SAU_CK01_fCLK_15                  (0x00F0U) /* ck01-fCLK/2^15 */

/*
    Serial mode register mn (SMRmn) 
*/
/* Selection of operation clock (fMCK) of channel n (CKSmn) */
#define _0000_SAU_CLOCK_SELECT_CK00             (0x0000U) /* operation clock CKm0 set by the SPSm register */
#define _8000_SAU_CLOCK_SELECT_CK01             (0x8000U) /* operation clock CKm1 set by the SPSm register */
/* Selection of transfer clock (fTCLK) of channel n (CCSmn) */
#define _0000_SAU_CLOCK_MODE_CKS                (0x0000U) /* divided operation clock fMCK specified by the CKSmn bit */
#define _4000_SAU_CLOCK_MODE_TI0N               (0x4000U) /* clock input fSCK from the SCKp pin (slave transfer in CSI mode) */
/* Selection of start trigger source (STSmn) */
#define _0000_SAU_TRIGGER_SOFTWARE              (0x0000U) /* only software trigger is valid (selected for CSI, UART transmission, and simplified I2C) */
#define _0100_SAU_TRIGGER_RXD                   (0x0100U) /* valid edge of the RxDq pin (selected for UART reception) */
/* Controls inversion of level of receive data of channel n in UART mode (SISmn0) */
#define _0000_SAU_EDGE_FALL                     (0x0000U) /* falling edge is detected as the start bit.
                                                             The input communication data is captured as is */
#define _0040_SAU_EDGE_RISING                   (0x0040U) /* rising edge is detected as the start bit.
                                                             The input communication data is inverted and captured */
/* Setting of operation mode of channel n (MDmn2, MDmn1) */
#define _0000_SAU_MODE_CSI                      (0x0000U) /* CSI mode */
#define _0002_SAU_MODE_UART                     (0x0002U) /* UART mode */
#define _0004_SAU_MODE_IIC                      (0x0004U) /* simplified I2C mode */
/* Selection of interrupt source of channel n (MDmn0) */
#define _0000_SAU_TRANSFER_END                  (0x0000U) /* transfer end interrupt */
#define _0001_SAU_BUFFER_EMPTY                  (0x0001U) /* buffer empty interrupt */

/*
    Serial communication operation setting register mn (SCRmn) 
*/
/* Setting of operation mode of channel n (TXEmn, RXEmn) */
#define _0000_SAU_NOT_COMMUNICATION             (0x0000U) /* disable communication */
#define _4000_SAU_RECEPTION                     (0x4000U) /* reception only */
#define _8000_SAU_TRANSMISSION                  (0x8000U) /* transmission only */
#define _C000_SAU_RECEPTION_TRANSMISSION        (0xC000U) /* transmission/reception */
/* Selection of data and clock phase in CSI mode (DAPmn,CKPmn) */
#define _0000_SAU_TIMING_1                      (0x0000U) /* type 1 */
#define _1000_SAU_TIMING_2                      (0x1000U) /* type 2 */
#define _2000_SAU_TIMING_3                      (0x2000U) /* type 3 */
#define _3000_SAU_TIMING_4                      (0x3000U) /* type 4 */
/* Mask control of error interrupt signal (INTSREx (x = 0 to 1)) (EOCmn) */
#define _0000_SAU_INTSRE_MASK                   (0x0000U) /* disables generation of error interrupt INTSREx (INTSRx is generated) */
#define _0400_SAU_INTSRE_ENABLE                 (0x0400U) /* enables generation of error interrupt INTSREx (INTSRx is not generated if an error occurs) */
/* Setting of parity bit in UART mode (PTCmn1, PTCmn0) */
#define _0000_SAU_PARITY_NONE                   (0x0000U) /* none parity */
#define _0100_SAU_PARITY_ZERO                   (0x0100U) /* zero parity */
#define _0100_SAU_PARITY_NO_JUDGMENT            (0x0100U) /* no judgment */
#define _0200_SAU_PARITY_EVEN                   (0x0200U) /* even parity */
#define _0300_SAU_PARITY_ODD                    (0x0300U) /* odd parity */
/* Selection of data transfer sequence in CSI and UART modes (DIRmn) */
#define _0000_SAU_MSB                           (0x0000U) /* inputs/outputs data with MSB first */
#define _0080_SAU_LSB                           (0x0080U) /* inputs/outputs data with LSB first */
/* Setting of stop bit in UART mode (SLCmn1, SLCmn0) */
#define _0000_SAU_STOP_NONE                     (0x0000U) /* no stop bit */
#define _0010_SAU_STOP_1                        (0x0010U) /* Stop bit length = 1 bit */
#define _0020_SAU_STOP_2                        (0x0020U) /* stop bit length = 2 bits (mn = 00, 02 only) */
/* Setting of data length in CSI and UART modes (DLSmn1, DLSmn0) */
#define _0001_SAU_LENGTH_9                      (0x0001U) /* 9-bit data length */
#define _0002_SAU_LENGTH_7                      (0x0002U) /* 7-bit data length */
#define _0003_SAU_LENGTH_8                      (0x0003U) /* 8-bit data length */

/*
    Serial flag clear trigger register mn (SIRmn) 
*/
/* Clear trigger of framing error of channel n (FECTmn) */
#define _0004_SAU_SIRMN_FECTMN                  (0x0004U) /* clears the FEFmn bit of the SSRmn register to 0 */
/* Clear trigger of parity error flag of channel n (PECTmn) */
#define _0002_SAU_SIRMN_PECTMN                  (0x0002U) /* clears the PEFmn bit of the SSRmn register to 0 */
/* Clear trigger of overrun error flag of channel n (OVCTmn) */
#define _0001_SAU_SIRMN_OVCTMN                  (0x0001U) /* clears the OVFmn bit of the SSRmn register to 0 */

/*
    Serial status register mn (SSRmn) 
*/
/* Communication status indication flag of channel n (TSFmn) */
#define _0040_SAU_UNDER_EXECUTE                 (0x0040U) /* communication is in progress */
/* Buffer register status indication flag of channel n (BFFmn) */
#define _0020_SAU_VALID_STORED                  (0x0020U) /* valid data is stored in the SDRmn register */
/* Framing error detection flag of channel n (FEFmn) */
#define _0004_SAU_FRAM_ERROR                    (0x0004U) /* an error occurs (during UART reception) */
/* Parity error detection flag of channel n (PEFmn) */
#define _0002_SAU_PARITY_ERROR                  (0x0002U) /* an error occurs (during UART reception) or ACK is not detected (during I2C transmission) */
/* Overrun error detection flag of channel n (OVFmn) */
#define _0001_SAU_OVERRUN_ERROR                 (0x0001U) /* an overrun error occurs */

/*
    Serial channel start register m (SSm) 
*/
/* Operation start trigger of channel 3 (SSm3) */
#define _0000_SAU_CH3_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0008_SAU_CH3_START_TRG_ON              (0x0008U) /* sets the SEmn bit to 1 and enters the communication wait status */
/* Operation start trigger of channel 2 (SSm2) */
#define _0000_SAU_CH2_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0004_SAU_CH2_START_TRG_ON              (0x0004U) /* sets the SEmn bit to 1 and enters the communication wait status */
/* Operation start trigger of channel 1 (SSm1) */
#define _0000_SAU_CH1_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0002_SAU_CH1_START_TRG_ON              (0x0002U) /* sets the SEmn bit to 1 and enters the communication wait status */
/* Operation start trigger of channel 0 (SSm0) */
#define _0000_SAU_CH0_START_TRG_OFF             (0x0000U) /* no trigger operation */
#define _0001_SAU_CH0_START_TRG_ON              (0x0001U) /* sets the SEmn bit to 1 and enters the communication wait status */

/*
    Format of Serial channel stop register m (STm) 
*/
/* Operation stop trigger of channel 3 (STm3) */
#define _0000_SAU_CH3_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0008_SAU_CH3_STOP_TRG_ON               (0x0008U) /* clears the SEmn bit to 0 and stops the communication operation */
/* Operation stop trigger of channel 2 (STm2) */
#define _0000_SAU_CH2_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0004_SAU_CH2_STOP_TRG_ON               (0x0004U) /* clears the SEmn bit to 0 and stops the communication operation */
/* Operation stop trigger of channel 1 (STm1) */
#define _0000_SAU_CH1_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0002_SAU_CH1_STOP_TRG_ON               (0x0002U) /* clears the SEmn bit to 0 and stops the communication operation */
/* Operation stop trigger of channel 0 (STm0) */
#define _0000_SAU_CH0_STOP_TRG_OFF              (0x0000U) /* no trigger operation */
#define _0001_SAU_CH0_STOP_TRG_ON               (0x0001U) /* clears the SEmn bit to 0 and stops the communication operation */

/*
    Serial channel enable status register m (SEm) 
*/
/* Indication of operation enable/stop status of channel 3 (SEm3) */
#define _0000_SAU_CH3_STATUS_DISABLE            (0x0000U) /* operation stops */
#define _0008_SAU_CH3_STATUS_ENABLE             (0x0008U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 2 (SEm2) */
#define _0000_SAU_CH2_STATUS_DISABLE            (0x0000U) /* operation stops */
#define _0004_SAU_CH2_STATUS_ENABLE             (0x0004U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 1 (SEm1) */
#define _0000_SAU_CH1_STATUS_DISABLE            (0x0000U) /* operation stops */
#define _0002_SAU_CH1_STATUS_ENABLE             (0x0002U) /* operation is enabled */
/* Indication of operation enable/stop status of channel 0 (SEm0) */
#define _0000_SAU_CH0_STATUS_DISABLE            (0x0000U) /* operation stops */
#define _0001_SAU_CH0_STATUS_ENABLE             (0x0001U) /* operation is enabled */

/*
    Serial output enable register m (SOEm) 
*/
/* Serial output enable/stop of channel 2 (SOEm2) */
#define _0000_SAU_CH2_OUTPUT_DISABLE            (0x0000U) /* stops output by serial communication operation */
#define _0004_SAU_CH2_OUTPUT_ENABLE             (0x0004U) /* enables output by serial communication operation */
/* Serial output enable/stop of channel 0 (SOEm0) */
#define _0000_SAU_CH0_OUTPUT_DISABLE            (0x0000U) /* stops output by serial communication operation */
#define _0001_SAU_CH0_OUTPUT_ENABLE             (0x0001U) /* enables output by serial communication operation */

/*
    Serial output register m (SOm) 
*/
/* Serial clock output of channel 0 (CKOm0) */
#define _0000_SAU_CH0_CLOCK_OUTPUT_0            (0x0000U) /* serial clock output value is 0 */
#define _0100_SAU_CH0_CLOCK_OUTPUT_1            (0x0100U) /* serial clock output value is 1 */
/* Serial data output of channel 2 (SOm2) */
#define _0000_SAU_CH2_DATA_OUTPUT_0             (0x0000U) /* serial data output value is 0 */
#define _0004_SAU_CH2_DATA_OUTPUT_1             (0x0004U) /* serial data output value is 1 */
/* Serial data output of channel 0 (SOm0) */
#define _0000_SAU_CH0_DATA_OUTPUT_0             (0x0000U) /* serial data output value is 0 */
#define _0001_SAU_CH0_DATA_OUTPUT_1             (0x0001U) /* serial data output value is 1 */

/*
    Serial output level register m (SOLm) 
*/
/* Selects inversion of the level of the transmit data of channel n in UART mode (SOLm2) */
#define _0000_SAU_CHANNEL2_NORMAL               (0x0000U) /* communication data is output as is */
#define _0004_SAU_CHANNEL2_INVERTED             (0x0004U) /* communication data is inverted and output */
/* Selects inversion of the level of the transmit data of channel n in UART mode (SOLm0) */
#define _0000_SAU_CHANNEL0_NORMAL               (0x0000U) /* communication data is output as is */
#define _0001_SAU_CHANNEL0_INVERTED             (0x0001U) /* communication data is inverted and output */

/*
    Serial standby control register m (SSCm) 
*/
/* Selection of whether to enable or disable the generation of communication error interrupts in the
SNOOZE mode (SSECm) */
#define _0000_SAU_INTSRE0_ENABLE                (0x0000U) /* enable the generation of error interrupts (INTSRE0) */
#define _0002_SAU_INTSRE0_DISABLE               (0x0002U) /* disable the generation of error interrupts (INTSRE0) */
/* Setting of the SNOOZE mode (SWCm) */
#define _0000_SAU_CH0_SNOOZE_OFF                (0x0000U) /* do not use the SNOOZE mode function */
#define _0001_SAU_CH0_SNOOZE_ON                 (0x0001U) /* use the SNOOZE mode function */

/*
    Input switch control register (ISC) 
*/
/* Channel 0 SSI00 input setting in CSI communication and slave mode (SSIE00) */
#define _00_SAU_SSI00_UNUSED                    (0x00U) /* disables SSI00 pin input */
#define _80_SAU_SSI00_USED                      (0x80U) /* enables SSI00 pin input */

/*
    Noise filter enable register 0 (NFEN0) 
*/
/* Use of noise filter of RxD1 pin (SNFEN10) */
#define _00_SAU_RXD1_FILTER_OFF                 (0x00U) /* noise filter off */
#define _04_SAU_RXD1_FILTER_ON                  (0x04U) /* noise filter on */
/* Use of noise filter of RxD0 pin (SNFEN00) */
#define _00_SAU_RXD0_FILTER_OFF                 (0x00U) /* noise filter off */
#define _01_SAU_RXD0_FILTER_ON                  (0x01U) /* noise filter on */


/* SAU used flag */
#define _00_SAU_IIC_MASTER_FLAG_CLEAR       (0x00U)
#define _01_SAU_IIC_SEND_FLAG               (0x01U)
#define _02_SAU_IIC_RECEIVE_FLAG            (0x02U)
#define _04_SAU_IIC_SENDED_ADDRESS_FLAG     (0x04U)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _5C00_SAU0_CH0_BAUDRATE_DIVISOR         (0x5C00U) /* transfer clock set by dividing the operating clock */
#define _0000_SAU0_CH1_BAUDRATE_DIVISOR         (0x0000U) /* transfer clock set by dividing the operating clock */
#define _0020_SMR00_DEFAULT_VALUE               (0x0020U) /* SMR00 default value */
#define _0020_SMR01_DEFAULT_VALUE               (0x0020U) /* SMR01 default value */
#define _0004_SCR00_DEFAULT_VALUE               (0x0004U) /* SCR00 default value */
#define _0004_SCR01_DEFAULT_VALUE               (0x0004U) /* SCR01 default value */
#define _0E0A_SO0_DEFAULT_VALUE                 (0x0E0AU) /* SO0 default value */
#define IIC_WAITTIME                        (10U) /* change the waiting time according to the system */
#define _9A00_SAU0_CH0_BAUDRATE_DIVISOR         (0x9A00U) /* transfer clock set by dividing the operating clock */
#define _9A00_SAU0_CH1_BAUDRATE_DIVISOR         (0x9A00U) /* transfer clock set by dividing the operating clock */


/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_SAU0_Create(void);
void R_UART0_Create(void);
void R_UART0_Start(void);
void R_UART0_Stop(void);
MD_STATUS R_UART0_Send(uint8_t * const tx_buf, uint16_t tx_num);
MD_STATUS R_UART0_Receive(uint8_t * const rx_buf, uint16_t rx_num);
static void r_uart0_callback_receiveend(void);
static void r_uart0_callback_sendend(void);
static void r_uart0_callback_error(uint8_t err_type);
static void r_uart0_callback_softwareoverrun(uint16_t rx_data);
void UartSendData(u8 tdata);
void UartSendString(char *ptdata);
void UartSendLongData(u16 tdata,u8 base);



#endif

