#ifndef ASSERTS_H
#define ASSERTS_H

#include "typeAsserts.h"
#include <hls_stream.h>

#define ASSERT_FLOAT_EQ(x, y) ASSERT_FLOAT_EQ_IMPL(timeClock, assertFLOAT_EQ_failures, assertFLOAT_EQ_failureCount, assertFLOAT_EQ_callCount, x, y)

void 
ASSERT_FLOAT_EQ_IMPL(hls::stream<unsigned int> &timeClock,
		     hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_EQ_failures,
		     unsigned int &assertFLOAT_EQ_failureCount,
		     unsigned int &assertFLOAT_EQ_callCount,
		     float x,
		     float y);


#define ASSERT_FLOAT_LT(x, y) ASSERT_FLOAT_LT_IMPL(timeClock, assertFLOAT_LT_failures, assertFLOAT_LT_failureCount, assertFLOAT_LT_callCount, x, y)


void 
ASSERT_FLOAT_LT_IMPL(hls::stream<unsigned int> &timeClock,
		     hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_LT_failures,
		     unsigned int &assertFLOAT_LT_failureCount,
		     unsigned int &assertFLOAT_LT_callCount,
		     float x,
		     float y);

#endif
