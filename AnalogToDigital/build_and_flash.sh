#! /bin/zsh

avr-g++ -std=c++20 -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o AnalogToDigital.o AnalogToDigital.cpp
avr-g++ -mmcu=atmega328p AnalogToDigital.o -o AnalogToDigital
avr-objcopy -O ihex -R .eeprom AnalogToDigital AnalogToDigital.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:AnalogToDigital.hex
rm blink *.o *.hex
 
