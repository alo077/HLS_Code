#include <iostream>
#include "nand_gate.h"

int main() {
    ap_uint<1> a, b;
    data_t w1 , w2, bias;
    int status = 0;
    std :: cout << "Testing NAND Perceptron ... \n";
    a = 0; b = 0;
    nand_gate(a, b, w1);
    a = 0; b = 1;
    nand_gate(a, b, w2);
    a = 1; b = 0;
    nand_gate(a, b, bias);
    std :: cout << "w1 = " << w1 << ", w2 = " << w2 << ", bias = " << bias << "\n";
    
    for (ap_uint<3> k; k < 4; k++){
        a = (k >> 1) & 1; b = k & 1;
        data_t z = a * w1 + b * w2 + bias;
        ap_uint<1> y_ = 0;
        if(z >= 0){
            y_ = 1;
        }
        else y_ = 0;

        ap_uint<1> y = ~(a&b);

        std :: cout << "a=" << a << " b=" << b << "y_ =" << y_ << "\n";
        if (y_ != y) status = 1;
        if (status == 0) std :: cout << "PASSED!\n";
    }

    return status;
}