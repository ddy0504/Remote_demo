#!/bin/python

#from ctypes import cdll
import ctypes
from timeit import timeit

#libhello = cdll.LoadLibrary("./libfunc.so")
libhello = ctypes.CDLL("./libfunc.so")
print libhello.func1()

def factorial(n):
    if n<2:
        return 1
    return factorial(n-1)*n

def factorial_c(n):
    return libhello.factorial(n)

f_setup = 'from __main__ import factorial'
f_c_setup = 'from __main__ import factorial_c'
print timeit('factorial(20)',setup=f_setup,number=100000)
print timeit('factorial_c(20)',setup=f_c_setup,number=100000)
