#include <Arduino.h>
#include <Wire.h>
#include "../lib/PCF8575_Lib.hpp"

PCF8575_Lib gpio_exp;

uint8_t portStatus;

void IRAM_ATTR interruptServiceRoutine()
{
  // Handle interrupt
  portStatus = gpio_exp.read_input(PCF8575_I2C_ADDR, 0x00);
  // Update ports variables

}

void setup()
{
  Serial.begin(115200);
  gpio_exp.begin(PCF8575_I2C_ADDR, &Wire);
  attachInterrupt(10, interruptServiceRoutine, FALLING);
}

void loop()
{

}
