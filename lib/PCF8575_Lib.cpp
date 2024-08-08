#include "PCF8575_Lib.hpp"

PCF8575_Lib::PCF8575_Lib() {
    // Constructor implementation
}

/*!
 * @brief Starts I2C connection
 * @param addr I2C address of device
 * @param wire The TwoWire master, defaults to &Wire
 * @return Returns true if successful
 */
bool PCF8575_Lib::begin(uint8_t addr, TwoWire *wire)
{
    if (i2c_dev)
    {
        delete i2c_dev; // remove old inteface
    }
    i2c_dev = new Adafruit_I2CDevice(addr, wire);

    /* Try to instantiate the I2C device. */
    if (!i2c_dev->begin(false))
    {
        return false;
    }

    // softReset();

    // uint8_t device_prod_id;
    // device_prod_id = getDeviceProductId();

    // uint8_t revision_id;
    // revision_id = getDeviceRevisionId();

    return true;
}

uint8_t PCF8575_Lib::read_i2c_register(uint8_t i2c_dev_addr, uint8_t i2c_reg_addr)
{
    // This function writes data to the buffer.
    // Wire.write(uint8_t);
    // Or specify qty of bytes to send with second param
    // Wire.write(const uint8_t *, size_t);

    // This function will finish the communication and release all the allocated resources.
    // After calling end you need to use begin again in order to initialize the I2C driver again.
    // wire.end();
    
    // After writing to the buffer using i2c write, use the function endTransmission to send the message to the slave device address defined on the beginTransmission function.
    // uint8_t endTransmission(bool sendStop);
    // sendStop enables (true) or disables (false) the stop signal (only used in master mode).
    // Calling the this function without sendStop is equivalent to sendStop = true.
    // uint8_t endTransmission(void);

    Wire.beginTransmission(i2c_dev_addr);
    Wire.write(i2c_reg_addr);
    Wire.endTransmission();

    // Request byte from slave
    if (Wire.requestFrom(i2c_dev_addr, 1U, 1U) > 0)
        return (Wire.read());
    else
        return (0x0);
}

uint8_t PCF8575_Lib::write_i2c_register(uint8_t i2c_dev_addr, uint8_t i2c_reg_addr, uint8_t data)
{
    Wire.beginTransmission(i2c_dev_addr);
    Wire.write(i2c_reg_addr);
    Wire.write(data);

    return Wire.endTransmission(true);
}

uint8_t PCF8575_Lib::read_input(uint8_t i2c_dev_addr, uint8_t input_port)
{
	uint16_t status = 0x0;
	uint8_t reg_to_read = 0x41;

	status = read_i2c_register(i2c_dev_addr, reg_to_read);
	status = (status & ~(0 << input_port)) >> input_port;

	// status = (status & (1 << input_port)) >> input_port;
	return (status);
}