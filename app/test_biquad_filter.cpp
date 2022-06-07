#include <ra/biquad_filter.hpp>

namespace biquad = ra::biquad;

template<typename T>
void test_case(){
    constexpr biquad::biquad_filter_coefs<T> test1(T(1.0), T(1.0), T(1.0), T(1.0), T(1.0), T(1.0));
    constexpr biquad::biquad_filter_coefs<T> test2(test1);
    constexpr auto test3 = biquad::lowpass<T>(T(0.5), T(1));
    constexpr auto test4 = biquad::highpass<T>(T(0.5), T(1));
    constexpr auto test5 = biquad::bandpass<T>(T(0.5), T(1));
    constexpr auto test6 = biquad::lowshelf_boost<T>(T(0.5), T(1));
    constexpr auto test7 = biquad::lowshelf_cut<T>(T(0.5), T(1));
}

int main(){
    test_case<float>();
    test_case<double>();
    test_case<long double>();

    return 0;
}