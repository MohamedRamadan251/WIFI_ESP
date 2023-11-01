
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/STK/STK_int.h"
#include "HAL/ESP/ESP_init.h"
#include "HAL/LED/LED_int.h"
int main()
{
	u8 x = 0 ;
	HLED_voidLedInitial(LED1_ID) ;
	HESP_voidEspInit (UART1) ;

	HESP_voidConnectToAccessPoint (UART1) ;


	while (1)
	{
		HESP_voidOpenServerConnection (UART1) ;
		x = HESP_u8GetHttpRequest (UART1) ;
		if (x == '1')
		{
			HLED_voidLedOn(LED1_ID) ;
		}
		else
		{
			HLED_voidLedOff(LED1_ID) ;
		}

	}
}
