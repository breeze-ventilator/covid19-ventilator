#ifndef SENSORS_H
#define SENSORS_H

class OxygenPressureSensor {
  public:
	  OxygenPressureSensor();
    
  private:
	  int mI2cAddress;
    int moffset;
    int mscale;
	  uint8_t crc8(const uint8_t data, uint8_t crc);
};

#endif