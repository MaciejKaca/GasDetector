#include "LCDDisplay.h"

void LCDDisplay::printMessage(String messsage, byte line)
{
	const int messageLenght = messsage.length();

	// Refresh lcd only if the new message is longer
	if (messageLenght < text[line].length())
	{
		lcd.clear();
	}

	text[line] = messsage;

	for (int i = 0; i < height; i++)
	{
		lcd.setCursor(0, i);
		lcd.print(text[i]);
	}
}