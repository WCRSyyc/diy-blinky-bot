# Level 3 Blink Bot Sketches

This folder contains Arduino sketch code that can be used with level 3 blinky bot projects.  Level 3 contains an Arduino board to supply some intelligence to the projects.

## Pumpkin

The Halloween pumpkin eyes use a pair of LED matrices.  Those can be used for a lot more than eyes.

* [scroll-text](https://github.com/WCRSyyc/diy-blinky-bot/blob/master/level3/scroll-text/scroll-text.ino)
  * One of the tests, to make sure you understand how to communicate with the MAX7219 LED Matrix controller chip, is to get it do show your name or initials.  This goes a bit further than that.  If the Arduino board is connected a computer, the Arduino IDE serial monitor (or other serial terminal program) can be used to pass information to and from the Arduino while it is running.  Scroll-text takes advantage of that, to change the message after the Arduino is started.  Within the limits of the character images defined, any text can be specified to scrolled across a single 8x8 LED matrix.
  * click the "Raw" button on the above linked page, to get a page that is easy to copy the code from.
  * Going further
    * Set a message to display initially, until a new message is supplied/
    * Replace the scroll step delay with code that used elapsed time checks.  This would allow changing the displayed message immediately, instead of only when the last of the current message has scrolled through.
    * What changes would be needed to handle 2 Matrices, to display 2 full characters at a time?
      * Hints: 2 addresses; bigger buffer area.
