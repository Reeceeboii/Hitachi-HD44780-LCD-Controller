// Made by Reece Mercer

//    Friendly reminder to disconnect pins 0 and 1 if following my schematics as they stop the USB comms
//    working correctly when flashing the board.


#include <Arduino.h>
#include "lcd.h"

// Clear the display of all content
void clear_display(){
    PORTD = CLEAR_DISPLAY;
    PORTB = 0;
    toggle_clock_latch(CLEAR_OR_RETURN_MICROSECOND_DELAY);
}

// Sets DDRAM address to 0. Contents of memory remain unchanged, though
void return_home(){
    PORTD = RETURN_HOME;
    PORTB = 0;
    toggle_clock_latch(CLEAR_OR_RETURN_MICROSECOND_DELAY);
}

// Toggle the chipset's clock latch and wait a given number of microseconds.
// As we don't want to affect any other control bits before an instruction is sent, we can just simply
// toggle the control latch bit on its own.
// Also, as each instruction takes x amount of time to complete, we can bundle a microsecond delay param
// as part of triggering a clock pulse
void toggle_clock_latch(unsigned int microsecondDelay){
    PORTB |= E;
    PORTB &= ~E;
    delayMicroseconds(microsecondDelay);
}

// Write a single character to the display
void write_char(char c){
    PORTD = c;
    // change the control pins to include a tied high register select bit so we can write to display RAM
    PORTB |= RS;
    toggle_clock_latch(STANDARD_MICROSECOND_DELAY);
}

// Write a string of characters to the display
void write_str(char* str){
    for(int i = 0; i < strlen(str); ++i){
        write_char(str[i]);
    }
}

// Carry out all of the functions required to boot theb display into eight bit, one line display mode.
// Delays for these functions can be found on page 24 of the datasheet for the HD44780 chipset.
// Most of them use a seemingly standard 37μs delay
void initialise_eight_bit_one_line(){
    PORTB = 0;

    // Function set
    PORTD = EIGHT_BIT_ONE_LINE_DISPLAY;
    toggle_clock_latch(STANDARD_MICROSECOND_DELAY);

    // Display on (with a flashing cursor because why not)
    PORTD = DISPLAY_ON_CURSOR_APPEAR;
    toggle_clock_latch(STANDARD_MICROSECOND_DELAY);

    // set the entry mode to increment the cursor address correctly
    PORTD = ENTRY_MODE_SET;
    toggle_clock_latch(37);
}

// Initialise the LCD
void setup(){
    // Give the display sufficient time to carry out its internal reset function
    delay(1000);

    // Before we can do anything, we set and data direction registers to be correct
    // 0 through 7 (data bits) set to output
    DDRD  = 0xFF;
    // first 3 pins (of PORTB) used for control signals
    DDRB  = 0x7;
       
    // now we can initialise the display
    initialise_eight_bit_one_line();
    clear_display();

    write_str(TEST_STRING_SINGLE_LINE);
}

void loop(){
}