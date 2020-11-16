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
    REG_DAC_TEMP = 0x40,   // comando para escribir en el registro temporal
    REG_DAC_EEPROM = 0x60, // comando para escribir en la eeprom del dac
} PlaceRegister_t;

class DAC_MCP4725
{

private:

    I2C_HandleTypeDef *i2c;
    uint8_t address;

public:

    DAC_MCP4725( I2C_HandleTypeDef * hi2c, uint8_t addr );

    void setValue( uint16_t data, PlaceRegister_t place );
    // lee los registro del temporal o eeprom
    uint16_t getValue( PlaceRegister_t place );
   };

#endif /* SRC_DACMCP4725_H_ */
