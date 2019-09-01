#include "MQ2.h"

MQ2::MQ2()
{
}

int MQ2::read_sensor()
{
	return analogRead(MQ2_PIN);
}