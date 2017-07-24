#include "topTesting.h"
#include "wrapperOBJ.h"
#include "wrapper_ASSERTS.h"



void
forward_OBJ(hls::stream<unsigned int> &src, short size)
{
  short it=0;
  while(it != size){
    src.read();
    it += 1;
  }
}


void
buildResponse_OBJ(hls::stream<unsigned int> &dst,
		  unsigned short objID, unsigned short size,
		  unsigned char flags)
{  
  int words32;

  words32 = (header_OBJ.cb<<16) | (header_OBJ.methodID<<8) | flags;
  dst.write(words32);
  if(flags & FLAG_HAS_PAYLOAD){
    words32 = (objID<<16) | size;
    dst.write(words32);
    while (!bufferRESP_OBJ.empty())
      dst.write(bufferRESP_OBJ.read());
  }
}


void
getRequestHead_OBJ(hls::stream<unsigned int> &src)
{
  int words32[2];

  for(int it=0; it != 2; it++)
    words32[it] = src.read();
  //byteHeader[it].words32 = bufferIN.read();

  header_OBJ.nodeID = (words32[0] >> 24) & 0xFF;
  header_OBJ.objectID = (words32[0] >> 16) & 0xFF;
  header_OBJ.methodID = (words32[0] >> 8) & 0xFF;
  header_OBJ.flags = words32[0] & 0xFF;
  header_OBJ.cb = (words32[1] >> 16) & 0xFFFF;
  header_OBJ.size = words32[1] & 0xFFFF;
}



void
topTesting(hls::stream<unsigned int> din, hls::stream<unsigned int> dout,
	   hls::stream<unsigned int> timeClock)
{
#pragma HLS STREAM variable=bufferRESP_OBJ depth=32
  
  getRequestHead_OBJ(din);

  if (ID_OBJ == header_OBJ.objectID || BROADCAST == header_OBJ.objectID)
    if (ID_OBJ_l2norm == header_OBJ.methodID){
      testing_OBJ_l2norm(din, bufferRESP_OBJ);
      buildResponse_OBJ(dout, ID_OBJ, sizeof(ret_OBJ_l2norm)/OBJ_BUS_WIDTH_BYTES,
     			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else{
      forward_OBJ(din, header_OBJ.size);
      buildResponse_OBJ(dout, ID_OBJ, 0, 
			FLAG_RESPONSE|FLAG_FAIL);
    } 
  else if (ID_ASSERTS == header_OBJ.objectID)
    if (ID_ASSERT_FLOAT_EQ_callCount == header_OBJ.methodID){
      running_ASSERT_FLOAT_EQ_callCount(bufferRESP_OBJ, assertFLOAT_EQ_callCount);
      buildResponse_OBJ(dout, ID_ASSERTS, sizeof(ret_ASSERT_FLOAT_EQ_callCount)/ASSERTS_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_ASSERT_FLOAT_EQ_failureCount == header_OBJ.methodID){
      running_ASSERT_FLOAT_EQ_failureCount(bufferRESP_OBJ, assertFLOAT_EQ_failureCount);
      buildResponse_OBJ(dout, ID_ASSERTS, sizeof(ret_ASSERT_FLOAT_EQ_failureCount)/ASSERTS_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_ASSERT_FLOAT_EQ_failures == header_OBJ.methodID){
      running_ASSERT_FLOAT_EQ_failures(bufferRESP_OBJ, assertFLOAT_EQ_failures);
      buildResponse_OBJ(dout, ID_ASSERTS, sizeof(ret_ASSERT_FLOAT_EQ_failures)/ASSERTS_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_ASSERT_FLOAT_LT_callCount == header_OBJ.methodID){
      running_ASSERT_FLOAT_LT_callCount(bufferRESP_OBJ, assertFLOAT_LT_callCount);
      buildResponse_OBJ(dout, ID_ASSERTS, sizeof(ret_ASSERT_FLOAT_LT_callCount)/ASSERTS_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_ASSERT_FLOAT_LT_failureCount == header_OBJ.methodID){
      running_ASSERT_FLOAT_LT_failureCount(bufferRESP_OBJ, assertFLOAT_LT_failureCount);
      buildResponse_OBJ(dout, ID_ASSERTS, sizeof(ret_ASSERT_FLOAT_LT_failureCount)/ASSERTS_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_ASSERT_FLOAT_LT_failures == header_OBJ.methodID){
      running_ASSERT_FLOAT_LT_failures(bufferRESP_OBJ, assertFLOAT_LT_failures);
      buildResponse_OBJ(dout, ID_ASSERTS, sizeof(ret_ASSERT_FLOAT_LT_failures)/ASSERTS_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else{
      forward_OBJ(din, header_OBJ.size); 
      buildResponse_OBJ(dout, FLAG_FAIL, ID_ASSERTS,
			FLAG_RESPONSE|FLAG_FAIL);
    }
  else{
    forward_OBJ(din, header_OBJ.size);
    buildResponse_OBJ(dout, NULL_OBJ, 0,
		      FLAG_RESPONSE|FLAG_FAIL);
  }
}

