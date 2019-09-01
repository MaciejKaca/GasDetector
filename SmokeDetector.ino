#include "LCDDisplay.h"
#include "MQ2.h"
#include "temperatureSensor.h"

LCDDisplay *lcd;
MQ2 smokeDetector;
temperatureSensor tempSensor;

void setup()
{
	Serial.begin (9600);
	lcd = new LCDDisplay(LCD_PIN);
}

void loop()
{
	lcd->printMessage("MQ2: " + String(smokeDetector.read_sensor()), 0);
	lcd->printMessage(String(tempSensor.read_sensor()) + " C", 1);
}
