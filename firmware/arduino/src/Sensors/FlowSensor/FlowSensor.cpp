/*
  FlowSensor.cpp - Library for reading values from flowmeter Sensirion FlowSensor
  https://www.sensirion.com/en/flow-sensors/mass-flow-meters-for-high-precise-measurement-of-gases/low-pressure-drop-mass-flow-meter/
  Created by WeDo, Zuerich 20170616
  
  Released into the public domain.
*/

#include "FlowSensor.h"
#include <Wire.h>
#include "Arduino.h"
//FlowSensor::FlowSensor(uint8_t i2cAddress)
FlowSensor::FlowSensor(int i2cAddress, uint32_t offset, float scale)
{
  _i2cAddress = i2cAddress;
	_offset = offset;
	_scale = scale;
}

void FlowSensor::init()
{
  Wire.begin();
  delay(1000);
  Wire.beginTransmission(byte(_i2cAddress)); // transmit to device with I2C _i2cAddress
  Wire.write(byte(0x10));
  Wire.write(byte(0x00));
  Wire.endTransmission();
  
  delay(50);
  
}
 
float FlowSensor::read(int *errorType)
{ 
  uint16_t reading = 0;
  uint8_t crc;
  float flow;
  *errorType = NO_ERROR;

  // Wire.beginTransmission(byte(_i2cAddress)); // transmit to device with I2C _i2cAddress
  // Wire.write(byte(0x10));
  // Wire.write(byte(0x00));
  // Wire.endTransmission();
  // delay(2);

	Wire.requestFrom(_i2cAddress, 3); // read 3 bytes
	
  if (3 <= Wire.available()) { // if 3 bytes were received
    reading = Wire.read(); // receive high byte and shift to be high 8 bits
    reading = reading << 8;  
    reading |= Wire.read(); // receive low byte as lower 8 bits
    crc = Wire.read(); // cyclic redundancy check
  }  
	else {
		*errorType = SENSOR_DEAD_OR_NEEDS_RESET_ERROR; // should restart
		flow = -1;
		return flow;
	}
  // offset = 32768; we read 32704-32720
  // print float of each
  flow = ((float)reading - _offset) / _scale; // numbers given upon initilization
  Serial.println(flow);

  return flow;

    
	// // uint8_t mycrc = 0xFF; // initialize crc variable
  // // mycrc = crc8(a, mycrc); // let first byte through CRC calculation
  // // mycrc = crc8(b, mycrc); // and the second byte too

	// // Error check
	// // if (mycrc != crc) { // check if the calculated and the received CRC byte matches

	// // 	*errorType = NOISY_READING_ERROR; // noisy reading
	// //   flow = -2;
	// // 	return flow;
  // // }
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