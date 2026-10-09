#include <iostream>
#include "or_gate.h"

int main() {
    ap_uint<1> a, b, c;
    int status = 0;
    std :: cout << "Testing OR Perceptron ... \n";
    for (int i = 0; i < 4; i++) {
        a =(i >> 1) & 1; b = i & 1;
        or_gate(a, b, c);
        ap_uint<1> expected =a | b;
        std :: cout << "a=" << a << " b=" << b << "c=" << c << "\n";
        if (c != expected) status = 1;
        if (status == 0) std :: cout << "PASSED!\n";
    }
    return status;
}