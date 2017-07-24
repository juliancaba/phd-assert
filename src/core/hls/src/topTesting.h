#ifndef TOPTESTING_H
#define TOPTESTING_H

#include "header.h"

#include "typeAsserts.h"
#include <hls_stream.h>


static struct headerStruct header_OBJ;

static hls::stream<unsigned int> bufferRESP_OBJ;

static hls::stream<tASSERT_FLOAT_FAILURE> assertFLOAT_EQ_failures;
static unsigned int assertFLOAT_EQ_callCount = 0;
static unsigned int assertFLOAT_EQ_failureCount = 0;

static hls::stream<tASSERT_FLOAT_FAILURE> assertFLOAT_LT_failures;
static unsigned int assertFLOAT_LT_callCount = 0;
static unsigned int assertFLOAT_LT_failureCount = 0;


void forward_OBJ(hls::stream<unsigned int> &src, short size);

void getRequestHead_OBJ(hls::stream<unsigned int> &src);
void buildResponse_OBJ(hls::stream<unsigned int> &dst,
		       unsigned short objID, unsigned short size, 
		       unsigned char flags);

void topTesting(hls::stream<unsigned int> din, hls::stream<unsigned int> dout,
		hls::stream<unsigned int> timeClock);

#endif
