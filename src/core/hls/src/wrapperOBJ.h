#ifndef WRAPPEROBJ_H
#define WRAPPEROBJ_H


//#include <ap_int.h>
#include <hls_stream.h>

#include "vector_norm.h"

const int OBJ_BUS_WIDTH_BYTES = 4; //int

static unsigned char ID_OBJ=1;


///////////////////////////////////////////////////////////////////////
//                 Function:   l2norm
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_l2norm = 7;
static unsigned char ID_OBJ_l2norm = 7;

const int OBJ_L2NORM_READ_SIZE_BYTES = 4; //int
const int OBJ_L2NORM_WRITE_SIZE_BYTES = 4; //int

#define testing_OBJ_l2norm(src, dst) testing_OBJ_l2norm_assert(src, dst, timeClock, assertFLOAT_EQ_callCount, assertFLOAT_EQ_failureCount, assertFLOAT_EQ_failures, assertFLOAT_LT_callCount, assertFLOAT_LT_failureCount, assertFLOAT_LT_failures)

struct PARAM_OBJ_l2norm{
  float histIN[HIST_SIZE];
  // here padding if its necessary
}__attribute__((packed));


struct RETURN_OBJ_l2norm{
  float histOUT[HIST_SIZE];
  // here padding if its necessary
}__attribute__((packed));

static struct PARAM_OBJ_l2norm  args_OBJ_l2norm;
static struct RETURN_OBJ_l2norm  ret_OBJ_l2norm;

//void testing_OBJ_l2norm(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst);
void testing_OBJ_l2norm_assert(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst,
			       hls::stream<unsigned int> &timeClock,
			       unsigned int &assertFLOAT_EQ_callCount,
			       unsigned int &assertFLOAT_EQ_failureCount,
			       hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_EQ_failures,
			       unsigned int &assertFLOAT_LT_callCount,
			       unsigned int &assertFLOAT_LT_failureCount,
			       hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_LT_failures);
void readParameters_OBJ_l2norm(hls::stream<unsigned int> &src);
void writeReturn_OBJ_l2norm(hls::stream<unsigned int> &dst);
//////////////////////////////////////////////////////////////////////



#endif
