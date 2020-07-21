# Hitachi-HD44780-LCD-Controller
## My attempt at writing code to control a TC1602B­01 (HD44780 compatible) LCD module without any LCD specific libraries.

I haven't done any electronics based stuff in a while so figured I needed a fairly interesting project to get back into the flow of things. I have an LCD module (Tinsharp TC1602B­01) sitting in my box of electronics along with an Arduino so figured I'd wire them up and write the control code myself to hopefully renew my knowledge and learn a thing or two along the way.


![TC1602B­01 front](img/lcd_front.jpg)
![TC1602B­01 back](img/lcd_back.jpg)

## The plan
The majority of the control signals that get sent to the screen are done so via the 8 (D0-D7) data pins that are visible on the front of the module. Now sending data to these pins individually sounds (and is) a pain so luckily we can make use of the Arduino's port registers to allow quicker and more efficient access to these pins via the code. We can send out a byte of data at once as opposed to 8 individuals calls to a digital write function.

First of all, we need to wire it up - here's a schematic I threw together before starting:

![Circuit schematic](img/citcuit_schematic.png)