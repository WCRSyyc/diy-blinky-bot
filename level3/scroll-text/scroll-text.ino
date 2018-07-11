// Scrolled Name

/*
 * The purpose of this program is to scroll a name or message across one LED matrix.
 * Hint: For greater efficiency, use a bit shift operator. >>
 * To make the program more general, try to write it for a name/message of any length.
 * Hint:  Use the length method of the String class.
 */

#include <LedControl.h>

// Specify the Arduino pin numbers to use for the (pseudo) SPI interface to the
// MAX7219 LED matrix controller chip
const unsigned int LC_DATA_IN = 12;  // MISO (master input slave output)
const unsigned int LC_CLK = 11;      // SCK (serial clock)
const unsigned int LC_LOAD = 10;     // SS (slave select)

const unsigned int LC_NUM_DEVICES = 1;  // Define the number of matrices connected

// Pass this data to the LedControl library
LedControl lc = LedControl(LC_DATA_IN, LC_CLK, LC_LOAD, LC_NUM_DEVICES);

int delayTime = 100; // milliseconds between scrolling steps

/*
 *  Binary images of Alphabetic characters
 *  Create your own characters at this website:  https://xantorohara.github.io/led-matrix-editor/#0010107c10100000|0000003c00000000|006c38fe386c0000|00060c1830600000|60660c1830660600|00003c003c000000|000000365c000000|0000008244281000|6030180c18306000|060c1830180c0600|6030181818306000|060c1818180c0600|7818181818187800|1e18181818181e00|7018180c18187000|0e18183018180e00|0606000000000000|0018180018180000|0c18180018180000|060c0c0c00000000|180018183c3c1800|1800183860663c00|003c421a3a221c00|fc66a6143c663c00|103c403804781000|6c6cfe6cfe6c6c00|383838fe7c381000|10387cfe38383800|10307efe7e301000|1018fcfefc181000|fefe7c7c38381000|1038387c7cfefe00|061e7efe7e1e0600|c0f0fcfefcf0c000|7c92aa82aa827c00|7ceed6fed6fe7c00|10387cfefeee4400|10387cfe7c381000|381054fe54381000|38107cfe7c381000|00387c7c7c380000|ffc7838383c7ffff|0038444444380000|ffc7bbbbbbc7ffff|0c12129ca0c0f000|38444438107c1000|060e0c0808281800|066eecc88898f000|105438ee38541000|1038541054381000|6666006666666600|002844fe44280000|00000000286c6c00|006030180c060000|0000000060303000|0000000c18181800|fe8282c66c381000
 *
 */

const byte number1[8] = {
  B00000000,
  B00011000,
  B00011000,
  B00111000,
  B00011000,
  B00011000,
  B00011000,
  B01111110
};
const byte number2[8] = {
  B00000000,
  B00111100,
  B01100110,
  B00000110,
  B00001100,
  B00110000,
  B01100000,
  B01111110
};
const byte number3[8] = {
  B00000000,
  B00111100,
  B01100110,
  B00000110,
  B00011100,
  B00000110,
  B01100110,
  B00111100
};
const byte number4[8] = {
  B00000000,
  B00001100,
  B00011100,
  B00101100,
  B01001100,
  B01111110,
  B00001100,
  B00001100
};
const byte number5[8] = {
  B00000000,
  B01111110,
  B01100000,
  B01111100,
  B00000110,
  B00000110,
  B01100110,
  B00111100
};
const byte number6[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B00111100
};
const byte number7[8] = {
  B00000000,
  B01111110,
  B01100110,
  B00001100,
  B00001100,
  B00011000,
  B00011000,
  B00011000
};
const byte number8[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B00111100,
  B01100110,
  B01100110,
  B00111100
};
const byte number9[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B00111110,
  B00000110,
  B01100110,
  B00111100
};
const byte number0[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01101110,
  B01110110,
  B01100110,
  B01100110,
  B00111100
};
const byte capA[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};
const byte capB[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01100110,
  B01100110,
  B01111100
};
const byte capC[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01100000,
  B01100110,
  B00111100
};
const byte capD[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01111100
};
const byte capE[8] = {
  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01111110
};
const byte capF[8] = {
  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01100000
};
const byte capG[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01101110,
  B01100110,
  B00111100
};
const byte capH[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};
const byte capI[8] = {
  B00000000,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100
};
const byte capJ[8] = {
  B00000000,
  B00011110,
  B00001100,
  B00001100,
  B00001100,
  B01101100,
  B01101100,
  B00111000
};
const byte capK[8] = {
  B00000000,
  B01100110,
  B01101100,
  B01111000,
  B01110000,
  B01111000,
  B01101100,
  B01100110
};
const byte capL[8] = {
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110
};
const byte capM[8] = {
  B00000000,
  B01100011,
  B01110111,
  B01111111,
  B01101011,
  B01100011,
  B01100011,
  B01100011
};
const byte capN[8] = {
  B00000000,
  B01100011,
  B01110011,
  B01111011,
  B01101111,
  B01100111,
  B01100011,
  B01100011
};
const byte capO[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100
};
const byte capP[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
};
const byte capQ[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
};
const byte capR[8] = {
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01111000,
  B01101100,
  B01100110
};
const byte capS[8] = {
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B00111100,
  B00000110,
  B01100110,
  B00111100
};
const byte capT[8] = {
  B00000000,
  B01111110,
  B01011010,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};
