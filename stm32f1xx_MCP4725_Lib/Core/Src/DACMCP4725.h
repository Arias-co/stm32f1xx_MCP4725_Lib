/*
 * DACMCP4725.h
 *
 *  Created on: Nov 15, 2020
 *      Author: arielarias
 */

#ifndef SRC_DACMCP4725_H_
#define SRC_DACMCP4725_H_

#include "stm32f1xx_hal.h"



typedef enum
{
    REG_DAC = 0x40,
    REG_DAC_EEPROM = 0x60,
} PlaceRegister_t;

class DAC_MCP4725
{

private:

    I2C_HandleTypeDef *i2c;
    uint8_t address;

public:

    DAC_MCP4725( I2C_HandleTypeDef * hi2c, uint8_t addr );

    void sendData( uint16_t data, PlaceRegister_t place );
    // lee los registro del dac
    uint16_t read( void );
    // lee la eeprom
    uint16_t readEEPROM( void );
};

#endif /* SRC_DACMCP4725_H_ */
