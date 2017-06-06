#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-

import sys
from hwt_proxy import sendMessage
from arm_casting_ieee754 import *


_hw_addr = 0x42000000

_float_eq_failurecount = 0
_float_eq_failurecount_vld = 0

_float_lt_failurecount = 0
_float_lt_failurecount_vld = 0


def ASSERT_FLOAT_EQ_CALLCOUNT():          
    head,payload = sendMessage(0x42000000, 0x000B1700, 0x00000000, None)
    _callcount = int(payload[0],16)
    return _callcount


  
def ASSERT_FLOAT_EQ_FAILURECOUNT():          
    head,payload = sendMessage(_hw_addr, 0x000B1800, 0x00000000, None)
    _float_eq_failurecount = int(payload[0],16)
    _float_eq_failurecount_vld = 1
    return _float_eq_failurecount

  
def PRINT_FAILURES_ASSERT_FLOAT_EQ():
    if _float_eq_failurecount_vld:
        failures = _float_eq_failurecount;
    else:
        failures = ASSERT_FLOAT_EQ_FAILURECOUNT();

    if failures == 0:
        print("{0}: No failures".format(sys._getframe().f_code.co_name))
    else:
        print("Failures - {0}".format(sys._getframe().f_code.co_name))
        for it in range(0,failures):
            head,payload = sendMessage(_hw_addr, 0x000B1A00, 0x00000000, None)
            callCount = int(payload[0],16)
            print ("\tcallCount {0}".format(callCount))
            time = int(payload[1],16)
            print ("\tTime {0}".format(time))
            expected = ieee754_to_float(payload[2])
            print ("\tExpected {0}".format(expected))
            actual = ieee754_to_float(payload[3])
            print ("\tActual {0}".format(actual))

            
def ASSERT_FLOAT_LT_CALLCOUNT():
    head,payload = sendMessage(_hw_addr, 0x000B2B00, 0x00000000, None)
    _callcount = int(payload[0],16)
    return _callcount

  
def ASSERT_FLOAT_LT_FAILURECOUNT():
    head,payload = sendMessage(_hw_addr, 0x000B2C00, 0x00000000, None)
    _float_lt_failurecount = int(payload[0],16)
    _float_lt_failurecount_vld = 1
    return _float_lt_failurecount

  
def PRINT_FAILURES_ASSERT_FLOAT_LT():
    if _float_lt_failurecount_vld:
        failures = _float_lt_failurecount;
    else:
        failures = ASSERT_FLOAT_LT_FAILURECOUNT();

    if failures == 0:
        print("{0}: No failures".format(sys._getframe().f_code.co_name))
    else:
        print("Failures - {0}".format(sys._getframe().f_code.co_name))
        for it in range(0,failures):
            head,payload = sendMessage(_hw_addr, 0x000B2E00, 0x00000000, None)
            callCount = int(payload[0],16)
            print ("\tcallCount {0}".format(callCount))
            time = int(payload[1],16)
            print ("\tTime {0}".format(time))
            expected = ieee754_to_float(payload[2])
            print ("\tExpected {0}".format(expected))
            actual = ieee754_to_float(payload[3])
            print ("\tActual {0}".format(actual))


