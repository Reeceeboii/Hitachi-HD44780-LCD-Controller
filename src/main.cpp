// lcd.cpp - Made by Reece Mercer

//    Friendly reminder to disconnect pins 0 and 1 if following my schematics as they stop the USB comms
//    working correctly when flashing the board.


#include <Arduino.h>
#include "lcd.h"


/*
B (digital pin 8 to 13) (only lesser 3 bits are used here)
D (digital pins 0 to 7) (all are used as the 8 data bits: D0 - D7)
*/


// set RS, RW and E bits to 0
void zero_control_signals(){
    PORTB = 0x0;
}

// toggle clock latch    
void toggle_clock_latch(){
    PORTB = E; 
    zero_control_signals();
}

void setup(){
    delay(1000);
    // first set pin modes
    // 0 through 7 (data bits) set to output
    DDRD  = 0xFF;
    // first 3 pins (of PORTB) used for control signals
    DDRB  = 0x7;
       
    // now we can initialise the display
    PORTD = EIGHT_BIT_ONE_LINE_DISPLAY; // eight bit mode, one line display
    zero_control_signals();
    toggle_clock_latch();
    delayMicroseconds(50);
   
    PORTD = DISPLAY_ON_CURSOR_APPEAR;
    toggle_clock_latch();
    delayMicroseconds(50);

    //PORTD = ENTRY_MODE_SET;

    //toggle_clock_latch();

}

void loop() {

}