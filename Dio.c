/*
 * Dio.h
 *
 *  Created on: Oct 7, 2023
 *      Author: eme
 */
#include "Dio.h"


/*array of register data*/
unsigned long * data_reg[] = {(unsigned long*)0x400043FC ,/*GPIO_PORTA_DATA_R,*/
                              (unsigned long*)0x400053FC ,/*GPIO_PORTB_DATA_R,*/
                              (unsigned long*)0x400063FC ,/*GPIO_PORTC_DATA_R,*/
                              (unsigned long*)0x400073FC ,/*GPIO_PORTD_DATA_R,*/
                              (unsigned long*)0x400243FC ,/*GPIO_PORTE_DATA_R,*/
                              (unsigned long*)0x400253FC /*GPIO_PORTF_DATA_R}*/};

/*The Dio_ReadChannel function shall return the value of the specified DIO channel.*/
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId)
{
    Dio_LevelType ReadValue ;

    /*get port id from channel id */
    uint8_t port_id = ChannelId / 8 ;

    /*get port from port id */
    ReadValue = (*data_reg[port_id])>>ChannelId & (1U);

    return ReadValue;
}

void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    /*get port id from channel id */
    uint8_t port_id = ChannelId / 8 ;
    (*data_reg[port_id]) |= (Level << ChannelId);
}

/*The Dio_ReadPort function shall return the level of all channels of that port.*/
Dio_PortLevelType Dio_ReadPort ( Dio_PortType PortId )
{
    Dio_PortLevelType ReadValue ;

    /*get port from port id */
    ReadValue = (*data_reg[PortId]);

    return ReadValue;
}

void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    /*get port id from channel id */
    uint8_t port_id = ChannelId / 8 ;
    (*data_reg[port_id]) = Level;
}
