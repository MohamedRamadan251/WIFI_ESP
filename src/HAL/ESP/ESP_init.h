/*
 * ESP_init.h
 *
 *  Created on: Jan 21, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_ESP_ESP_INIT_H_
#define HAL_ESP_ESP_INIT_H_
#include "../../MCAL/UART/UART_interface.h"

/*define RouteInfo*/
typedef struct
{
	u8 Name [50]  ;
	u8 Pass [50]  ;
}HESP_RouterInfo_t;

/*define ServerInfo*/
typedef struct
{
	u8 Url         [100] ;
	u8 LengthOfUrl [3  ] ;
	u8 IP          [50 ] ;
	u8 Port        [5  ] ;
}HESP_ServerInfo_t;

/**
	Function Name        : HESP_voidEspInit
	Function Returns     : void
	Function Arguments   : USART_t *A_xUART_Type
	Function Description : initialize ESP
*/
void HESP_voidEspInit (USART_t *A_xUART_Type) ;

/**
	Function Name        : HESP_voidConnectToAccessPoint
	Function Returns     : void
	Function Arguments   : USART_t *A_xUART_Type
	Function Description : connect to access point by sending it's name and password
*/
void HESP_voidConnectToAccessPoint (USART_t *A_xUART_Type) ;

/**
	Function Name        : HESP_voidOpenServerConnection
	Function Returns     : void
	Function Arguments   : USART_t *A_xUART_Type
	Function Description : open server connection by sending it's IP and PORT
*/
void HESP_voidOpenServerConnection (USART_t *A_xUART_Type) ;

/**
	Function Name        : HESP_u8GetHttpRequest
	Function Returns     : u8
	Function Arguments   : USART_t *A_xUART_Type
	Function Description : Get value from file into sever
*/
u8 HESP_u8GetHttpRequest(USART_t *A_xUART_Type) ;

/**
	Function Name        : HESP_u8PostHttpRequest
	Function Returns     : void
	Function Arguments   : USART_t *A_xUART_Type , u8 *A_pu8PostedValue
	Function Description : write value at file into sever
*/
void HESP_u8PostHttpRequest(USART_t *A_xUART_Type , u8 *A_pu8PostedValue) ;

#endif /* HAL_ESP_ESP_INIT_H_ */
