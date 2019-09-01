#pragma once

#include <OneWire.h>
#include <DallasTemperature.h>
#include "pinMapping.h"

class temperatureSensor
{
private:
    OneWire onewire;
    DallasTemperature sensors;
public:
    temperatureSensor() : onewire(TEMPERATURE_SENSOR_PIN), sensors(&onewire)
    {
        sensors.begin();
    }
    
    float read_sensor();
};