/*
 * Sensor.cpp
 *
 *  Created on: May 25, 2016
 *      Author: attilio
 */

#include<assert.h>
#include "Sensor.h"

Sensor::Sensor(float threshold) {
	//initTestParameters
	_MIN_RAND = 2.0, _MAX_RAND = 6.0;
	_RANGE = _MAX_RAND - _MIN_RAND;
	_SAMPLES = 10;
	_FILENAME = "samples.txt";

	_recording = false;
	_samplesCounter = 0;
	_threshold = threshold;
	_buffer = new Buffer(2 * _SAMPLES + 1);
}

Sensor::~Sensor() {
	delete _buffer;
}

void Sensor::read(int samples) {
	assert(samples > 0);
	while (samples > 0) {
		float data = readsensor();
		_buffer->push(data);
		if (isRecording()) {
			if (isRecordingCompleted()) {
				turnOffRecording();
				writeSamplesTriggered();
			}
			else decrSamplesCounter();
		}
		if (!isRecording() && isAboveThreshold(data)) turnOnRecording();
		--samples;
	}
}

float Sensor::readsensor() {
	return _RANGE * ((((float) rand()) / (float) RAND_MAX)) + _MIN_RAND ;
}

bool Sensor::isRecordingCompleted() {
	return _samplesCounter == 0;
}

bool Sensor::isRecording() {
	return _recording;
}

bool Sensor::isAboveThreshold(float data) {
	return (data > _threshold);
}

void Sensor::decrSamplesCounter() {
	--_samplesCounter;
}

void Sensor::initSamplesCounter() {
	_samplesCounter = _SAMPLES;
}

void Sensor::turnOnRecording() {
	initSamplesCounter();
	_recording = true;
}

void Sensor::turnOffRecording() {
	_recording = false;
}

void Sensor::writeSamplesTriggered() {
	_buffer->toFile(_FILENAME);
}
