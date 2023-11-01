/*
 * ESP_prog.c
 *
 *  Created on: Jan 21, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/UART/UART_interface.h"
#include "../../MCAL/STK/STK_int.h"

#include "ESP_private.h"
#include "ESP_conf.h"
#include "ESP_init.h"

extern USART_InitType         MUART_Init ;
extern USART_ClockInitTypeDef MUART_clock ;
extern HESP_RouterInfo_t      RouterInfo ;
extern HESP_ServerInfo_t      ServerInfoGet ;
extern HESP_ServerInfo_t      ServerInfoPost ;

/***********************************************************************************/
volatile u8 GP_u8recv_buffer_1[100];
static volatile u8 G_u8bufferIterator_1=0;
static volatile u8 G_u8DataAdd_1=0;
static volatile u8 G_u8DataEndAdd_1=0;

void UART1_Callback(void)
{
	GP_u8recv_buffer_1[G_u8bufferIterator_1] = MUART_u8ReadDataRegister(UART1);
	G_u8bufferIterator_1++;
	if(GP_u8recv_buffer_1[G_u8bufferIterator_1-1]==':'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-3]==','&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-4]=='D'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-5]=='P'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-6]=='I')
	{
	   G_u8DataAdd_1=G_u8bufferIterator_1;
	}
	if(GP_u8recv_buffer_1[G_u8bufferIterator_1-1]=='D'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-2]=='E'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-3]=='S'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-4]=='O'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-5]=='L'&&
	   GP_u8recv_buffer_1[G_u8bufferIterator_1-6]=='C')
	{
		G_u8DataEndAdd_1=G_u8bufferIterator_1-6;
		G_u8bufferIterator_1=0;
	}
}
/***********************************************************************************/
/***********************************************************************************/
volatile u8 GP_u8recv_buffer_2[100];
static volatile u8 G_u8bufferIterator_2=0;
static volatile u8 G_u8DataAdd_2=0;
static volatile u8 G_u8DataEndAdd_2=0;

void UART2_Callback(void)
{
	GP_u8recv_buffer_2[G_u8bufferIterator_2] = MUART_u8ReadDataRegister(UART2);
	G_u8bufferIterator_2++;
	if(GP_u8recv_buffer_2[G_u8bufferIterator_2-1]==':'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-3]==','&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-4]=='D'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-5]=='P'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-6]=='I')
	{
	   G_u8DataAdd_2=G_u8bufferIterator_2;
	}
	if(GP_u8recv_buffer_2[G_u8bufferIterator_2-1]=='D'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-2]=='E'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-3]=='S'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-4]=='O'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-5]=='L'&&
	   GP_u8recv_buffer_2[G_u8bufferIterator_2-6]=='C')
	{
		G_u8DataEndAdd_2=G_u8bufferIterator_2-6;
		G_u8bufferIterator_2=0;
	}
}
/***********************************************************************************/
/***********************************************************************************/
volatile u8 GP_u8recv_buffer_6[100];
static volatile u8 G_u8bufferIterator_6=0;
static volatile u8 G_u8DataAdd_6=0;
static volatile u8 G_u8DataEndAdd_6=0;

