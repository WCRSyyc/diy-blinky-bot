# [Programming](Pumpkin.md)

<link href="css/markdown.css" rel="stylesheet"/>

* (jump to) [Improving your programming skills](#improving_skills)

The MAX7219 driver chip requires a library -- LedControl.  You must install this library in the Arduino IDE.  (You can install this library within the Arduino IDE by going to the dropdown "Sketch Menu," then "Include Library," then "Manage Libraries," and finally "LedControl")

The following program is provided to kickstart your programming and to make sure your circuit is working correctly.

Note that the Serial commands are for debugging and can be commented out, if desired.

```c++
// Preliminary Test

// Get the matrix to display a diagonal line and refresh

/*
 *  The purpose of this program is make sure you have correctly wired one 7219
 *  driver chip to an 8x8 matrix and an Arduino board.  Looking at the matrix
 *  with the pins running along the top and bottom, you should see a blinking
 *  diagonal line from the upper right-hand corner to the lower left-hand
 *  corner of the matrix
 */

/* Include the library needed to communicate with the 7219 driver chip.
 * This chip handles the multiplexing (also called scanning) for the 8x8 matrix
 * and reduces the number of required Arduino pins.
 */

# include <LedControl.h>

// Define constants for information required by LedControl.h

/*
 * Note the all caps used to define these constants.  This is a coding convention
 * used for unchanging constants, as opposed to a variable.
 */

/*
 *  There are three pins associated with the SPI protocol (Serial Peripheral Interface Bus)
 *  which is used to communicate with the 7919 chip.
 */

// Define the MOSI (master output slave input) for the interface
const unsigned int LC_MOSI = 12;

// Define the SCK (serial clock) for the interface
const unsigned int LC_CLK = 11;

// Define the SS (slave select) for the interface
const unsigned int LC_LOAD = 10;

// Define the number of matrices connected
const unsigned int LC_NUM_DEVICES = 1;

// Define a name to match the number of the first (only) LED matrix
const unsigned int FIRST_EYE = 0;

// Have the library create a control that knows how to talk to our device.
// Technically, have the library create an 'instance' (lc) of the LedControl
// 'class' using the details needed for the way the LED matrix is wired.
// the instance can be 'asked' to do things through the interface using
// method (function) calls.

LedControl lc = LedControl(LC_MOSI, LC_CLK, LC_LOAD, LC_NUM_DEVICES);

/*
 *  Define a bit array to correspond to the matrix LEDs.
 *  A 1 turns the LED on and a 0 turns it off.
 */

byte matrix[8] = {
  B00000001,
  B00000010,
  B00000100,
  B00001000,
  B00010000,
  B00100000,
  B01000000,
  B10000000
};

/*  Define a delay time between loops.
 *  Note the use of capitals in the middle of the variable name.
 *  The convention is to start with a small letter and use Caps to start each
 *  other 'word', to make the name more readable.
 */

int delayTime = 1000;  // milliseconds (= 1 second)

void setup() {
  lc.shutdown(FIRST_EYE, false);  // Wake up the display
  lc.setIntensity(FIRST_EYE, 5);  // Set the intensity level
  lc.clearDisplay(FIRST_EYE);  // Clear the display

  Serial.begin(9600); // Enable printing to the screen through the serial interface
}


void loop() {

  // Note the use of a for loop here.

  for (int i = 0; i < 8; i++) {
    lc.setRow(FIRST_EYE, i, matrix[i]);
    printBits(matrix[i]);
    delay(delayTime);
  }
  lc.clearDisplay(FIRST_EYE);
  Serial.println();
  delay(delayTime);
}


// function to print out the bit pattern to the serial interface

void printBits(byte myByte) {
 for (byte mask = 0x80; mask; mask >>= 1) {  // for each bit (high to low)
   if (mask & myByte) {  // if the bit is on (HIGH)
       Serial.print('1');
   } else {
       Serial.print('0');
   }
 }
 Serial.println();
}
```

## <a name="improving_skills">⚓</a> Improving your programming skills]

If you are new to programming, you many want to try the following challenges before attempting to program the various pumpkin expressions. Try to do these challenges on your own, but if you are really stuck example code is provided in Appendix B of this instructable. Note that there is always more than one way to achieve a programming objective, so do not be concerned if your approach differs from the example code.  That being said, do try to follow good programming etiquette, such as naming conventions and indentations.

1. Light each LED in each *row*, one at a time.  Hint:  For greater efficiency, you might want to use a bit shift operator (>> or <<).  Bonus points for starting at each of the four corners of the LED matrix. (See the code in Example 1 of Appendix B, if you need help.)

1. Light each LED in each *column*, one at a time.  Again, you may find a bit shift operator helpful.  Bonus points for starting at each of the four corners of the LED matrix. (See the code in Example 2 of Appendix B, if you need help.)

1. Scroll a vertical column across the matrix from left to right.  Bonus points for scrolling in both directions.  (See the code in Example 3 of Appendix B, if you need help.)

1. Display one letter/initial on the LED matrix. (See the code in Example 4 of Appendix B for bit patterns for various capital letters and/or if you need help.)

1. Scroll one letter/initial across the matrix from right to left. (See the code in Example 5 of Appendix B, if you need help.)

1. Scroll a message across the matrix (e.g., your name). Bonus points for building in flexibility to handle a message of any size.  Extra bonus points for getting your code to parse text into a bit pattern.

1. Add a second LED matrix and 7219 driver. Display one letter/initial or number on each of the two matrices. It is helpful to position the two LED matrices side-by-side.
A second breadboard can be useful, but there is room to put both eyes on a single breadboard.  See the earlier example layout.

1. Scroll two letters across two matrices.  Bonus points for building in flexibility to handle messages of any length.

1. Display the basic eyeball pattern on each of the LEDs.  Turn all LEDs on, except for a square of 4 in the middle.

1. Make the eye pupils move to the left and right.

1. Add the capability to move the pupils up and down.

1. Add the capability to move the pupils diagonally.

1. Add the capability to move each pupil to a specified target.

1. Add the capability for crossed eyes.

1. Add the capability to roll the eyes.  (Scroll the pupils and then have them reappear on the other side of the eyeball.)

1. Add the capability for jittery eyes, also known as "coffee eyes."  Bonus points for making your growing range of options random.

1. Add the capability for blinking eyes.  Bonus points for winking eyes.

1. Add the capability for glowing eyes.  Hint:  Change the light intensity.

1. Design your own eye patterns -- goofy eyes, sinister eyes, etc.

Some bit array patterns to get you started

```c++
// A round eyeball bit pattern, without a pupil
const byte roundEye[] = {
  0b00111100,   // 0
  0b01111110,   // 1
  0b11111111,   // 2
  0b11111111,   // 3
  0b11111111,   // 4
  0b11111111,   // 5
  0b01111110,   // 6
  0b00111100,   // 7

// A (black) pupil by itself
const byte pupil[] = {
  0b11111111,   // 0
  0b11111111,   // 1
  0b11111111,   // 2
  0b11100111,   // 3
  0b11100111,   // 4
  0b11111111,   // 5
  0b11111111,   // 6
  0b11111111,   // 7
};

// A round eyeball with pupil in the centre
const byte eyeAndPupil[] = {
  0b00111100,   // 0
  0b01111110,   // 1
  0b11111111,   // 2
  0b11100111,   // 3
  0b11100111,   // 4
  0b11111111,   // 5
  0b01111110,   // 6
  0b00111100,   // 7
```
