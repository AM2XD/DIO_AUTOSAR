

/*
 * Dio.c
 *
 *  Created on: Oct 7, 2023
 *      Author: eme
 */

#ifndef DIO_C_
#define DIO_C_

#include "Std_Types.h"
#include "tm4c123gh6pm.h"

#define PORT_E GPIO_PORTE_DATA_R


Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId);


void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);



Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId );


void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);



#endif /* DIO_C_ */
