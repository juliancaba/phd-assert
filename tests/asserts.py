#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-

import sys
from hwt_proxy import FPGA_hwtClient
from arm_casting_ieee754 import *


_hw_addr = 0x42000000

_float_eq_failurecount = 0
_float_eq_failurecount_vld = 0

_float_lt_failurecount = 0
_float_lt_failurecount_vld = 0


def ASSERT_FLOAT_EQ_CALLCOUNT():      
    din = []
    din.extend(int_to_byte(0x000B1700))
    din.extend(int_to_byte(0x00000000))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]
    head2 = idout[1]

    _callcount = idout[2]
    del testCli
    del idout
    return _callcount


  
def ASSERT_FLOAT_EQ_FAILURECOUNT():      
    din = []
    din.extend(int_to_byte(0x000B1800))
    din.extend(int_to_byte(0x00000000))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]
    head2 = idout[1]

    _float_eq_failurecount = idout[2]
    _float_eq_failurecount_vld = 1
    del testCli
    del idout
    return _float_eq_failurecount



  
def PRINT_FAILURES_ASSERT_FLOAT_EQ():
    if _float_eq_failurecount_vld:
        failures = _float_eq_failurecount;
    else:
        failures = ASSERT_FLOAT_EQ_FAILURECOUNT();

    if failures == 0:
        print("{0}: No failures\n").format(__name__)
    else:
        for it in (0,failures):
            din = []
            din.extend(int_to_byte(0x000B1A00))
            din.extend(int_to_byte(0x00000000))

            testCli = FPGA_hwtClient()
            testCli.arguments(_hw_addr, din)
            testCli.main([None])
            dout = testCli.result()
            idout = charSeq_to_intSeq(dout)

            head1 = idout[0]
            head2 = idout[1]
            callCount = idout[2]
            print ("\tcallCount {0}\n").format(callCount)
            time = idout[3]
            print ("\tTime {0}\n").format(time)
            expected = ieee754_to_float(idout[4])
            print ("\tExpected {0}\n").format(expected)
            actual = ieee754_to_float(idout[5])
            print ("\tActual {0}\n").format(actual)

            del testCli
            del idout


            
def ASSERT_FLOAT_LT_CALLCOUNT():      
    din = []
    din.extend(int_to_byte(0x000B1700))
    din.extend(int_to_byte(0x00000000))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]
    head2 = idout[1]

    _callcount = idout[2]
    del testCli
    del idout
    return _callcount


  
def ASSERT_FLOAT_LT_FAILURECOUNT():      
    din = []
    din.extend(int_to_byte(0x000B1800))
    din.extend(int_to_byte(0x00000000))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]
    head2 = idout[1]

    _float_lt_failurecount = idout[2]
    _float_lt_failurecount_vld = 1
    del testCli
    del idout
    return _float_lt_failurecount



  
def PRINT_FAILURES_ASSERT_FLOAT_LT():
    if _float_lt_failurecount_vld:
        failures = _float_lt_failurecount;
    else:
        failures = ASSERT_FLOAT_LT_FAILURECOUNT();

    if failures == 0:
        print("{0}: No failures\n").format(__name__)
    else:
        for it in (0,failures):
            din = []
            din.extend(int_to_byte(0x000B1A00))
            din.extend(int_to_byte(0x00000000))

            testCli = FPGA_hwtClient()
            testCli.arguments(_hw_addr, din)
            testCli.main([None])
            dout = testCli.result()
            idout = charSeq_to_intSeq(dout)

            head1 = idout[0]
            head2 = idout[1]
            callCount = idout[2]
            print ("\tcallCount {0}\n").format(callCount)
            time = idout[3]
            print ("\tTime {0}\n").format(time)
            expected = ieee754_to_float(idout[4])
            print ("\tExpected {0}\n").format(expected)
            actual = ieee754_to_float(idout[5])
            print ("\tActual {0}\n").format(actual)

            del testCli
            del idout