void UART6_Callback(void)
{
	GP_u8recv_buffer_6[G_u8bufferIterator_6] = MUART_u8ReadDataRegister(UART6);
	G_u8bufferIterator_6++;
	if(GP_u8recv_buffer_6[G_u8bufferIterator_6-1]==':'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-3]==','&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-4]=='D'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-5]=='P'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-6]=='I')
	{
	   G_u8DataAdd_6=G_u8bufferIterator_6;
	}
	if(GP_u8recv_buffer_6[G_u8bufferIterator_6-1]=='D'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-2]=='E'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-3]=='S'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-4]=='O'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-5]=='L'&&
	   GP_u8recv_buffer_6[G_u8bufferIterator_6-6]=='C')
	{
		G_u8DataEndAdd_6=G_u8bufferIterator_6-6;
		G_u8bufferIterator_6=0;
	}
}
/***********************************************************************************/
void HESP_voidEspInit (USART_t *A_xUART_Type)
{
	/*initialize systic timer*/
	MSTK_vInit () ;
	/*Inetializing UART and Enable it*/
	MUART_voidInit(&MUART_Init, &MUART_clock, A_xUART_Type);
	if (A_xUART_Type == UART1)
	{
		MUART1_voidSetCallBack(UART1_Callback) ;
	}
	else if (A_xUART_Type == UART2)
	{
		MUART2_voidSetCallBack(UART2_Callback) ;
	}
	else if (A_xUART_Type == UART6)
	{
		MUART6_voidSetCallBack(UART6_Callback) ;
	}
	MUART_RxIntSetStatus(A_xUART_Type , ENABLE) ;
	MUART_voidEnable(A_xUART_Type);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\r\n");
	MSTK_vSetBusyWait(5000);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"ATE0\r\n");
	MSTK_vSetBusyWait(5000);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"AT+CWMODE=1\r\n");
	MSTK_vSetBusyWait(5000);
}

void HESP_voidConnectToAccessPoint (USART_t *A_xUART_Type)
{
	MUART_voidTransmitString(A_xUART_Type,(u8*)"AT+CWJAP_CUR=\"");
	MUART_voidTransmitString(A_xUART_Type,RouterInfo.Name);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\",\"");
	MUART_voidTransmitString(A_xUART_Type,RouterInfo.Pass);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\"\r\n");
	MSTK_vSetBusyWait(10000000);
}

void HESP_voidOpenServerConnection(USART_t *A_xUART_Type)
{
	MUART_voidTransmitString(A_xUART_Type,(u8*)"AT+CIPSTART=\"");
	MUART_voidTransmitString(A_xUART_Type,(u8*)"TCP");
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\",\"");
	MUART_voidTransmitString(A_xUART_Type,ServerInfoGet.IP);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\",");
	MUART_voidTransmitString(A_xUART_Type,ServerInfoGet.Port);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\r\n");
	MSTK_vSetBusyWait(500000);
}

u8 HESP_u8GetHttpRequest(USART_t *A_xUART_Type)
{
	u8 L_u8DataReturnedFromUrl = 0 ;
	MUART_voidTransmitString(A_xUART_Type,(u8*)"AT+CIPSEND=");
	MUART_voidTransmitString(A_xUART_Type,ServerInfoGet.LengthOfUrl);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\r\n");
	MSTK_vSetBusyWait(500000);
	MUART_voidTransmitString(A_xUART_Type,ServerInfoGet.Url);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\r\n");
	MSTK_vSetBusyWait(500000);
	if (A_xUART_Type == UART1)
	{
		L_u8DataReturnedFromUrl = GP_u8recv_buffer_1[G_u8DataAdd_1] ;
	}
	else if (A_xUART_Type == UART2)
	{
		L_u8DataReturnedFromUrl = GP_u8recv_buffer_2[G_u8DataAdd_2] ;
	}
	else if (A_xUART_Type == UART6)
	{
		L_u8DataReturnedFromUrl = GP_u8recv_buffer_6[G_u8DataAdd_6] ;
	}
	return L_u8DataReturnedFromUrl ;
}

void HESP_u8PostHttpRequest(USART_t *A_xUART_Type , u8 *A_pu8PostedValue)
{
	MUART_voidTransmitString(A_xUART_Type,(u8*)"AT+CIPSEND=");
	MUART_voidTransmitString(A_xUART_Type,ServerInfoPost.LengthOfUrl);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\r\n");
	MSTK_vSetBusyWait(500000);
	MUART_voidTransmitString(A_xUART_Type,(u8*)"GET /script.php?statues=") ;
	MUART_voidTransmitString(A_xUART_Type,A_pu8PostedValue) ;
	MUART_voidTransmitString(A_xUART_Type,(u8*)" HTTP/1.1\r\nHost: ") ;
	MUART_voidTransmitString(A_xUART_Type,ServerInfoPost.Url) ;
	MUART_voidTransmitString(A_xUART_Type,(u8*)"\r\n\r\n") ;
}

