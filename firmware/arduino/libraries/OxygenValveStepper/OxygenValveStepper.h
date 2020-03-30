#ifndef SENSORS_H
#define SENSORS_H

class OxygenValveStepper {
  public:
	  OxygenValveStepper(int i2cAddress, int offset, float scale);
    int begin(int maxWaitTime);
    float getvalue(int *errorType);
    
  private:
	  int mI2cAddress;
    int moffset;
    int mscale;
	  uint8_t crc8(const uint8_t data, uint8_t crc);
};

#endif