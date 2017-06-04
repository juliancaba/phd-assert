// -*- coding: utf-8; mode: c++; tab-width: 4 -*-

#include "asserts.h"


void 
ASSERT_FLOAT_EQ_IMPL(hls::stream<unsigned int> &timeClock,
					 hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_EQ_failures,
					 unsigned int &assertFLOAT_EQ_failureCount,
					 unsigned int &assertFLOAT_EQ_callCount,
					 float x,
					 float y)
{
#pragma HLS RESET variable=assertFLOAT_EQ_callCount
#pragma HLS RESET variable=assertFLOAT_EQ_failureCount
#pragma HLS RESET variable=assertFLOAT_EQ_failures
#pragma HLS STREAM variable=assertFLOAT_EQ_failures depth=32
  bool _exp;
  unsigned int _time;
  tASSERT_FLOAT_FAILURE _auxFailure;
  
  _time = timeClock.read();
  _exp = (x!=y);

  if(_exp){
	_auxFailure._callTime = _time;
	_auxFailure._callCount = assertFLOAT_EQ_callCount;
	_auxFailure._x = x;
	_auxFailure._y = y;
	assertFLOAT_EQ_failures.write(_auxFailure);
	assertFLOAT_EQ_failureCount +=1;
  }
  assertFLOAT_EQ_callCount += 1;
}


void 
ASSERT_FLOAT_LT_IMPL(hls::stream<unsigned int> &timeClock,
		     hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_LT_failures,
		     unsigned int &assertFLOAT_LT_failureCount,
		     unsigned int &assertFLOAT_LT_callCount,
		     float x,
		     float y)
{
#pragma HLS RESET variable=assertFLOAT_LT_callCount
#pragma HLS RESET variable=assertFLOAT_LT_failureCount
#pragma HLS RESET variable=assertFLOAT_LT_failures
#pragma HLS STREAM variable=assertFLOAT_LT_failures depth=32
  bool _exp;
  unsigned int _time;
  tASSERT_FLOAT_FAILURE _auxFailure;
  
  _time = timeClock.read();
  _exp = (x>=y);

  if(_exp){
	_auxFailure._callTime = _time;
	_auxFailure._callCount = assertFLOAT_LT_callCount;
	_auxFailure._x = x;
	_auxFailure._y = y;
	assertFLOAT_LT_failures.write(_auxFailure);
	assertFLOAT_LT_failureCount +=1;
  }
  assertFLOAT_LT_callCount += 1;
}


