# Hitachi-HD44780-LCD-Controller
## My attempt at writing code to control a TC1602B­01 (HD44780 compatible) LCD module without any LCD specific libraries.

I haven't done any electronics based stuff in a while so figured I needed a fairly interesting project to get back into the flow of things. I have an LCD module (Tinsharp TC1602B­01) sitting in my box of electronics along with an Arduino so figured I'd wire them up and write the control code myself to hopefully renew my knowledge and learn a thing or two along the way.


![TC1602B­01 front](img/lcd_front.jpg)
![TC1602B­01 back](img/lcd_back.jpg)

## The plan
The majority of the control signals that get sent to the screen are done so via the 8 (D0-D7) data pins that are visible on the front of the module. Now sending data to these pins individually sounds (and is) a pain, so luckily we can make use of the Arduino's port registers to allow quicker and more efficient access to these pins via the code. We can send out a byte of data at once as opposed to 8 individual calls to a digital write function doing a bit at a time. This makes for faster and more lightweight code.

First of all, we need to wire it up - here's a schematic I threw together before starting:

![Circuit schematic](img/citcuit_schematic.png)
(one thing to note is that having pins 0 and 1 in use by our program may cause issues when flashing the board. I had issues with avrdude during this step. Simply disconnecting the jumpers solves this and you can reconnect them straight after.)

And a somewhat accurate recreation:

![Wired up](img/wired_up.jpg)
![Pins](img/pins.jpg)

You can see 8 data bits are wired into PORTD (pins 0 through 7) and the control signals and clock latch pins wired into the lesser 3 bits of PORTB.

GPIO pins aren't needed for power nor ground so those are wired into the regular 5V and GND pins on the far side of the board.