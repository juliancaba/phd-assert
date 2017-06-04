#ifndef VECTOR_NORM_H
#define VECTOR_NORM_H

const static short HIST_SIZE=16;

#include <hls_stream.h>
#include "typeAsserts.h"

#define l2norm(histIN, histOUT) l2norm_assert(histIN, histOUT, timeClock, assertFLOAT_EQ_callCount, assertFLOAT_EQ_failureCount, assertFLOAT_EQ_failures, assertFLOAT_LT_callCount, assertFLOAT_LT_failureCount, assertFLOAT_LT_failures)

float sum_hist_pow(float histIN[HIST_SIZE]);
float scale2(float sum);
void mult_hist_scale(float histAUX[HIST_SIZE], float scale, float histOUT[HIST_SIZE]);
//void l2norm(float histIN[HIST_SIZE], float histOUT[HIST_SIZE]);

void l2norm_assert(float histIN[HIST_SIZE], float histOUT[HIST_SIZE],
		   hls::stream<unsigned int> &timeClock,
		   unsigned int &assertFLOAT_EQ_callCount,
		   unsigned int &assertFLOAT_EQ_failureCount,
		   hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_EQ_failures,
		   unsigned int &assertFLOAT_LT_callCount,
		   unsigned int &assertFLOAT_LT_failureCount,
		   hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_LT_failures);
#endif
