
[![Arduino CI](https://github.com/RobTillaart/TwoWireSW/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/TwoWireSW/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/TwoWireSW/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/TwoWireSW/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/TwoWireSW/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/TwoWireSW.svg)](https://github.com/RobTillaart/TwoWireSW/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/TwoWireSW/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/TwoWireSW.svg?maxAge=3600)](https://github.com/RobTillaart/TwoWireSW/releases)

TODO: include when working.
```
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/TwoWireSW.svg)](https://registry.platformio.org/libraries/robtillaart/TwoWireSW)
```


Arduino-lint is failing as library is not registered.



# TwoWireSW

TwoWire interface wrapper around SoftwareWire (experimental ==> not possible)


## Description

**VERY VERY EXPERIMENTAL**
TwoWireSW is a wrapper class under development (not working).

Goal is to create a wrapper class which inherits from **TwoWire** 
around the **SoftwareWire** class.

- https://github.com/Testato/SoftwareWire

This would allow the wrapper class to be inserted as the I2C interface
in many libraries (sensors, IO chips, DAC, multiplexer etc.) that now expect
an instance of a **TwoWire** object.


The **SoftwareWire** library had a **TwoWire** interface in the past 
however since version 1.6.0 this interface has been removed.


#### Status

- 2023-03-15 - not working
- 2023-03-20 - not possible to work => see discussion in issue #1
- 2023-10-09 - add build-CI frame to fix open issue.


#### Conclusion

It is possible to write the wrapper class, but impossible to use that as an instance
for TwoWire as the main functions of **TwoWire** are not virtual. (See issue #1).

Will not investigate further unless as project.


## Dependencies

- Wire
- SoftwareWire
- AsyncDelay


## Interface

```cpp
#include "TwoWireSW.h"
```

See TwoWire documentation.


## Future

#### Must

- improve documentation
- create PR / issue to make main functions TwoWire virtual.
  (would at least help a bit on AVR)

#### Should

#### Could

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,



