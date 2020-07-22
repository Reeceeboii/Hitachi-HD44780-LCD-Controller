// lcd.cpp - Made by Reece Mercer

//    Friendly reminder to disconnect pins 0 and 1 if following my schematics as they stop the USB comms
//    working correctly when flashing the board.


#include <Arduino.h>
#include "lcd.h"


// set RS, RW and E bits to 0
void zero_control_signals(){
    PORTB = 0x0;
}

// clear the display of all content
void clear_display(){
    PORTD = CLEAR_DISPLAY;
    zero_control_signals();
}

// TODO implementing this
// sets DDRAM address to 0. Contents of memory remain unchanged, though
void return_home(){
    PORTD = RETURN_HOME;

}

// toggle clock latch but make sure that existing signal bits are left as they are 
void toggle_clock_latch(unsigned int microsecondDelay){
    PORTB = PORTB | E; 
    zero_control_signals();
    delayMicroseconds(microsecondDelay);
}

// write a character to the display
void write_char(char c){
    // change the control pins to include a tied high register select bit so we can write to display RAM
    PORTD = c;
    PORTB = RS;
    PORTB = PORTB | E;
    delayMicroseconds(37);
    zero_control_signals();
}

// write a string of characters to the display
void write_str(char* str){
    for(int i = 0; i < strlen(str); ++i){
        write_char(str[i]);
    }
}

void setup(){
    // the datasheet has some details about voltages that I don't yet totally understand. I'm not sure how long 
    // it takes my board to reach the required voltage to make their delay time valid, so I'll just wait for one second. 
    // Can play with this later if required.
    delay(1000);

    // first set pin modes
    // 0 through 7 (data bits) set to output
    DDRD  = 0xFF;
    // first 3 pins (of PORTB) used for control signals
    DDRB  = 0x7;
       
    // now we can initialise the display
    // delays for these functions can be found on page 24 of the datasheet for the HD44780 chipset

    // eight bit mode, one line display
    PORTD = EIGHT_BIT_ONE_LINE_DISPLAY;
    zero_control_signals();
    toggle_clock_latch(37);
   
    // turn on the display and make the cursor appear (with blinks because why not?)
    PORTD = DISPLAY_ON_CURSOR_APPEAR;
    toggle_clock_latch(37);

    // set the entry mode to increment the cursor address correctly
    PORTD = ENTRY_MODE_SET;
    toggle_clock_latch(37);

    write_str(TEST_STRING_SINGLE_LINE);

    delay(2500);
    clear_display();
    toggle_clock_latch(37);
    delay(1000);

    write_str(TEST_STRING_SINGLE_LINE);

}

void loop() {

}