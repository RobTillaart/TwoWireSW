
# TwoWireSW

Wrapper class for SoftwareWire (experimental)

## Description

TwoWireSW is a wrapper class under development.

Goal is to create a wrapper class which inherits from **Twowire** 
around the **SoftwareWire** class.

- https://github.com/Testato/SoftwareWire

This would allow the wrapper class to be inserted as the I2C interface
in many libraries (sensors, IO chips, DAC, multiplexer etc) that now expect
an instance of a **Twowire** object.


The **SoftwareWire** library had a Twowire interface in the past 
however since version 1.6.0 this interface has been removed.


## Dependencies

- Wire
- SoftwareWire
- AsyncDelay


## Status

2023-03-15 - not working