const byte capU[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111110
};
const byte capV[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000
};
const byte capW[8] = {
  B00000000,
  B01100011,
  B01100011,
  B01100011,
  B01101011,
  B01111111,
  B01110111,
  B01100011
};
const byte capX[8] = {
  B00000000,
  B01100011,
  B01100011,
  B00110110,
  B00011100,
  B00110110,
  B01100011,
  B01100011
};
const byte capY[8] = {
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000,
  B00011000,
  B00011000
};
const byte capZ[8] = {
  B00000000,
  B01111110,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01100000,
  B01111110
};
const byte smallA[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B00000110,
  B00111110,
  B01100110,
  B00111110
};
const byte smallB[8] = {
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B01111100
};
const byte smallC[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100110,
  B00111100
};
const byte smallD[8] = {
  B00000000,
  B00000110,
  B00000110,
  B00000110,
  B00111110,
  B01100110,
  B01100110,
  B00111110
};
const byte smallE[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B01100110,
  B01111110,
  B01100000,
  B00111100
};
const byte smallF[8] = {
  B00000000,
  B00011100,
  B00110110,
  B00110000,
  B00110000,
  B01111100,
  B00110000,
  B00110000
};
const byte smallG[8] = {
  B00000000,
  B00000000,
  B00111110,
  B01100110,
  B01100110,
  B00111110,
  B00000110,
  B00111100
};
const byte smallH[8] = {
  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B01100110
};
const byte smallI[8] = {
  B00000000,
  B00000000,
  B00011000,
  B00000000,
  B00011000,
  B00011000,
  B00011000,
  B00111100
};
const byte smallJ[8] = {
  B00000000,
  B00001100,
  B00000000,
  B00001100,
  B00001100,
  B01101100,
  B01101100,
  B00111000
};
const byte smallK[8] = {
 B00000000,
  B01100000,
  B01100000,
  B01100110,
  B01101100,
  B01111000,
  B01101100,
  B01100110
};
const byte smallL[8] = {
  B00000000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};
