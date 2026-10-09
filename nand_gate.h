#ifndef NAND_GATE
#define NAND_GATE

#include <ap_int.h>
#include <ap_fixed.h>

typedef ap_fixed<8, 4> data_t;

void nand_gate(ap_uint<1> a, ap_uint<1> b, data_t &output);

#endif