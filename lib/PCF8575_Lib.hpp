#ifndef PCF8575_LIB_H
# define PCF8575_LIB_H

#include <Arduino.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_BusIO_Register.h>
#include <Wire.h>

/************************************** Macros *******************************************/

/** I2C address of the XENSIV™ PASCO2 sensor */
#define PCF8575_I2C_ADDR              (0x20U)

typedef struct s_port_status
{
	uint8_t port0;
	uint8_t port1;
	uint8_t port2;
	uint8_t port3;
	uint8_t port4;
	uint8_t port5;
	uint8_t port6;
	uint8_t port7;
	uint8_t port8;
	uint8_t port9;
	uint8_t port10;
	uint8_t port11;
	uint8_t port12;
	uint8_t port13;
	uint8_t port14;
	uint8_t port15;
} t_port_status;

class PCF8575_Lib
{
public:
	PCF8575_Lib();
	bool PCF8575_Lib::begin(uint8_t addr, TwoWire *wire);
	uint8_t read_input(uint8_t i2c_dev_addr, uint8_t input_port);
	~PCF8575_Lib();
private:
	uint8_t read_i2c_register(uint8_t i2c_dev_addr, uint8_t i2c_reg_addr);
	uint8_t write_i2c_register(uint8_t i2c_dev_addr, uint8_t i2c_reg_addr, uint8_t data);
	Adafruit_I2CDevice *i2c_dev = NULL; // < Pointer to I2c bus interface
};

PCF8575_Lib::PCF8575_Lib(/* args */)
{
}

PCF8575_Lib::~PCF8575_Lib()
{
}

#endif