const byte smallM[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01100011,
  B01110111,
  B01111111,
  B01101011,
  B01101011
};
const byte smallN[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01111100,
  B01111110,
  B01100110,
  B01100110,
  B01100110
};
const byte smallO[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B00111100
};
const byte smallP[8] = {
  B00000000,
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000
};
const byte smallQ[8] = {
  B00000000,
  B00000000,
  B00111100,
  B01101100,
  B01101100,
  B00111100,
  B00001101,
  B00001111
};
const byte smallR[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100000,
  B01100000
};
const byte smallS[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00111110,
  B01000000,
  B00111100,
  B00000010,
  B01111100
};
const byte smallT[8] = {
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B01111110,
  B00011000,
  B00011000,
  B00011000
};
const byte smallU[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111110
};
const byte smallV[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B01100110,
  B00111100,
  B00011000
};
const byte smallW[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01100011,
  B01101011,
  B01101011,
  B01101011,
  B00111110
};
const byte smallX[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B00111100,
  B00011000,
  B00111100,
  B01100110
};
const byte smallY[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B01100110,
  B00111110,
  B00000110,
  B00111100
};
const byte smallZ[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B00001100,
  B00011000,
  B00110000,
  B00111100
};
const byte space[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};
const byte period[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01100000,
  B01100000
};
const byte comma[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00110000,
  B00110000,
  B01100000
};
const byte colon[8] = {
  B00000000,
  B00000000,
  B00110000,
  B00110000,
  B00000000,
  B00110000,
  B00110000,
  B00000000
};
const byte semiColon[8] = {
  B00000000,
  B00000000,
  B00110000,
  B00110000,
  B00000000,
  B00110000,
  B00110000,
  B01100000
};
const byte exclamation[8] = {
  B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00011000,
  B00000000,
  B00011000
};
const byte question[8] = {
  B00000000,
  B00111100,
  B01100110,
  B00000110,
  B00011100,
  B00011000,
  B00000000,
  B00011000
};

// Convention is to use all upper case names for constant values

// The ascii characters (LETTER_SET) that have binary images defined
const int LED_ROWS = 8;     // The number of rows and columns of LEDs on the 
const int LED_COLUMNS = 8;  // LED matrix
// The ascii characters (letters) that have binary images defined.
const String LETTER_SET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,:;!?";
const unsigned int NUMBER_OF_LETTERS = LETTER_SET.length();
// The locations to find the binary images for the letters, same order as in `LETTER_SET`
const byte *LETTER_ADDRESS[] = {  // The * means that LETTER_ADDRESS is a pointer array to the addresses of its contents
  capA, capB, capC, capD, capE, capF, capG, capH, capI, capJ, capK, capL, capM,
  capN, capO, capP, capQ, capR, capS, capT, capU, capV, capW, capX, capY, capZ,
  smallA, smallB, smallC, smallD, smallE, smallF, smallG, smallH, smallI, smallJ, smallK, smallL, smallM,
  smallN, smallO, smallP, smallQ, smallR, smallS, smallT, smallU, smallV, smallW, smallX, smallY, smallZ,
  number0, number1, number2, number3, number4, number5, number6, number7, number8, number9,
  space, period, comma, colon, semiColon, exclamation, question
};
const unsigned int MAX_MESSAGE_LEN = 100;
const char END_MESSAGE_MARKER = '.';

String workString = "";
String alphaString = "";
unsigned int lengthOfAlphaString = 0;
const byte *alphaAddresses[MAX_MESSAGE_LEN]; // The * means that alphaAddresses is a pointer array to the addresses of its contents
// 'const byte *' says that alphaAddresses[] is an array that references arrays of const bytes.
// IE. what each entry in alphaAddresses refers (points) to can be changed, but what it points to
// can not be changed.

void setup() {
  lc.shutdown(0, false);  // Wake up the display
  lc.setIntensity(0, 5);  // Set the intensity level
  lc.clearDisplay(0);     // Clear the display

  Serial.begin(9600); // Enable access (read and write) to serial port (Serial Monitor)

  Serial.println("Enter message: ");
}


void loop() {
  unsigned int buffer16[LED_ROWS];  // 2 character wide buffer (2 * LED_COLUMNS bits)
  getAlphaString();

  if (lengthOfAlphaString > 0) {
    // Load the first letter into the 2 character buffer, but do not display it yet
    for (int rowNumber = 0; rowNumber < LED_ROWS; rowNumber++) {
      buffer16[rowNumber] = alphaAddresses[0][rowNumber] << LED_COLUMNS;
    }

    for (unsigned int letterNumber = 1; letterNumber < lengthOfAlphaString; letterNumber++){
      // Load the next letter into the 2 character wide buffer
      for (int rowNumber = 0; rowNumber < LED_ROWS; rowNumber++) {
        buffer16[rowNumber] = buffer16[rowNumber] + alphaAddresses[letterNumber][rowNumber];
      }

      // Scroll from the previous character to the current one, by using
      // bit shift, 1 bit less at a time to the right and print to the LED matrix
      for (int columnNumber = LED_COLUMNS; columnNumber > 0; columnNumber--) {
        for (int rowNumber = 0; rowNumber < LED_ROWS; rowNumber++) {
          lc.setRow (0,rowNumber, buffer16[rowNumber] >> columnNumber);
        }
        delay(delayTime);  // Pause before next scroll step
      }

      // Move the current letter into the place of the previous letter (left of buffer)
      for (int rowNumber = 0; rowNumber < LED_ROWS; rowNumber++) {
        buffer16[rowNumber] = buffer16[rowNumber] << LED_COLUMNS;
      }
    }
  }
}

