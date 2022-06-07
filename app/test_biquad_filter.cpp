#include <ra/biquad_filter.hpp>
#include <iostream>

int main(){
    ra::biquad::biquad_filter_coefs<float> test1(ra::biquad::lowpass(0.5, 1.0));

    std::cout << test1.a0 << "\n";
    std::cout << test1.a1 << "\n";
    std::cout << test1.a2 << "\n";
    std::cout << test1.b0 << "\n";
    std::cout << test1.b1 << "\n";
    std::cout << test1.b2 << "\n";

    return 0;
}