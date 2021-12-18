/*
 * mainApp.c
 *
 *  Created on: Sep 8, 2017
 *      Author: dkhairnar
 */

#include "mainApp.h"
#include "sx1276_7_8.h"
#include "usb_device.h"
#include "usbd_cdc_if.h"
#define printUSB(x) CDC_Transmit_FS((uint8_t*)x,strlen((char*)x))

char strBuf[64];
u16 SysTime;
u16 time2_count;
u16 key1_time_count;
u16 key2_time_count;
u8 rf_rx_packet_length;

u8 mode;//lora--1/FSK--0
u8 Freq_Sel;//
u8 Power_Sel;//
u8 Lora_Rate_Sel;//
u8 BandWide_Sel;//

u8 Fsk_Rate_Sel;//

u8 key1_count;
/*key1_count = 0----------->lora master
key1_count = 1----------->lora slaver
key1_count = 2----------->FSK TX test
key1_count = 3----------->FSK RX test
*/
u8 time_flag;
/*{
bit0 time_1s;
bit1 time_2s;
bit2 time_50ms;
bit3 ;
bit4 ;
bit5 ;
bit6 ;
bit7 ;
}*/
u8	operation_flag;
/*typedef struct
{
	uchar	:RxPacketReceived-0;
	uchar	:
	uchar	:
	uchar	:
	uchar	:
	uchar	:key2_down;
	uchar	:key1_down;
	uchar	;
} operation_flag;*/
u8 key_flag;
/*{
	uchar	:key1_shot_down;
	uchar	:key1_long_down;
	uchar	:key2_short_down;
	uchar	:key2_long_down
	uchar	:
	uchar	:;
	uchar	:;
	uchar	;
}*/

void mainApp()
{
	u16 i=0;//,j,k=0,g;

	SysTime = 0;
	operation_flag = 0x00;
	key1_count = 0x00;
	mode = 0x01;//lora mode
	Freq_Sel = 0x00;//433M
	Power_Sel = 0x00;//
	Lora_Rate_Sel = 0x06;//
	BandWide_Sel = 0x07;
	Fsk_Rate_Sel = 0x00;

	RED_LED_L();
	HAL_Delay(500);
	RED_LED_H();

	HAL_GPIO_WritePin(Reset_GPIO_Port,Reset_Pin,GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(Reset_GPIO_Port,Reset_Pin,GPIO_PIN_SET);

	sx1276_7_8_Config();//
	sx1276_7_8_LoRaEntryRx();


	while (1)
	{
		key1_count = 1;
		switch(key1_count)
		{
			case 0://lora master Tx

				//if(time_flag & 0x02)//2s time
				{
				//	time_flag &= 0xfd;
					sprintf((char*)sx1276_7_8Data,"Counter From Transmitter : %d\n",i++);
					printUSB(sx1276_7_8Data);
					RED_LED_H();
					sx1276_7_8_LoRaEntryTx();
					sx1276_7_8_LoRaTxPacket();
					RED_LED_L();
					//sx1276_7_8_LoRaEntryRx();
				}
//				if(sx1276_7_8_LoRaRxPacket())
//				{
//
//					HAL_Delay(100);
//
//				}
				HAL_Delay(1000);

			break;
			case 1://lora slaver Rx

				if(sx1276_7_8_LoRaRxPacket())
				{
					sprintf(strBuf,"Receive Data %s\n",(char*)RxData);
					printUSB(strBuf);
					RED_LED_H();
					HAL_Delay(500);
//					sx1276_7_8_LoRaEntryTx();
//					sx1276_7_8_LoRaTxPacket();
					RED_LED_L();
//					sx1276_7_8_LoRaEntryRx();

				}


			break;
			case 2:


			break;
			case 3:


			break;
			default:

			break;
		}
	}
}
