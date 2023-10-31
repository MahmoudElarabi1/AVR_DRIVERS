/*
 * main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "main_h.h"

void ACT_SPI(u8 Copy_u8Recrived)
{
	if(Copy_u8Recrived == 70)
	{
		Dio_FlipChannel(PA_4);
	}
}

int main() {
	Port_Init(pins);
	GI_voidEnable();

	SPI_voidInit();

	while (1)
	{
		Dio_WriteChannel(PB_4, 1);
		_delay_ms(1);
		Dio_WriteChannel(PB_4, 0);
		SPI_voidTransmit_Async(2, ACT_SPI);
		_delay_ms(200);
	}
	return 0;
}
