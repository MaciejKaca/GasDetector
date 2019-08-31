#include <DallasTemperature.h>
#include "pinMapping.h"

class MQ2
{
public:
    MQ2();
    int read_sensor();
};

int MQ2::read_sensor()
{
    return analogRead(MQ2_PIN);
}