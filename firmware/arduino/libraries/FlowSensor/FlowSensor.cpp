/*
  FlowSensor.cpp - Library for reading values from flowmeter Sensirion FlowSensor
  https://www.sensirion.com/en/flow-sensors/mass-flow-meters-for-high-precise-measurement-of-gases/low-pressure-drop-mass-flow-meter/
  Created by WeDo, Zuerich 20170616
  
  Released into the public domain.
*/

#include "FlowSensor.h"
#include <Wire.h>

//FlowSensor::FlowSensor(uint8_t i2cAddress)
FlowSensor::FlowSensor(int i2cAddress, int offset, float scale)
{
  //: mI2cAddress(i2cAddress)
  mI2cAddress = i2cAddress;
	moffset = offset;
	mscale = scale;
}

void FlowSensor::init()
{
  Wire.begin();
  delay(1000);
  Wire.beginTransmission(byte(mI2cAddress)); // transmit to device with I2C mI2cAddress
  Wire.beginTransmission(byte(mI2cAddress)); // transmit to device with I2C mI2cAddress
  Wire.write(byte(0x10));
  Wire.write(byte(0x00));
  Wire.endTransmission();
  
  delay(5);
  
}
 
float FlowSensor::getvalue(int *errorType)
{
  *errorType = NO_ERROR;
	Wire.requestFrom(mI2cAddress, 3); // read 3 bytes from device with address 0x40
	if (3 <= Wire.available()) { // if 3 bytes were received
		uint16_t a = Wire.read(); // first received byte stored here. The variable "uint16_t" can hold 2 bytes, this will be relevant later
		uint8_t b = Wire.read(); // second received byte stored here
		uint8_t crc = Wire.read(); // crc value stored here
	}
	else {
		*errorType = SENSOR_DEAD_OR_NEEDS_RESET_ERROR; // should restart
		float Flow = 0;
		return Flow;
	}
  
	
	uint8_t mycrc = 0xFF; // initialize crc variable
  mycrc = crc8(a, mycrc); // let first byte through CRC calculation
  mycrc = crc8(b, mycrc); // and the second byte too
	
	// Error check
	if (mycrc != crc) { // check if the calculated and the received CRC byte matches

		*errorType = NOISY_READING_ERROR; // noisy reading
		float Flow = 0;
		return Flow;
  }
  a = (a << 8) | b; // combine the two received bytes to a 16bit integer value
  // a >>= 2; // remove the two least significant bits
  //float Flow = (float)a;
  unsigned int Flow = a;
  float Flow = ((float)result - moffset) / mscale; // numbers given upon initilization
  return Flow;
}

// cyclic redundancy check
uint8_t FlowSensor::crc8(const uint8_t data, uint8_t crc)
{
	crc ^= data;
	for ( uint8_t i = 8; i; --i ) {
		crc = ( crc & 0x80 )
		? (crc << 1) ^ 0x31
		: (crc << 1);
	}
  return crc;
}