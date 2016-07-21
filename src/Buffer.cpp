/*
 * Buffer.cpp
 *
 *  Created on: May 25, 2016
 *      Author: attilio
 */

#include<assert.h>
#include "Buffer.h"

Buffer::Buffer (unsigned int nelements){
	assert(nelements > 0);
	_nelements = nelements;
    _buffer = new std::deque<float>(_nelements);
    _outfile = new std::ofstream();
}

Buffer::~Buffer (){
    delete _buffer;
    delete _outfile;
}

void Buffer::push(float element){
	if( _buffer != NULL ) {
		if (isBufferFull()) _buffer->pop_back();
		_buffer->push_front(element);
	}
}

void Buffer::toFile(const char * filename){
	assert(filename != NULL);
	_outfile->open(filename, std::ios_base::app);
	if (_outfile->is_open())
	{
	 for (std::deque<float>::iterator it = _buffer->begin(); it!=_buffer->end(); ++it) {
		(*_outfile) << *it << std::endl;
	 }
	 _outfile->close();
	}
}

bool Buffer::isBufferFull(){
	return _buffer->size() >= _nelements;
}

void Buffer::clear(){
	_buffer->clear();
}

