#include "nand_gate.h"

void nand_gate(ap_uint<1> a, ap_uint<1> b, data_t &output){
    
    #pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE ap_none port=a
    #pragma HLS INTERFACE ap_none port=b
    #pragma HLS INTERFACE ap_none port=output
    
    data_t w1 = 0.0;
    data_t w2 = 0.0;
    data_t bias = 0.0;
    
    
    data_t n = 0.125;
    
    ap_uint<1> flag = 1;
    ap_uint<8> epochs = 0;
    
    while(flag == 1 && epochs < 20){
        flag = 0;
        for (ap_uint<3> k = 0; k < 4; k++){
            ap_uint<1> i = (k >> 1) & 1; ap_uint<1> j = k & 1;
            data_t pred = (i * w1) + (j * w2) + bias;
            ap_uint<1> y = ~(i&j);
                        
            ap_uint<2> out = 0;
            
            if(pred >= 0){
                out = 1;
            }
            else{
                out = 0;
            }
            
            if(out != y){
                flag = 1;
                w1 = w1 + n*(y-out)*i;
                w2 = w2 + n * (y-out)*j;
                bias = bias + n * (y-out);
            }
        }
        epochs += 1;
    }

    if ((~a)&(~b) == 1) output = w1;
    else if ((~a)&(b) == 1) output = w2;
    else if ((a)&(~b) == 1) output = bias;
}