void printBits8(byte myByte) {
  Serial.print("0b");
  for(byte mask = 0x80; mask; mask >>= 1) {
    if(mask & myByte) {
      Serial.print('1');
    } else {
      Serial.print('0');
    }
  }
//  Serial.println();
}


void printBits16(unsigned int myInt) {
  Serial.print("0b");
  for(unsigned int mask = 0x8000; mask; mask >>= 1) {
    if(mask & myInt) {
      Serial.print('1');
    } else {
      Serial.print('0');
    }
  }
//  Serial.println();
}

/** 
 * Collect text for the message to be scrolled
 * 
 * Populates array of character images to be scrolled
 */
void getAlphaString() {
  char workChar = 0;

  while(Serial.available()) {
    workChar = Serial.read();   // Get the (next) character.
    if(workChar != END_MESSAGE_MARKER) {
      workString += workChar;
      if(workString.length() > MAX_MESSAGE_LEN) {
        workString = "";  // Clear the too large text string
        alphaString = "ERROR: Message must contain fewer than " +
          String(MAX_MESSAGE_LEN) + " characters. ";
        Serial.print(alphaString);
        if(alphaString.length() > MAX_MESSAGE_LEN) {
          alphaString.remove(MAX_MESSAGE_LEN);
        }
        lengthOfAlphaString = alphaString.length();
        break;  // Abort collecting more content for the current message
      }
    } else {  // end of message marker found
      if(workString.length() == 0) {  // Empty message, ignore the marker
        break;
      }
      if(workString.length() < MAX_MESSAGE_LEN) {
        if(workString[workString.length() - 1] != ' ') {  // if it does not already have one
          workString += ' ';  // add a space to the end of the message.
        }
      }
      alphaString = workString;
      lengthOfAlphaString = alphaString.length();
      Serial.print("Full message is \"");
      Serial.print(alphaString);
      Serial.println("\"");

      // Setup so ready to start collecting text for the next message.
      workString = "";
      Serial.println("\nEnter new message: ");
    }
  }
  if (lengthOfAlphaString > 0) {  // When have new message text
    getAddresses();  // Populate the array of character images
  }
}


/**
 * Populates array of character images matching message text
 */
void getAddresses() {
  for (unsigned int i = 0; i < lengthOfAlphaString; i++) {
    alphaAddresses[i] = 0;
    for (unsigned int j = 0; j < NUMBER_OF_LETTERS; j++) {
      if (alphaString[i] == LETTER_SET[j]) {
        alphaAddresses[i] = LETTER_ADDRESS[j];
        break;  // Found the matching character image, stop looking
      }
    }
    if (alphaAddresses[i] == 0) {
      char badChar = alphaString[i];  // character that no image data exists for
      alphaString = "ERROR:  Invalid Character ";
      Serial.print(alphaString);
      Serial.print("\"");
      Serial.write(badChar);  // The numeric value 'writes' as the actual character
      Serial.println("\"");
      if(alphaString.length() > MAX_MESSAGE_LEN) {  // Safety check, incase using small buffer
        alphaString.remove(MAX_MESSAGE_LEN);  // Truncate scrolling message to maximum size
      }
      lengthOfAlphaString = alphaString.length();
      // Recusive call: a little risky, if the error message could cause another
      // `invalid character` error.
      getAddresses();  // Scroll the error message instead
    }
  }
}
