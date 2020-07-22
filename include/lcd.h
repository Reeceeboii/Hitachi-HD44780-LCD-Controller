// instruction codes
#define EIGHT_BIT_ONE_LINE_DISPLAY 0x30
#define DISPLAY_ON_CURSOR_APPEAR 0x0F
#define ENTRY_MODE_SET 0x06
#define CLEAR_DISPLAY 0x01
#define RETURN_HOME 0x02

// my particular pins for the 3 control signals
#define RS 0x01
#define RW 0x02
#define E 0x04

char TEST_STRING_SINGLE_LINE[] = "Hello world!";

void write_char(char c);
void write_str(char* str);
void toggle_clock_latch(unsigned int microsecondDelay);
void zero_control_signals();
void clear_display();
void return_home();