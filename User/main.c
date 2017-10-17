#include "stm32f4xx.h"                  // Device header
#include "main.h"
#include <Lab3_Test.h>

uint32_t i;
uint8_t var;
uint32_t answer = 0;
uint16_t counter = 0;

uint8_t Lab3_Test_ini(char *name);
uint32_t while_Test(uint8_t *decision);
uint8_t decision[3];

//uint32_t read_flag(void);
void LEDPinsInit (void);
void ButtonPinInit (void);
void delay (void);

int main(void)
{
	LEDPinsInit();
	ButtonPinInit();
	
	var = Lab3_Test_ini("Petrunin");
	
	while(1)
	{		
		while_Test(decision);
		
		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 0)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_13);
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			delay();
			counter++;
		}
		
		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 1)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);	
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			delay();
			counter++;
		}
			
		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 2)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);	
			GPIO_SetBits(GPIOD, GPIO_Pin_15);	
			delay();
			counter++;
		}	
		
		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 3)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_15);	
			GPIO_SetBits(GPIOD, GPIO_Pin_12);	
			delay();
			counter++;			
		}

		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 4)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);	
			GPIO_SetBits(GPIOD, GPIO_Pin_13);	
			delay();
			counter++;			
		}

		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 5)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_13);	
			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			delay();
			counter++;			
		}

		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 6)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_15);	
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			delay();
			counter++;			
		}

		if ( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0) == 1  &&  counter == 7)
		{
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);	
			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			delay();
			counter = 0;			
		}
				
		//answer = read_flag();					
	}
}

void LEDPinsInit (void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitTypeDef PORTD_init_struct;
	
	PORTD_init_struct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;;
	PORTD_init_struct.GPIO_Mode = GPIO_Mode_OUT;
	PORTD_init_struct.GPIO_Speed = GPIO_Speed_2MHz;
	PORTD_init_struct.GPIO_OType = GPIO_OType_PP;
	PORTD_init_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &PORTD_init_struct);
}

void ButtonPinInit (void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef PORTA_init_struct;
	
	PORTA_init_struct.GPIO_Pin = GPIO_Pin_0 ;;
	PORTA_init_struct.GPIO_Mode = GPIO_Mode_IN;
	PORTA_init_struct.GPIO_Speed = GPIO_Speed_2MHz;
	PORTA_init_struct.GPIO_OType = GPIO_OType_PP;
	PORTA_init_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &PORTA_init_struct);
}

void delay (void)
{
	for (i=0;i<1000000;i++) {}
}

