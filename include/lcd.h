// instruction codes
#define EIGHT_BIT_ONE_LINE_DISPLAY 0x30
#define EIGHT_BIT_TWO_LINE_DISPLAY 0x38
#define DISPLAY_ON_CURSOR_APPEAR 0x0F
#define ENTRY_MODE_SET 0x06
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02
#define MOVE_CURSOR_TO_SECOND_LINE 0x40

// my particular pins for the 3 control signals
#define RS 0x01
#define RW 0x02
#define E 0x04

// and some other stuff
char TEST_STRING_SINGLE_LINE[] = "Hello world!";
// delay of 37μs to use for clock latch toggles
#define STANDARD_MICROSECOND_DELAY 40
// the delay when clearing the display or returning home is a bit longer
#define CLEAR_OR_RETURN_MICROSECOND_DELAY 1600

void write_char(char c);
void write_str(char* str);
void toggle_clock_latch(unsigned int microsecondDelay);
void zero_control_signals();
void clear_display();
void return_home();
void initialise_eight_bit_one_line();
void initialise_eight_bit_two_line();
void move_cursor_to_new_line();