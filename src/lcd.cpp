// lcd.cpp - Made by Reece Mercer

//    Friendly reminder to disconnect pins 0 and 1 if following my schematics as they stop the USB comms
//    working correctly when flashing the board.


#include <Arduino.h>
#include "lcd.h"


/*
B (digital pin 8 to 13) (only lesser 3 bits are used here)
D (digital pins 0 to 7) (all are used as the 8 data bits: D0 - D7)
*/

// toggle clock latch    
void toggle_clock_latch(){
    PORTB = E;
    PORTB = 0;
}

// set RS, RW and E bits to 0
void zero_control_signals(){
    PORTB = 0;
}

void setup(){
    // first set pin modes
    // 0 through 7 (data bits) set to output
    DDRD  = 0xFF;
    // first 3 pins (of PORTB) used for control signals
    DDRB  = 0x07;
    // now we can initialise the display
    zero_control_signals();
    PORTD = EIGHT_BIT_ONE_LINE_DISPLAY; // eight bit mode, one line display
    toggle_clock_latch();
    PORTD = DISPLAY_ON_CURSOR_APPEAR;
    toggle_clock_latch();
    

}

void loop() {

}