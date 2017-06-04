#include "wrapper_ASSERTS.h"

#include "hls_casting.h"



///////////////////////////////////////////////////////////////////////
//                  Function:   callCount
//////////////////////////////////////////////////////////////////////
union UNION_RET_ASSERT_FLOAT_EQ_callCount{
  unsigned int words32[sizeof(ret_ASSERT_FLOAT_EQ_callCount)/sizeof(int)];
  unsigned short words16[sizeof(ret_ASSERT_FLOAT_EQ_callCount)/sizeof(short)];
  unsigned char words8[sizeof(ret_ASSERT_FLOAT_EQ_callCount)];
}byteRet_ASSERT_FLOAT_EQ_callCount;


void
running_ASSERT_FLOAT_EQ_callCount(hls::stream<unsigned int> &dst, unsigned int &assertFLOAT_EQ_callCount)
{
  short index = 0;
  unsigned int ptr_return;
  ptr_return = assertFLOAT_EQ_callCount;
  byteRet_ASSERT_FLOAT_EQ_callCount.words32[index++] = ptr_return;

  for(int itReturn=0; itReturn != sizeof(byteRet_ASSERT_FLOAT_EQ_callCount.words32)/ASSERTS_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_ASSERT_FLOAT_EQ_callCount.words32[itReturn]);
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   failureCount
//////////////////////////////////////////////////////////////////////
union UNION_RET_ASSERT_FLOAT_EQ_failureCount{
  unsigned int words32[sizeof(ret_ASSERT_FLOAT_EQ_failureCount)/sizeof(int)];
  unsigned short words16[sizeof(ret_ASSERT_FLOAT_EQ_failureCount)/sizeof(short)];
  unsigned char words8[sizeof(ret_ASSERT_FLOAT_EQ_failureCount)];
}byteRet_ASSERT_FLOAT_EQ_failureCount;


void
running_ASSERT_FLOAT_EQ_failureCount(hls::stream<unsigned int> &dst, unsigned int &assertFLOAT_EQ_failureCount)
{
  short index = 0;
  unsigned int ptr_return;
  ptr_return = assertFLOAT_EQ_failureCount;
  byteRet_ASSERT_FLOAT_EQ_failureCount.words32[index++] = ptr_return;

  for(int itReturn=0; itReturn != sizeof(byteRet_ASSERT_FLOAT_EQ_failureCount.words32)/ASSERTS_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_ASSERT_FLOAT_EQ_failureCount.words32[itReturn]);
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   failures
//////////////////////////////////////////////////////////////////////
union UNION_RET_ASSERT_FLOAT_EQ_failures{
  unsigned int words32[sizeof(ret_ASSERT_FLOAT_EQ_failures)/sizeof(int)];
  unsigned short words16[sizeof(ret_ASSERT_FLOAT_EQ_failures)/sizeof(short)];
  unsigned char words8[sizeof(ret_ASSERT_FLOAT_EQ_failures)];
}byteRet_ASSERT_FLOAT_EQ_failures;


void
running_ASSERT_FLOAT_EQ_failures(hls::stream<unsigned int> &dst, hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_EQ_failures)
{
  short index = 0;
  tASSERT_FLOAT_FAILURE auxFailure;

  auxFailure = assertFLOAT_EQ_failures.read();


  unsigned int ptr_callCount;
  ptr_callCount = auxFailure._callCount;
  byteRet_ASSERT_FLOAT_EQ_failures.words32[index++] = ptr_callCount;

  unsigned int ptr_time;
  ptr_time = auxFailure._callTime;
  byteRet_ASSERT_FLOAT_EQ_failures.words32[index++] = ptr_time;

  unsigned int ptr_x[1];
  toSequence(auxFailure._x, ptr_x);
  byteRet_ASSERT_FLOAT_EQ_failures.words32[index++] = ptr_x[0];

  unsigned int ptr_y[1];
  toSequence(auxFailure._y, ptr_y);
  byteRet_ASSERT_FLOAT_EQ_failures.words32[index++] = ptr_y[0];

  for(int itReturn=0; itReturn != sizeof(byteRet_ASSERT_FLOAT_EQ_failures.words32)/ASSERTS_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_ASSERT_FLOAT_EQ_failures.words32[itReturn]);

  assertFLOAT_EQ_failures_rd_index += 1;
}
///////////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////////////
//                  Function:   callCount
//////////////////////////////////////////////////////////////////////
union UNION_RET_ASSERT_FLOAT_LT_callCount{
  unsigned int words32[sizeof(ret_ASSERT_FLOAT_LT_callCount)/sizeof(int)];
  unsigned short words16[sizeof(ret_ASSERT_FLOAT_LT_callCount)/sizeof(short)];
  unsigned char words8[sizeof(ret_ASSERT_FLOAT_LT_callCount)];
}byteRet_ASSERT_FLOAT_LT_callCount;


void
running_ASSERT_FLOAT_LT_callCount(hls::stream<unsigned int> &dst, unsigned int &assertFLOAT_LT_callCount)
{
  short index = 0;
  unsigned int ptr_return;
  ptr_return = assertFLOAT_LT_callCount;
  byteRet_ASSERT_FLOAT_LT_callCount.words32[index++] = ptr_return;

  for(int itReturn=0; itReturn != sizeof(byteRet_ASSERT_FLOAT_LT_callCount.words32)/ASSERTS_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_ASSERT_FLOAT_LT_callCount.words32[itReturn]);
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   failureCount
//////////////////////////////////////////////////////////////////////
union UNION_RET_ASSERT_FLOAT_LT_failureCount{
  unsigned int words32[sizeof(ret_ASSERT_FLOAT_LT_failureCount)/sizeof(int)];
  unsigned short words16[sizeof(ret_ASSERT_FLOAT_LT_failureCount)/sizeof(short)];
  unsigned char words8[sizeof(ret_ASSERT_FLOAT_LT_failureCount)];
}byteRet_ASSERT_FLOAT_LT_failureCount;


void
running_ASSERT_FLOAT_LT_failureCount(hls::stream<unsigned int> &dst, unsigned int &assertFLOAT_LT_failureCount)
{
  short index = 0;
  unsigned int ptr_return;
  ptr_return = assertFLOAT_LT_failureCount;
  byteRet_ASSERT_FLOAT_LT_failureCount.words32[index++] = ptr_return;

  for(int itReturn=0; itReturn != sizeof(byteRet_ASSERT_FLOAT_LT_failureCount.words32)/ASSERTS_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_ASSERT_FLOAT_LT_failureCount.words32[itReturn]);
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   failures
//////////////////////////////////////////////////////////////////////
union UNION_RET_ASSERT_FLOAT_LT_failures{
  unsigned int words32[sizeof(ret_ASSERT_FLOAT_LT_failures)/sizeof(int)];
  unsigned short words16[sizeof(ret_ASSERT_FLOAT_LT_failures)/sizeof(short)];
  unsigned char words8[sizeof(ret_ASSERT_FLOAT_LT_failures)];
}byteRet_ASSERT_FLOAT_LT_failures;


void
running_ASSERT_FLOAT_LT_failures(hls::stream<unsigned int> &dst, hls::stream<tASSERT_FLOAT_FAILURE> &assertFLOAT_LT_failures)
{
  short index = 0;
  tASSERT_FLOAT_FAILURE auxFailure;

  auxFailure = assertFLOAT_LT_failures.read();


  unsigned int ptr_callCount;
  ptr_callCount = auxFailure._callCount;
  byteRet_ASSERT_FLOAT_LT_failures.words32[index++] = ptr_callCount;

  unsigned int ptr_time;
  ptr_time = auxFailure._callTime;
  byteRet_ASSERT_FLOAT_LT_failures.words32[index++] = ptr_time;

  unsigned int ptr_x[1];
  toSequence(auxFailure._x, ptr_x);
  byteRet_ASSERT_FLOAT_EQ_failures.words32[index++] = ptr_x[0];

  unsigned int ptr_y[1];
  toSequence(auxFailure._y, ptr_y);
  byteRet_ASSERT_FLOAT_EQ_failures.words32[index++] = ptr_y[0];

  for(int itReturn=0; itReturn != sizeof(byteRet_ASSERT_FLOAT_LT_failures.words32)/ASSERTS_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_ASSERT_FLOAT_LT_failures.words32[itReturn]);

  assertFLOAT_LT_failures_rd_index += 1;
}
///////////////////////////////////////////////////////////////////////
