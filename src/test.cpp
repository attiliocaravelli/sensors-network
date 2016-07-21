//============================================================================
// Name        : main.cpp
// Author      : Attilio Caravelli
// Version     :
// Copyright   : GPL
// Description : Test sensor reading function in C++, Ansi-style
//============================================================================

#include "Sensor.h"

int main() {
	float threshold = 2.5;
	unsigned int numSamples = 10000;
	Sensor * s = new Sensor(threshold);
	s->read(numSamples);
	delete s;
	return 0;
}
