#pragma once

#include <DallasTemperature.h>
#include "pinMapping.h"

class MQ2
{
public:
	MQ2();
	int read_sensor();
};