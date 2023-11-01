/*
 * ESP_conf.c
 *
 *  Created on: Jan 22, 2023
 *      Author: Mohammed Ramadan
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#include "ESP_private.h"
#include "ESP_conf.h"
#include "ESP_init.h"

/*router information*/
HESP_RouterInfo_t RouterInfo =
{
		.Name = "Samsong"  ,
		.Pass = "Mohamed123@#$"
};

/*server information for get request*/
HESP_ServerInfo_t ServerInfoGet =
{
		.Url         = "GET http://mohammedramadanshaheen.freevar.com/statues.txt",
		.LengthOfUrl = "59"                                                       ,
		.IP          = "172.107.162.12"                                           ,
		.Port        = "80"
};

/*server information for get request*/
HESP_ServerInfo_t ServerInfoPost =
{
		.Url         = "mohammedramadanshaheen.freevar.com",
		.LengthOfUrl = "80"                                ,
		.IP          = "172.107.162.12"                    ,
		.Port        = "80"
};
