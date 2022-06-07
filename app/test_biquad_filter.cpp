#include <ra/biquad_filter.hpp>

int main(){
    constexpr ra::biquad::biquad_filter_coefs<double> test1(ra::biquad::lowpass<double>(0.5, 1.0));

    constexpr ra::biquad::biquad_filter_coefs<double> test2(ra::biquad::highpass<double>(0.5, 1.0));

    constexpr ra::biquad::biquad_filter_coefs<double> test3(ra::biquad::bandpass<double>(0.5, 1.0));

    constexpr ra::biquad::biquad_filter_coefs<double> test4(ra::biquad::lowshelf_boost<double>(0.5, 1.0));

    constexpr ra::biquad::biquad_filter_coefs<double> test5(ra::biquad::lowshelf_cut<double>(0.5, 1.0));

    return 0;
}