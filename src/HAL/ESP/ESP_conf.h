/*
 * ESP_conf.h
 *
 *  Created on: Jan 21, 2023
 *      Author: Mohammed Ramadan
 */

#ifndef HAL_ESP_ESP_CONF_H_
#define HAL_ESP_ESP_CONF_H_


/*select type of UART
 **Options :
 *UART1
 *UART2
 *UART6
 **/
#define UART_TYPE  USART1

/*define recieving timout for each command that if it exceeded it means no more data*/
/*It varies depending on the router and server and also Clock freq, you'll need to try it*/
#define ECHO_TIMEOUT		100
#define MODE_TIMEOUT		150
#define ROUTER_TIMEOUT		35000
#define SERVER_TIMEOUT		50000
#define PREREQUEST_TIMEOUT	200
#define REQUEST_TIMEOUT		50000

#endif /* HAL_ESP_ESP_CONF_H_ */
