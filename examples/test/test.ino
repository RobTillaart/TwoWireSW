//
//    FILE: test.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/TwoWireSW



//  NEED TO MAKE ALL TWOWIRE VIRTUAL
//  SEE  - https://github.com/RobTillaart/TwoWireSW/issues/1




#include "TwoWireSW.h"
#include "Wire.h"
#include "SHT31.h"

SoftwareWire sw(6,7)
TwoWireSW twsw(&sw);

#define SHT31_ADDRESS   0x44
SHT31 sht;

uint32_t start;
uint32_t stop;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);

  twsw.begin();
  sht.begin(SHT31_ADDRESS, &twsw);

  uint16_t stat = sht.readStatus();
  Serial.print(stat, HEX);
  Serial.println();

  Serial.println("done..");
}


void loop()
{
  start = micros();
  sht.read();         //  default = true/fast       slow = false
  stop = micros();

  Serial.print("\t");
  Serial.print(stop - start);
  Serial.print("\t");
  Serial.print(sht.getTemperature(), 1);
  Serial.print("\t");
  Serial.println(sht.getHumidity(), 1);
  delay(100);
}


// -- END OF FILE --

