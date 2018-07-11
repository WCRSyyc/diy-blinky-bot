# Level 3 Blink Bot Sketches

This folder contains Arduino sketch code that can be used with level 3 blinky bot projects.  Level 3 contains an Arduino board to supply some intelligence to the projects.

## Pumpkin

The Halloween pumpkin eyes use a pair of LED matrices.  Those can be used for a lot more than eyes.

* scroll-text
  * One of the tests, to make sure you understand how to communicate with the MAX7219 LED Matrix controller chip, is to get it do show your name or initials.  This goes a bit further than that.  If the Arduino board is connected a computer, the Arduino IDE serial monitor (or other serial terminal program) can be used to pass information to and from the Arduino while it is running.  Scroll-text takes advantage of that, to change the message after the Arduino is started.  Within the limits of the character images defined, any text can be specified to scrolled across a single 8x8 LED matrix.
  * Going further
    * Set a message to display initially, until a new message is supplied/
    * Replace the scroll step delay with code that used elapsed time checks.  This would allow changing the displayed message immediately, instead of only when the last of the current message has scrolled through.
