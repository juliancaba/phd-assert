// -*- coding: utf-8; mode: c++; tab-width: 4 -*-

#include "vector_norm.h"
#include <cmath>

#include "hls_math.h"

#include "asserts.h"

static float histAUX_1 [HIST_SIZE];

float
sum_hist_pow(float histIN[HIST_SIZE])
{
  float sum = 0.f;
  float inAUX;

  inAUX = histIN[0];
 loop1:for(int i = 0; i != HIST_SIZE; i++){
	sum += inAUX*inAUX;	  
	histAUX_1[i] = inAUX;
    if (i < HIST_SIZE-1)
      inAUX = histIN[i+1];
  }
  return sum;
}


float
scale2(float sum)
{
#ifndef POSIX
  return hls::recipf(sqrtf(sum)+1.6f);
#else
  return 1.f/(sqrtf(sum)+1.6f);
#endif
}



void
mult_hist_scale(float histAUX[HIST_SIZE], float scale, float histOUT[HIST_SIZE])
{
 loop2:for(int i = 0; i != HIST_SIZE; i++)
    histOUT[i] = histAUX[i]*scale;
}


// void
// l2norm(float histIN[HIST_SIZE], float histOUT[HIST_SIZE])
void l2norm_assert(float histIN[HIST_SIZE], float histOUT[HIST_SIZE],
				   hls::stream<unsigned int> &timeClock,
				   unsigned int &assertFLOAT_EQ_callCount,
				   unsigned int &assertFLOAT_EQ_failureCount,
				   hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_EQ_failures,
				   unsigned int &assertFLOAT_LT_callCount,
				   unsigned int &assertFLOAT_LT_failureCount,
				   hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_LT_failures)
{
  float scale = 0.f;
  float sum = 0.f;
  
  sum = sum_hist_pow(histIN);
  ASSERT_FLOAT_EQ(sum, 1240.0);
  ASSERT_FLOAT_EQ(sum, 1.0);
  scale = scale2(sum);
  ASSERT_FLOAT_LT(scale, 1.0);
  mult_hist_scale(histAUX_1, scale, histOUT);
}

