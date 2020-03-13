# Appendix B - Example Code for Learning Challenges

Additional code samples are available in the [WCRS pumpkin matrix](https://github.com/WCRSyyc/pumpkin-matrix) repository on github.

* Example 1 - [Lighting each LED - Row-wise](#each_led_row_wise)
* Example 2 - [Lighting each LED - Column-wise](#each_led_column_wise)
* Example 3 - [Scrolling a Vertical Column](#vertical_column_scroll)
* Example 4 - [Display One Initial](#display_one_initial)
* Example 5 - [Scroll One Initial](#scroll_one_initial)

## <a name="each_led_row_wise">⚓</a> Example 1 - Lighting each LED - Row-wise

```c++
// Light LEDs one at a time - row-wise

/*
 *  The purpose of this program is to light each LED in each row, one at
 *  a time.  Hint:  For greater efficiency, use a bit shift operator, >> or <<.
 */

#include <LedControl.h>

//Define pins required by LedControl.h

const unsigned int LC_DATA_IN = 12;
const unsigned int LC_CLK = 11;
const unsigned int LC_LOAD = 10;

// Define the number of matrices connected

const unsigned int LC_NUM_DEVICES = 1;

// Pass this data to the LedControl library

LedControl lc = LedControl(LC_DATA_IN, LC_CLK, LC_LOAD, LC_NUM_DEVICES);

int delayTime = 500;

void setup() {

  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);    // Clear displays

  Serial.begin(9600);
}

void loop() {

  // Starting in the upper right-hand corner

  // Note the use of two nested for loops.

  for (int j = 0; j < 8; j++) {
    Serial.print("Row = ");
    Serial.println(j+1);
    for (int i = 7; i >= 0; i--) {
      lc.setRow(0,j,B10000000 >> i);
      printBits(B10000000 >> i);
      delay (delayTime);
      lc.clearDisplay(0);
    }
    Serial.println();
  }

  // Starting in the lower right-hand corner

  for (int j = 7; j >= 0; j--) {
    Serial.print("Row = ");
    Serial.println(j+1);
    for (int i = 7; i >= 0; i--) {
      lc.setRow(0,j,B10000000 >> i);
      printBits(B10000000 >> i);
      delay (delayTime);
      lc.clearDisplay(0);
    }
    Serial.println();
  }

  // Starting in the upper left-hand corner

  for (int j = 0; j < 8; j++) {
    Serial.print("Row = ");
    Serial.println(j+1);
    for (int i = 0; i < 8; i++) {
      lc.setRow(0,j,B10000000 >>i);
      printBits(B10000000 >> i);
      delay (delayTime);
      lc.clearDisplay(0);
    }
    Serial.println();
  }

  // Starting in the lower left-hand corner

  for (int j = 7; j >= 0; j--) {
    Serial.print("Row = ");
    Serial.println(j+1);
    for (int i = 0; i < 8; i++) {
      lc.setRow(0,j,B10000000 >> i);
      printBits(B10000000 >> i);
      delay (delayTime);
      lc.clearDisplay(0);
    }
    Serial.println();
  }
  delay (delayTime);
}

void printBits(byte myByte){
 for(byte mask = 0x80; mask; mask >>= 1){
   if(mask  & myByte)
       Serial.print('1');
   else
       Serial.print('0');
 }
 Serial.println();
}
```

## <a name="each_led_column_wise">⚓</a> Example 2 - Lighting each LED - Column-wise

```c++
// Light LEDs one at a time - column-wise

/*
 *  The purpose of this program is to light each LED in each column, one at
 *  a time.  Hint:  For greater efficiency, use a bit shift operator (<< or >>).
 */

#include <LedControl.h>

//Define pins required by LedControl.h

const unsigned int LC_DATA_IN = 12;
const unsigned int LC_CLK = 11;
const unsigned int LC_LOAD = 10;

// Define the number of matrices connected

const unsigned int LC_NUM_DEVICES = 1;

// Pass this data to the LedControl library

LedControl lc = LedControl(LC_DATA_IN, LC_CLK, LC_LOAD, LC_NUM_DEVICES);

int delayTime = 500;

void setup() {

  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);    // Clear displays

  Serial.begin(9600);
}

void loop() {

  // Starting at the upper right-hand corner

  for (int j = 0; j < 8; j++) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0,i,1 << j);
      Serial.print("Row = ");
      Serial.print(i+1);
      Serial.print(" ");
      printBits(1 << j);
      delay (delayTime);
      lc.setRow(0,i,0);
      delay (delayTime);
    }
    Serial.println();
  }

  // Starting at the upper left-hand corner

  for (int j = 7; j >= 0; j--) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0,i,1 << j);
      Serial.print("Row = ");
      Serial.print(i+1);
      Serial.print(" ");
      printBits(1 << j);
      delay (delayTime);
      lc.setRow(0,i,0);
      delay (delayTime);
    }
    Serial.println();
  }

  // Starting at the lower right-hand corner

  for (int j = 0; j < 8; j++) {
    for (int i = 7; i >= 0; i--) {
      lc.setRow(0,i,1 << j);
      Serial.print("Row = ");
      Serial.print(i+1);
      Serial.print(" ");
      printBits(1 << j);
      delay (delayTime);
      lc.setRow(0,i,0);
      delay (delayTime);
    }
    Serial.println();
  }

  // Starting at the lower left-hand corner

  for (int j = 7; j >=0; j--) {
    for (int i = 7; i >= 0; i--) {
      lc.setRow(0,i,1 << j);
      Serial.print("Row = ");
      Serial.print(i+1);
      Serial.print(" ");
      printBits(1 << j);
      delay (delayTime);
      lc.setRow(0,i,0);
      delay (delayTime);
    }
    Serial.println();
  }
}

void printBits(byte myByte){
 for(byte mask = 0x80; mask; mask >>= 1){
   if(mask  & myByte)
       Serial.print('1');
   else
       Serial.print('0');
 }
 Serial.println();
}
```

## <a name="vertical_column_scroll">⚓</a> Example 3 - Scrolling a Vertical Column

```c++
// Scrolling a Vertical Column

/*
 *  The purpose of this program is scroll a vertical column across an 8 x 8 matrix
 *  from right to left.
 *  Hint:  For greater efficiency, use a bit shift operator <<.
 */

#include <LedControl.h>

//Define pins required by LedControl.h

const unsigned int LC_DATA_IN = 12;
const unsigned int LC_CLK = 11;
const unsigned int LC_LOAD = 10;

// Define the number of matrices connected

const unsigned int LC_NUM_DEVICES = 1;

// Pass this data to the LedControl library and save it in memory as lc

LedControl lc = LedControl(LC_DATA_IN, LC_CLK, LC_LOAD, LC_NUM_DEVICES);

int delayTime = 200;

void setup() {

  Serial.begin(9600);

  lc.shutdown(0,false);  // Wake up displays
  lc.setIntensity(0,5);  // Set intensity levels
  lc.clearDisplay(0);    // Clear displays
}

void loop() {

  // Scrolling from Right

  for (int j = 0; j < 8 ; j++) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0,i,1 << j);
      printBits(1 << j);
    }
    Serial.println();
    delay (delayTime);
    for (int i = 0; i <8; i++) {
      lc.setRow(0,i,0);
    }
  }

  // Scrolling from Left

  for (int j = 7; j >= 0 ; j--) {
    for (int i = 0; i < 8; i++) {
      lc.setRow(0,i,1 << j);
      printBits(1 << j);
    }
    Serial.println();
    delay (delayTime);
    for (int i = 0; i <8; i++) {
      lc.setRow(0,i,0);
    }
  }
}

void printBits(byte myByte){
 for(byte mask = 0x80; mask; mask >>= 1){
   if(mask  & myByte)
       Serial.print('1');
   else
       Serial.print('0');
 }
 Serial.println();
}
```

## <a name="display_one_initial">⚓</a> Example 4 - Display One Initial

```c++
// Display one initial

// The objective of this program is to display one initial on your LED.

#include <LedControl.h>

const unsigned int LC_DATA_IN = 12; // Define the MISO (master input slave output) interface
const unsigned int LC_CLK = 11; // Define the SCK (serial clock) interface
const unsigned int LC_LOAD = 10; // Define the SS (slave select) interface

// Define the number of matrices connected
const unsigned int LC_NUM_DEVICES = 1;

// Pass this data to the LedControl library and save it in memory as lc

LedControl lc = LedControl(LC_DATA_IN, LC_CLK, LC_LOAD, LC_NUM_DEVICES);

// Define a bit array for the initial
// Choose your own initial

byte capA[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};
byte capB[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01100110,
  B01100110,
  B01111100
};
byte capC[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01100000,
  B01100110,
  B00111100
};
byte capD[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01111100
};
byte capE[8] = {
  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01111110
};
byte capF[8] = {
  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01100000
};
byte capG[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01101110,
  B01100110,
  B00111100
};
byte capH[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};
byte capI[8] = {
  B00000000,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100
};
byte capJ[8] = {
  B00000000,
  B00011110,
  B00001100,
  B00001100,
  B00001100,
  B01101100,
  B01101100,
  B00111000
};
byte capK[8] = {
  B00000000,
  B01100110,
  B01101100,
  B01111000,
  B01110000,
  B01111000,
  B01101100,
  B01100110
};
byte capL[8] = {
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110
};
byte capM[8] = {
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110
};
byte capN[8] = {
  B00000000,
  B01100011,
  B01110011,
  B01111011,
  B01101111,
  B01100111,
  B01100011,
  B01100011
};
byte capO[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100
};
byte capP[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
};
byte capQ[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
};
byte capR[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01111000,
  B01101100,
  B01100110
};
byte capS[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B00111100,
  B00000110,
  B01100110,
  B00111100
};
byte capT[8] = {
  B00000000,
  B01111110,
  B01011010,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};
byte capU[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111110
};
byte capV[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000
};
byte capW[8] = {
  B00000000,
  B01100011,
  B01100011,
  B01100011,
  B01101011,
  B01111111,
  B01110111,
  B01100011
};
byte capX[8] = {
  B00000000,
  B01100011,
  B01100011,
  B00110110,
  B00011100,
  B00110110,
  B01100011,
  B01100011
};
byte capY[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000,
  B00011000,
  B00011000
};
byte capZ[8] = {
  B00000000,
  B01111110,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01100000,
  B01111110
};


int delayTime = 1000;// Define a delay time between loops.

void setup() {
  Serial.begin(9600);

  lc.shutdown(0,false);  // Wake up the displays
  lc.setIntensity(0,5);  // Set the intensity levels
  lc.clearDisplay(0);    // Clear the displays
}

void loop() {
  for (int i = 0; i < 8; i++) {
    // Substitute the letter of your choice
    lc.setRow(0,i,capA[i]);
    printBits(capA[i]);
  }
  Serial.println();
  delay (delayTime);
  lc.clearDisplay(0);
  delay(delayTime);
}


void printBits(byte myByte){
 for(byte mask = 0x80; mask; mask >>= 1){
   if(mask  & myByte)
       Serial.print('1');
   else
       Serial.print('0');
 }
 Serial.println();
}
```

## <a name="scroll_one_initial">⚓</a> Example 5 - Scroll One Initial

```c++
// Scroll One Initial

// The objective of this program is to scroll one letter/initial or number on your LED.

#include <LedControl.h>

const unsigned int LC_DATA_IN = 12; // Define the MISO (master input slave output) interface
const unsigned int LC_CLK = 11;     // Define the SCK (serial clock) interface
const unsigned int LC_LOAD = 10;    // Define the SS (slave select) interface

// Define the number of matrices connected
const unsigned int LC_NUM_DEVICES = 1;

// Pass this data to the LedControl library

LedControl lc = LedControl(LC_DATA_IN, LC_CLK, LC_LOAD, LC_NUM_DEVICES);

// Define a bit array for the initial

byte capA[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};
byte capB[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01100110,
  B01100110,
  B01111100
};
byte capC[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01100000,
  B01100110,
  B00111100
};
byte capD[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01111100
};
byte capE[8] = {
  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01111110
};
byte capF[8] = {
  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01100000
};
byte capG[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01101110,
  B01100110,
  B00111100
};
byte capH[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};
byte capI[8] = {
  B00000000,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100
};
byte capJ[8] = {
  B00000000,
  B00011110,
  B00001100,
  B00001100,
  B00001100,
  B01101100,
  B01101100,
  B00111000
};
byte capK[8] = {
  B00000000,
  B01100110,
  B01101100,
  B01111000,
  B01110000,
  B01111000,
  B01101100,
  B01100110
};
byte capL[8] = {
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110
};
byte capM[8] = {
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110
};
byte capN[8] = {
  B00000000,
  B01100011,
  B01110011,
  B01111011,
  B01101111,
  B01100111,
  B01100011,
  B01100011
};
byte capO[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100
};
byte capP[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
};
byte capQ[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
};
byte capR[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01111000,
  B01101100,
  B01100110
};
byte capS[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B00111100,
  B00000110,
  B01100110,
  B00111100
};
byte capT[8] = {
  B00000000,
  B01111110,
  B01011010,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};
byte capU[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111110
};
byte capV[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000
};
byte capW[8] = {
  B00000000,
  B01100011,
  B01100011,
  B01100011,
  B01101011,
  B01111111,
  B01110111,
  B01100011
};
byte capX[8] = {
  B00000000,
  B01100011,
  B01100011,
  B00110110,
  B00011100,
  B00110110,
  B01100011,
  B01100011
};
byte capY[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000,
  B00011000,
  B00011000
};
byte capZ[8] = {
  B00000000,
  B01111110,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01100000,
  B01111110
};

byte holder;
byte initial[8];

int delayTime = 200;  // Define a delay time between loops.

void setup() {
  Serial.begin(9600);

  lc.shutdown(0,false);  // Wake up the displays
  lc.setIntensity(0,5);  // Set the intensity levels
  lc.clearDisplay(0);    // Clear the display

  // Choose your initial

  for (int i = 0; i < 8; i++) {
    initial[i]) = capA[i];
  }
}

void loop() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0,i,initial[i]);
    printBits(initial[i]);
  }
  Serial.println();
  delay (delayTime);
  lc.clearDisplay(0);
  for (int i = 0; i < 8; i++) {
    holder = initial[i] >> 7;
    initial[i] = initial[i] << 1;
    initial[i] = initial[i] + holder;
  }
}

void printBits(byte myByte){
 for(byte mask = 0x80; mask; mask >>= 1){
   if(mask  & myByte)
       Serial.print('1');
   else
       Serial.print('0');
 }
 Serial.println();
}
```
