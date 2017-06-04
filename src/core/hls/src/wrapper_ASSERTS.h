#ifndef WRAPPER_ASSERTS_H
#define WRAPPER_ASSERTS_H

#include <ap_int.h>
#include <hls_stream.h>
#include "typeAsserts.h"

const int ASSERTS_BUS_WIDTH_BYTES = 4; //int

static char ID_ASSERTS=11;


///// EQ /////

///////////////////////////////////////////////////////////////////////
//                 Function:   callCount
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_ASSERT_FLOAT_EQ_callCount = 3;
static unsigned char ID_ASSERT_FLOAT_EQ_callCount = 23;

//static int assert_FLOAT_EQ_callCount = 0;

//const int ASSERT_FLOAT_EQ_CALLCOUNT_WRITE_SIZE_BYTES = 4; //int

struct RETURN_ASSERT_FLOAT_EQ_callCount{
  unsigned int _return;
  // here padding if its necessary
}__attribute__((packed));

static struct RETURN_ASSERT_FLOAT_EQ_callCount ret_ASSERT_FLOAT_EQ_callCount;

void running_ASSERT_FLOAT_EQ_callCount(hls::stream<unsigned int> &dst, unsigned int &assert_FLOAT_EQ_callCount);
//////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                 Function:   failureCount
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_ASSERT_FLOAT_EQ_callCount = 3;
static unsigned char ID_ASSERT_FLOAT_EQ_failureCount = 24;

//static int assert_FLOAT_EQ_callCount = 0;

//const int ASSERT_FLOAT_EQ_CALLCOUNT_WRITE_SIZE_BYTES = 4; //int

struct RETURN_ASSERT_FLOAT_EQ_failureCount{
  unsigned int _return;
  // here padding if its necessary
}__attribute__((packed));

static struct RETURN_ASSERT_FLOAT_EQ_failureCount ret_ASSERT_FLOAT_EQ_failureCount;

void running_ASSERT_FLOAT_EQ_failureCount(hls::stream<unsigned int> &dst, unsigned int &assert_FLOAT_EQ_failureCount);
//////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                 Function:   failures
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_ASSERT_FLOAT_EQ_failures = 6;
static unsigned char ID_ASSERT_FLOAT_EQ_failures = 26;

//const int ASSERT_FLOAT_EQ_CALLTIME_WRITE_SIZE_BYTES = 4; //int

/* struct RETURN_ASSERT_FLOAT_EQ_failures{ */
/*   unsigned int  */
/*   unsigned int _callCount; */
/*   tASSERT_FLOAT_EQ_PARAM _param; */
/*   tASSERT_FLOAT_EQ_PARAM _expect; */
/*   int _time; */
/*   // here padding if its necessary */
/* }__attribute__((packed)); */


//static tASSERT_FLOAT_EQ_FAILURE assert_FLOAT_EQ_failures[32];
static char assertFLOAT_EQ_failures_rd_index = 0;

static tASSERT_FLOAT_FAILURE ret_ASSERT_FLOAT_EQ_failures;

//void running_ASSERT_FLOAT_EQ_failures(hls::stream<unsigned int> &dst);//, hls::stream<tfailure> &assert_FLOAT_EQ_failures);
void running_ASSERT_FLOAT_EQ_failures(hls::stream<unsigned int> &dst, hls::stream<tASSERT_FLOAT_FAILURE> &assert_FLOAT_EQ_failures);
//////////////////////////////////////////////////////////////////////



///// LT /////

///////////////////////////////////////////////////////////////////////
//                 Function:   callCount
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_ASSERT_FLOAT_LT_callCount = 3;
static unsigned char ID_ASSERT_FLOAT_LT_callCount = 43;

//static int assertFLOAT_LT_callCount = 0;

//const int ASSERT_FLOAT_LT_CALLCOUNT_WRITE_SIZE_BYTES = 4; //int

struct RETURN_ASSERT_FLOAT_LT_callCount{
  unsigned int _return;
  // here padding if its necessary
}__attribute__((packed));

static struct RETURN_ASSERT_FLOAT_LT_callCount ret_ASSERT_FLOAT_LT_callCount;

void running_ASSERT_FLOAT_LT_callCount(hls::stream<unsigned int> &dst, unsigned int &assertFLOAT_LT_callCount);
//////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                 Function:   failureCount
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_ASSERT_FLOAT_LT_callCount = 3;
static unsigned char ID_ASSERT_FLOAT_LT_failureCount = 44;

//static int assertFLOAT_LT_callCount = 0;

//const int ASSERT_FLOAT_LT_CALLCOUNT_WRITE_SIZE_BYTES = 4; //int

struct RETURN_ASSERT_FLOAT_LT_failureCount{
  unsigned int _return;
  // here padding if its necessary
}__attribute__((packed));

static struct RETURN_ASSERT_FLOAT_LT_failureCount ret_ASSERT_FLOAT_LT_failureCount;

void running_ASSERT_FLOAT_LT_failureCount(hls::stream<unsigned int> &dst, unsigned int &assertFLOAT_LT_failureCount);
//////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////
//                 Function:   failures
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_ASSERT_FLOAT_LT_failures = 6;
static unsigned char ID_ASSERT_FLOAT_LT_failures = 46;

//const int ASSERT_FLOAT_LT_CALLTIME_WRITE_SIZE_BYTES = 4; //int

/* struct RETURN_ASSERT_FLOAT_LT_failures{ */
/*   unsigned int  */
/*   unsigned int _callCount; */
/*   tASSERT_FLOAT_LT_PARAM _param; */
/*   tASSERT_FLOAT_LT_PARAM _expect; */
/*   int _time; */
/*   // here padding if its necessary */
/* }__attribute__((packed)); */


//static tASSERT_FLOAT_LT_FAILURE assertFLOAT_LT_failures[32];
static char assertFLOAT_LT_failures_rd_index = 0;

static tASSERT_FLOAT_FAILURE ret_ASSERT_FLOAT_LT_failures;

//void running_ASSERT_FLOAT_LT_failures(hls::stream<unsigned int> &dst);//, hls::stream<tfailure> &assertFLOAT_LT_failures);
void running_ASSERT_FLOAT_LT_failures(hls::stream<unsigned int> &dst, hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_LT_failures);
//////////////////////////////////////////////////////////////////////


#endif
