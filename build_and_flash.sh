#! /bin/zsh

avr-g++ -std=c++20 -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o blink.o blink.cpp
avr-g++ -mmcu=atmega328p blink.o -o blink
avr-objcopy -O ihex -R .eeprom blink blink.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:blink.hex
rm blink *.o *.hex
 
