#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_tpm.h"
#include "fsl_adc16.h"
#include "fsl_i2c.h"
#include "parse.h"

uint8_t g_master_buff[2U];
i2c_master_config_t masterConfig;
i2c_master_transfer_t masterXfer;

unsigned char LCD_screen_buffer[1024];
unsigned int Timer_counter = 0;
char LCD_line1[18], LCD_line2[18], LCD_line3[18],LCD_line4[18];

void LCD_send_Command(unsigned char* commands,unsigned int command_length ){

	g_master_buff[0] = 0x00;
	for (int x=0; x<command_length; x++){
		g_master_buff[1] = commands[x];
		masterXfer.data = g_master_buff;
		I2C_MasterTransferBlocking(I2C0, &masterXfer);
	}
	return;
}

void LCD_send_Data(unsigned char* data_, unsigned int data_lenght){

	g_master_buff[0] = 0x40;
	for (int x=0; x<data_lenght; x++){
		g_master_buff[1] = data_[x];
		masterXfer.data = g_master_buff;
		I2C_MasterTransferBlocking(I2C0, &masterXfer);
	}
	return;
}

void LCD_init(){

	memset(&masterXfer, 0, sizeof(masterXfer));
	masterXfer.slaveAddress = 0x3CU;
	masterXfer.direction = kI2C_Write;
	masterXfer.subaddress = 0;
	masterXfer.subaddressSize = 0;
	masterXfer.dataSize = 2U;
	masterXfer.flags = kI2C_TransferDefaultFlag;

	unsigned char init_sequence[27]={0xAE,0xD5,0x80,0xA8,63,0xD3,0x00,0x40,0x8D,
			0xD5,0x14,0x20,0x00,0xA1,0xC8,0xDA,0x12,0x81,0xCF,0xD9,0xF1,  0xDB,0x40,
			0xA4,0xA6,0x2E,0xAF};
	LCD_send_Command(init_sequence,27);
}

void LCD_print(){

	unsigned char start_screen[6]={0x22,0x00,0xFF,0x21,0x00,127};
	LCD_send_Command(start_screen,6);
	LCD_send_Data(LCD_screen_buffer,1024);
}

void LCD_print_text(){

	char buffer_letra[8];

	for(int y=0; y<18 ;y++)
	{
		LCD_parse(buffer_letra, LCD_line1[y]);
		for(int z=0; z<7 ;z++)
		{
			LCD_screen_buffer[129+ (7*y) +z] = buffer_letra[0+z];
		}
	}

	for(int y=0; y<18 ;y++)
	{
		LCD_parse(buffer_letra, LCD_line2[y]);
		for(int z=0; z<7 ;z++)
		{
			LCD_screen_buffer[385+ (7*y) +z] = buffer_letra[0+z];
		}
	}
	for(int y=0; y<18 ;y++)
		{
			LCD_parse(buffer_letra, LCD_line3[y]);
			for(int z=0; z<7 ;z++)
			{
				LCD_screen_buffer[641+ (7*y) +z] = buffer_letra[0+z];
			}
		}

		for(int y=0; y<18 ;y++)
		{
			LCD_parse(buffer_letra, LCD_line4[y]);
			for(int z=0; z<7 ;z++)
			{
				LCD_screen_buffer[897+ (7*y) +z] = buffer_letra[0+z];
			}
		}
	LCD_print();
}

void LCD_clear(){
	memset(&LCD_screen_buffer, 0, 1024);
	LCD_print();
}

int main(){
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    BOARD_InitDebugConsole();
#endif
    //ADC pin E20
    adc16_config_t adc16ConfigStruct;
	adc16_channel_config_t adc16ChannelConfigStruct;
	ADC16_GetDefaultConfig(&adc16ConfigStruct);
	adc16ConfigStruct.resolution = kADC16_ResolutionSE8Bit;
	ADC16_Init(ADC0, &adc16ConfigStruct);
	ADC16_EnableHardwareTrigger(ADC0, false);
	ADC16_DoAutoCalibration(ADC0);
	adc16ChannelConfigStruct.channelNumber = 0;					//Para escoger el canal 0, puerto E20
	adc16ChannelConfigStruct.enableInterruptOnConversionCompleted = false;
	adc16ChannelConfigStruct.enableDifferentialConversion = false;
	//TIMER
	tpm_config_t tpmInfo;
	CLOCK_SetTpmClock(1U);
	TPM_GetDefaultConfig(&tpmInfo);
	TPM_Init(TPM2, &tpmInfo);
	TPM_SetTimerPeriod(TPM2, 48000);//1ms * 1000 = 1s
	TPM_EnableInterrupts(TPM2, kTPM_TimeOverflowInterruptEnable);
	EnableIRQ(TPM2_IRQn);
	TPM_StartTimer(TPM2,kTPM_SystemClock);
    //I2C SCL B2 SDA B3
    I2C_MasterGetDefaultConfig(&masterConfig);
	masterConfig.baudRate_Bps = 400000U;
	I2C_MasterInit(I2C0, &masterConfig, CLOCK_GetFreq(I2C0_CLK_SRC));		//I2C0
    LCD_init();
    LCD_clear();

    int valor = 0, boton = 0, b = 0;
    int hora = 0, min = 0, seg = 0;
    sprintf(LCD_line1,"Nezly G. Ya-ez");
    LCD_print_text();

    while(1){
    	ADC16_SetChannelConfig(ADC0, 0, &adc16ChannelConfigStruct);
    	while (0U == (kADC16_ChannelConversionDoneFlag & ADC16_GetChannelStatusFlags(ADC0, 0))){}
   		valor = ADC16_GetChannelConversionValue(ADC0, 0);

   		sprintf(LCD_line2,"Adc = %d", valor);
   		LCD_print_text();
   		boton = GPIO_ReadPinInput(GPIOC, 1);
   		b = ((boton == 1) ? 1 : 0);
   		sprintf(LCD_line3,"Boton = %d", b);
   		LCD_print_text();

   		if(Timer_counter >= 800){
   			seg++;
   			if(seg == 60){
   				seg = 0;
				min++;
				if(min == 60){
					min = 0;
					hora++;
					if(hora == 24){
						hora = 0;
						min = 0;
						seg = 0;
					}
				}
   			}
   			Timer_counter = 0;
   		}
   		sprintf(LCD_line4,"RELOJ %dh:%dm:%ds     ",hora,min,seg);
   		LCD_print_text();
    }
}

void TPM2_IRQHandler(void){
		TPM_ClearStatusFlags(TPM2, kTPM_TimeOverflowFlag);
		Timer_counter++;
}
