#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-



import unittest
from unittest_time import TimeTestCase

from vector_norm import l2norm
from asserts import *


class TestL2Norm(TimeTestCase):

    def test_l2norm(self):
        ref = [0.0, 0.027163850143551826, 0.05432770028710365, 0.08149155229330063, 0.1086554005742073, 0.13581925630569458, 0.16298310458660126, 0.19014695286750793, 0.2173108011484146, 0.2444746494293213, 0.27163851261138916, 0.29880234599113464, 0.3259662091732025, 0.353130042552948, 0.38029390573501587, 0.40745773911476135];
        din = []
        for i in range(0,16):
            din.append(float(i))
            
        self.UNITTEST_TIME_RESET()
        self.CONFIGURE_UNITTEST_TIME_HW_ADDR(0x41000000)
        self.CONFIGURE_UNITTEST_TIME_INPUT_32BIT_WORDS(18)
        self.CONFIGURE_UNITTEST_TIME_OUTPUT_32BIT_WORDS(1)
        self.CONFIGURE_UNITTEST_TIME_ENABLE_CYCLES(0x0)

        self.UNITTEST_TIME_CONFIGURE()

        dout=[]
        l2norm(din, dout);

        
        self.assertTimeGT(220)
        self.assertTimeLT(450)
        
        for i in range(0,16):
            self.assertEqual(ref[i], dout[i])
            
        print("CallCount (FLOAT_EQ) {0}".format(ASSERT_FLOAT_EQ_CALLCOUNT()))
        print("FailureCount (FLOAT_EQ) {0}".format(ASSERT_FLOAT_EQ_FAILURECOUNT()))
        PRINT_FAILURES_ASSERT_FLOAT_EQ()

        print ("CallCount (FLOAT_LT) {0}".format(ASSERT_FLOAT_LT_CALLCOUNT()))
        print ("FailureCount (FLOAT_LT) {0}".format(ASSERT_FLOAT_LT_FAILURECOUNT()))
        PRINT_FAILURES_ASSERT_FLOAT_LT()

        

            
        
                    
# if __name__ == '__main__':
#     unittest.main()
    
