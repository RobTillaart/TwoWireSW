//    FILE: I2C_scanner_minimal.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo minimal I2C scanner
//     URL: https://github.com/RobTillaart/I2C_SCANNER



//  NEED TO MAKE ALL TWOWIRE VIRTUAL
//  SEE  - https://github.com/RobTillaart/TwoWireSW/issues/1



#include "TwoWireSW.h"

SoftwareWire sw(6, 7);
TwoWireSW twsw(&sw);

#include "I2C_SCANNER.h"

I2C_SCANNER scanner(&twsw);



void setup()
{
  Serial.begin(115200);
  while (!Serial);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("I2C_SCANNER_LIB_VERSION: ");
  Serial.println(I2C_SCANNER_LIB_VERSION);

  sw.begin();
  twsw.begin();
  scanner.begin();
  scanner.setWire(&twsw);

  twsw.beginTransmission(56);
  Serial.println(twsw.endTransmission());
  
  sw.beginTransmission(56);
  Serial.println(sw.endTransmission());
  
  for (int addr = 50; addr < 60; addr++)
  {
    Serial.print(addr);
    Serial.print("\t");
    Serial.print(scanner.ping(addr));
    Serial.print("\t");
    Serial.println(scanner.pingTime(addr));
  }
}


void loop()
{
}


//  -- END OF FILE --
