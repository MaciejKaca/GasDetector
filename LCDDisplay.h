#include <LiquidCrystal_I2C.h>

class LCDDisplay
{
private:
    const struct {
        int height;
        int width;
    } size = {2, 16};

    // @param      En[in] LCD En (Enable) pin connected to the IO extender module
    // @param      Rw[in] LCD Rw (Read/write) pin connected to the IO extender module
    // @param      Rs[in] LCD Rs (Reset) pin connected to the IO extender module
    // @param      d4[in] LCD data 0 pin map on IO extender module
    // @param      d5[in] LCD data 1 pin map on IO extender module
    // @param      d6[in] LCD data 2 pin map on IO extender module
    // @param      d7[in] LCD data 3 pin map on IO extender module
    static const uint8_t En = 2, Rw = 1, Rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, backlighPin = 3;
    static const t_backlightPol pol = POSITIVE;

    const LiquidCrystal_I2C lcd;
    String text[size.height];

public:
    // @param      lcd_Addr[in] I2C address of the IO expansion module. For I2CLCDextraIO,
    // the address can be configured using the on board jumpers.
    LCDDisplay(const byte lcd_Addr) : lcd(lcd_Addr, En, Rw, Rs, d4, d5, d6, d7, backlighPin, pol)
    {
        lcd.begin(size.height, size.width);
        lcd.backlight();
    }

    void printMessage(String message, byte line);
};

void LCDDisplay::printMessage(String messsage, byte line)
{
    const int messageLenght = messsage.length();

    // Refresh lcd only if the new message is longer
    if(messageLenght > text[line])
    {
        lcd.clear();
    }

    text[line] = messsage;

    for(int i=0; i < size.width; i++)
    {
        lcd.setCursor(0, i);
        lcd.print(text[i]);
    }
}