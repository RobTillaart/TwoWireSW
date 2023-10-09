#pragma once
//
//    FILE: TwoWireSW.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.0.1
//    DATE: 2023-03-16
// PURPOSE: TwoWire interface wrapper around SoftwareWire
//     URL: https://github.com/RobTillaart/TwoWireSW
//     URL: https://github.com/Testato/SoftwareWire


//  NEED TO MAKE ALL TWOWIRE VIRTUAL
//  SEE  - https://github.com/RobTillaart/TwoWireSW/issues/1


#include "Arduino.h"
#include "Wire.h"
#include "SoftwareWire.h"


#define TWOWIRESW_LIB_VERSION        (F("0.0.1 not working"))


class TwoWireSW : public TwoWire
{
public:


  //////////////////////////////////////////////////
  //
  //  CONSTRUCTOR
  //
  TwoWireSW(SoftwareWire *sw) : TwoWire()
  {
    _wire = sw;
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
  bool getWireTimeoutFlag(void){ return true; };
  void clearWireTimeoutFlag(void){};


  //////////////////////////////////////////////////
  //
  //  TRANSMISSION
  //


  void beginTransmission(uint8_t address)
  {
    _wire->beginTransmission(address);
    //  Serial.print("ADDR1:");
    //  Serial.print(address);
  };
  using TwoWire::beginTransmission;
  void beginTransmission(int address)
  {
    _wire->beginTransmission(address);
    //  Serial.print("ADDR2:");
    //  Serial.print(address);
  };
  using TwoWire::endTransmission;
  uint8_t endTransmission(void)
  {
    //  Serial.print("ET1:");
    return _wire->endTransmission(true);
  };
  uint8_t endTransmission(uint8_t sendStop)
  {
    //  Serial.print("ET2:");
    return _wire->endTransmission(sendStop);
  };


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
  size_t write(uint8_t data)
  {
    return _wire->write(data);
  };
  size_t write(const uint8_t *data, size_t quantity)
  {
    return _wire->write(data, quantity);
  };
  int available(void)
  {
    return _wire->available();
  };
  int read(void)
  {
    return _wire->read();
  };
  int peek(void)
  {
    return _wire->peek();
  };
  void flush(void){};

  void onReceive(void (*function)(int n) ){};
  void onRequest(void (*function)(void) ){};

private:
  SoftwareWire *_wire;
};


//  -- END OF FILE --

