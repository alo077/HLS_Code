#ifndef OR_GATE_H
#define OR_GATE_H

#include <ap_int.h>
#include <ap_fixed.h> // Custom fixed-point types

// 8-bit fixed-point type, with 4 integer bits (Format: 04.4)
typedef ap_fixed<8, 4> data_t;

// Function prototype for the OR Gate Perceptron
void or_gate(ap_uint<1> a, ap_uint<1> b, ap_uint<1> &c);

#endif

// Custom bit-width integer types