/*
 * Sensor.h
 *
 *  Created on: May 25, 2016
 *      Author: attilio
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include<cstdlib>
#include "Buffer.h"

class Sensor {
 public:
	Sensor(float);
	virtual ~Sensor();
	void read(int);
 protected:
	// Uppercase -> constant parameters in order to test the class
	float _MIN_RAND, _MAX_RAND;
	float _RANGE;
	unsigned int _SAMPLES;
	const char * _FILENAME;

	float _threshold;
	unsigned int _samplesCounter; // after the triggering of the threshold
	bool _recording;
	Buffer * _buffer;
	bool isRecordingCompleted();
	bool isAboveThreshold(float);
	bool isRecording();
	void initSamplesCounter();
	void decrSamplesCounter();
	void turnOnRecording();
	void turnOffRecording();
	void writeSamplesTriggered();
	virtual float readsensor();
};

#endif /* SENSOR_H_ */
