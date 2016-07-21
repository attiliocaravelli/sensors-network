/*
 * Buffer.h
 *
 *  Created on: May 25, 2016
 *      Author: attilio
 */
#ifndef BUFFER_H_
#define BUFFER_H_

#include <deque>
#include <iostream>
#include <fstream>
using namespace std;

class Buffer{
 public:
	Buffer(unsigned int);
	virtual ~Buffer();
	void push(float);
	void toFile(const char *);
	bool isBufferFull();
	void clear();
 protected:
	std::deque<float> * _buffer;
	std::ofstream * _outfile;
	unsigned int _nelements;
};

#endif /* BUFFER_H_ */
