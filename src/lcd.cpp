/*
    lcd.cpp - Made by Reece Mercer

    Friendly reminder to disconnect pins 0 and 1 if following my schematics as they stop the USB comms
    working correctly when flashing the board.
*/

#include <Arduino.h>


void setup() {
  PORTD = 0xFF; // 0 through 7 (data bits) set to output
}

void loop() {

}