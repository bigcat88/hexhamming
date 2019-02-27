#ifndef PYTHON_HEXHAMMING_WRAPPER_H
#define PYTHON_HEXHAMMING_WRAPPER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#include <Python.h>
#include "./hexhamming.hh"

///////////////////////////////////////////////////////////////
// Python API Wrappers
///////////////////////////////////////////////////////////////
static PyObject * hamming_distance_wrapper(PyObject *self, PyObject *args);

///////////////////////////////////////////////////////////////
// Docstrings
///////////////////////////////////////////////////////////////

static char hamming_docstring[] =
    "Calculate the hamming distance of two strings\n\n"
    "This is equivalent to\n\n"
    "    bin(int(a, 16) ^ int(b, 16)).count('1')\n\n"
    "with the only difference being it  was written in C++ and optimized\n"
    "using a lookup table of pre-calculated hexadecimal hamming distances.\n"
    ":param a: hexadecimal string\n"
    ":type a: str\n"
    ":param b: hexadecimal string\n"
    ":type b: str\n"
    ":returns: the hamming distance between the bits of two hexadecimal strings\n"
    ":rtype: int\n"
    ":raises ValueError: if either string doesn't exist, "
    "if the strings are different lengths, or if the strings aren't valid hex";

static char CompareDocstring[] =
    "Module for calculating hamming distance of two hexadecimal strings";

///////////////////////////////////////////////////////////////
// Python C-extension Initialization
///////////////////////////////////////////////////////////////
static PyMethodDef CompareMethods[] = {
    {"hamming_distance", hamming_distance_wrapper, METH_VARARGS, hamming_docstring},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC inithexhamming(void) {
    PyObject *m = Py_InitModule3("hexhamming", CompareMethods, CompareDocstring);
    if (m == NULL) {
        return;
    }
}


#endif
