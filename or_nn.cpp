#include "or_gate.h"

void or_gate(ap_uint<1> a, ap_uint<1> b, ap_uint<1> &c) {
    // Simple hardware pins wrapper without controls
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE ap_none port=a
    #pragma HLS INTERFACE ap_none port=b
    #pragma HLS INTERFACE ap_none port=c

    // Perceptron Weights & Bias (Trained for OR logic)
    const data_t w1 = 1.0;
    const data_t w2 = 1.0;
    const data_t bias = -0.5;

    // Multiply-Accumulate (MAC) step
    data_t z = (a * w1) + (b * w2) + bias;

    // Activation Function (Step / Threshold function)
    if (z >= 0) {
        c = 1;
    }
    else c = 0;

}