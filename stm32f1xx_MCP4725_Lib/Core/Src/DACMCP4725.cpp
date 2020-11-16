/*
 * DACMCP4725.cpp
 *
 *  Created on: Nov 15, 2020
 *      Author: arielarias
 */

#include "DACMCP4725.h"

DAC_MCP4725::DAC_MCP4725( I2C_HandleTypeDef * hi2c, uint8_t addr )
{
    // TODO Auto-generated constructor stub
    i2c = hi2c;
    address = addr << 1;

}

void DAC_MCP4725::setValue( uint16_t value, PlaceRegister_t place )
{
    uint8_t pData[3];

    if ( place == REG_DAC_EEPROM )
    {
        pData[0] = REG_DAC_EEPROM;
    }
    else
    {
        pData[0] = REG_DAC_TEMP;
    }
    pData[1] = value >> 4;       // Upper data bits (D11.D10.D9.D8.D7.D6.D5.D4)
    pData[2] = value << 4;        // Lower data bits (D3.D2.D1.D0.x.x.x.x)

    HAL_I2C_Master_Transmit( i2c, address, pData, 3, 500 );
}

uint16_t DAC_MCP4725::getValue( PlaceRegister_t place )
{
    uint8_t pData[5];
    uint16_t reg_temp;
    uint16_t reg_eeprom = 0;

    if ( place == REG_DAC_TEMP )
    {
        HAL_I2C_Master_Receive( i2c, address, pData, 5, 500 );
        reg_temp = pData[1] << 8;
        reg_temp |= pData[2];
        return reg_temp >>= 4;
    }
    else if ( place == REG_DAC_EEPROM )
    {
        HAL_I2C_Master_Receive( i2c, address, pData, 5, 500 );
        reg_eeprom = ( pData[3] & 0xf ) << 8;
        reg_eeprom |= pData[4];
        return reg_eeprom;
    }
    else
    {
        return 0;
    }
}

