#include "NewLCD.h"
#include "MQ2.h"
#include <LiquidCrystal_I2C.h>

NewLCD lcd(0x27);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  //LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
}
