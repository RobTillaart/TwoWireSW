#pragma once
//
//    FILE: TwoWireSW.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.0.0
//    DATE: 2023-03-16
// PURPOSE: TwoWire interface wrapper around SoftwareWire
//     URL: https://github.com/RobTillaart/TwoWireSW
//     URL: https://github.com/Testato/SoftwareWire


#include "Arduino.h"
#include "Wire.h"
#include "SoftwareWire.h"


class TwoWireSW : public TwoWire
{
public:


  //////////////////////////////////////////////////
  //
  //  CONSTRUCTOR
  //
  TwoWireSW(uint8_t SCL, uint8_t SDA)
  {
    _wire = new SoftwareWire(SCL, SDA);
  };
  ~TwoWireSW(){};


  //////////////////////////////////////////////////
  //
  //  BEGIN
  //
  void begin()
  {
    _wire->begin();
  };
  void begin(uint8_t address)
  {
    _wire->begin(address);
  };
  void begin(int address)
  {
    _wire->begin(address);
  };
  void end()
  {
    _wire->end();
  };


  //////////////////////////////////////////////////
  //
  //  CLOCK
  //
  void setClock(uint32_t clock)
  {
    _wire->setClock(clock);
  };
  void setWireTimeout(uint32_t timeout = 25000, bool reset_with_timeout = false){};
  bool getWireTimeoutFlag(void){};
  void clearWireTimeoutFlag(void){};


  //////////////////////////////////////////////////
  //
  //  TRANSMISSION
  //
  void beginTransmission(uint8_t address)
  {
    _wire->beginTransmission(address);
  };
  void beginTransmission(int address)
  {
    _wire->beginTransmission(address);
  };
  uint8_t endTransmission(void)
  {
    return endTransmission(true);
  };
  uint8_t endTransmission(uint8_t sendStop)
  {
    _wire->endTransmission(sendStop);
  }


  //////////////////////////////////////////////////
  //
  //  REQUEST_FROM
  //
  uint8_t requestFrom(uint8_t address, uint8_t quantity, uint32_t iaddress, uint8_t isize, uint8_t sendStop)
  {
    return _wire->requestFrom(address, quantity, sendStop);
  };
  uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop)
  {
    return requestFrom(address, quantity, 0, 0, sendStop);
  };
  uint8_t requestFrom(uint8_t address, uint8_t quantity)
  {
    return requestFrom(address, quantity, 0, 0, true);
  };
  uint8_t requestFrom(int address, int quantity)
  {
    return requestFrom(address, quantity, 0, 0, true);
  };
  uint8_t requestFrom(int address, int quantity, int sendStop)
  {
    return requestFrom(address, quantity, 0, 0, sendStop);
  };


  //////////////////////////////////////////////////
  //
  //  STREAM INTERFACE
  //
  virtual size_t write(uint8_t data)
  {
    return _wire->write(data);
  };
  virtual size_t write(const uint8_t *data, size_t quantity)
  {
    return _wire->write(data, quantity);
  };
  virtual int available(void)
  {
    return _wire->available();
  };
  virtual int read(void)
  {
    return _wire->read();
  };
  virtual int peek(void)
  {
    return _wire->peek();
  };
  virtual void flush(void){};

  void onReceive(void (*function)(int n) ){};
  void onRequest(void (*function)(void) ){};

private:
  SoftwareWire *_wire;
};


//  -- END OF FILE --

