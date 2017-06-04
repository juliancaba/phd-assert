#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-



import unittest
from unittest_time import TimeTestCase

from vector_norm import l2norm
from asserts import *


class TestL2Norm(TimeTestCase):

    def test_l2norm(self):
        ref = [0.0, 0.027164, 0.054328,
               0.081492, 0.108655, 0.135819,
               0.162983, 0.190147, 0.217311,
               0.244475, 0.271639, 0.298802,
               0.325966, 0.353130, 0.380294,
               0.407458];
        din = []
        for i in range(0,16):
            din.append(float(i))
            
        self.UNITTEST_TIME_RESET()
        self.CONFIGURE_UNITTEST_TIME_HW_ADDR(0x41000000)
        self.CONFIGURE_UNITTEST_TIME_INPUT_32BIT_WORDS(18)
        self.CONFIGURE_UNITTEST_TIME_OUTPUT_32BIT_WORDS(1)
        self.CONFIGURE_UNITTEST_TIME_ENABLE_CYCLES(2000000)

        self.UNITTEST_TIME_CONFIGURE()

        dout=[]
        l2norm(din, dout);
        
        self.assertTimeGT(220)
        self.assertTimeGT(450)

        for i in range(0,16):
            self.assertEqual(ref[i], dout[i])

        
        print ("CallCount (FLOAT_EQ) {0}\n").format(ASSERT_FLOAT_EQ_CALLCOUNT())
        print ("FailureCount (FLOAT_EQ) {0}\n").format(ASSERT_FLOAT_EQ_FAILURECOUNT())
        PRINT_FAILURES_ASSERT_FLOAT_EQ()

        print ("CallCount (FLOAT_LT) {0}\n").format(ASSERT_FLOAT_LT_CALLCOUNT())
        print ("FailureCount (FLOAT_LT) {0}\n").format(ASSERT_FLOAT_LT_FAILURECOUNT())
        PRINT_FAILURES_ASSERT_FLOAT_LT()
            
# if __name__ == '__main__':
#     unittest.main()
    
