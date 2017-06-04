#ifndef TOPTESTING_H
#define TOPTESTING_H

#include "header.h"

#include "typeAsserts.h"
#include <hls_stream.h>


static struct headerStruct header_OBJ;

static hls::stream<unsigned int> bufferIN_OBJ;
static hls::stream<unsigned int> bufferOUT_OBJ;
static hls::stream<unsigned int> bufferRESP_OBJ;

static hls::stream<tASSERT_FLOAT_FAILURE> assertFLOAT_EQ_failures;
unsigned int assertFLOAT_EQ_callCount;
unsigned int assertFLOAT_EQ_failureCount;

static hls::stream<tASSERT_FLOAT_FAILURE> assertFLOAT_LT_failures;
static unsigned int assertFLOAT_LT_callCount;
static unsigned int assertFLOAT_LT_failureCount;


void inputBuffer_OBJ(hls::stream<unsigned int> &src);
void outputBuffer_OBJ(hls::stream<unsigned int> &dst);
void forward_OBJ(short size);

void getRequestHead_OBJ();
void buildResponseHead_OBJ(hls::stream<unsigned int> &dst,
		       unsigned short objID, unsigned short size, 
		       unsigned char flags);
void
buildResponse_OBJ(unsigned short objID, unsigned short size,
		  unsigned char flags);

void topTesting(hls::stream<unsigned int> din, hls::stream<unsigned int> dout,
		hls::stream<unsigned int> timeClock);
void manager_OBJ(hls::stream<unsigned int> &timeClock);

#endif
