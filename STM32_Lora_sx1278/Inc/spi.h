#ifndef __DK_SPI_h__
#define __DK_SPI_h__

#include "main.h"
#include "stm32f1xx_hal.h"
#include "My_type.h"

#define NOP()                _asm("nop")

//#define nSEL_H() 					NOP()//	PA_ODR |= 0x08//PA3
//#define nSEL_L() 					NOP()//	PA_ODR &= 0xf7
//#define SCK_H()						NOP()//	PC_ODR |= 0x20//PC5
//#define SCK_L()						NOP()//	PC_ODR &= 0xdf
//#define SDI_H()						NOP()//	PC_ODR |= 0x40//PC6
//#define SDI_L()						NOP()//	PC_ODR &= 0xbf
//#define SDN_H()						NOP()//	PC_ODR |= 0x08//PC3
//#define SDN_L()						NOP()//	PC_ODR &= 0xf7
//#define Get_SDO()					NOP()//	(PC_IDR & 0x80) == 0x80//PC7
#define NSS_H()						HAL_GPIO_WritePin(SPI_NSS_GPIO_Port,SPI_NSS_Pin,GPIO_PIN_SET)
#define NSS_L()						HAL_GPIO_WritePin(SPI_NSS_GPIO_Port,SPI_NSS_Pin,GPIO_PIN_RESET)
#define Get_NIRQ()					HAL_GPIO_ReadPin(nIrq_GPIO_Port,nIrq_Pin)//(PD_IDR & 0x04) == 0x04//PD2

void SPICmd8bit(u8 WrPara);
u8 SPIRead(u8 adr);
u8 SPIRead8bit(void);
void SPIWrite(u8 adr, u8 WrPara);
void SPIBurstRead(u8 adr, u8 *ptr, u8 length);
void BurstWrite(u8 adr, const u8 *ptr, u8 length);

extern SPI_HandleTypeDef hspi1;
#endif







