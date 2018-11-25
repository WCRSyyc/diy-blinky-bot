#include <LedControl.h>

const unsigned int LC_DATA_IN = 12;
const unsigned int LC_CLK = 11;
const unsigned int LC_LOAD = 10;
const unsigned int LC_NUM_DEVICES = 2;
const int LEFT_ADDR = 0;
const int RIGHT_ADDR = 1;
const int MAT_BRIGHTNESS = 7; // 0 .. 15 = min .. max

const int BLINK_PIN = 13;
const unsigned long FRAME_DELAY = 300; // milliseconds

LedControl lc1 = LedControl(LC_DATA_IN, LC_CLK, LC_LOAD, LC_NUM_DEVICES);
byte frame0[] = {B11111111, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111};
byte frame1[] = {B00000000, B01111110, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000};

boolean blinkState = false;

void setup() {
  lc1.shutdown(LEFT_ADDR, false); // wake up from power saving mode
  lc1.shutdown(RIGHT_ADDR, false);
  lc1.setIntensity(LEFT_ADDR, MAT_BRIGHTNESS);
  lc1.setIntensity(RIGHT_ADDR, MAT_BRIGHTNESS);

  pinMode(BLINK_PIN, OUTPUT);
}

void loop() {
  blinkState = !blinkState;
  if(blinkState) {
    digitalWrite(BLINK_PIN, HIGH); // Show when frame should change
    showFrame(lc1, LEFT_ADDR, frame0);
    showFrame(lc1, RIGHT_ADDR, frame1);
  } else {
    digitalWrite(BLINK_PIN, LOW);
    showFrame(lc1, LEFT_ADDR, frame1);
    showFrame(lc1, RIGHT_ADDR, frame0);
  }
  delay(FRAME_DELAY);
}

/**
 Show a frame (image) that controls every LED of an 8 by 8 LED matrix

 @oaram lc LedControl instance
 @param addr address of the 72xx chip
 @param frame array of 8 bit patterns, one for each row
 */
void showFrame(LedControl lc, const int addr, const byte * frame) {
  for(int row = 0; row < 8; row++) {
    lc.setRow(addr, row, frame[row]);
  }
}
