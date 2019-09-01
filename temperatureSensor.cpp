#include "temperatureSensor.h"

float temperatureSensor::read_sensor()
{
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0);
}