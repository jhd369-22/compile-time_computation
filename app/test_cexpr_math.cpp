#include<ra/cexpr_math.hpp>

 

int main(){
    // abs
    static_assert(ra::cexpr_math::abs<double>(-1) == 1);
    static_assert(ra::cexpr_math::abs<double>(1) == 1);
    static_assert(ra::cexpr_math::abs<double>(0) == 0);

    // square
    static_assert(ra::cexpr_math::sqr<double>(-2) == 4);
    static_assert(ra::cexpr_math::sqr<double>(-1) == 1);
    static_assert(ra::cexpr_math::sqr<double>(0) == 0);
    static_assert(ra::cexpr_math::sqr<double>(1) == 1);
    static_assert(ra::cexpr_math::sqr<double>(2) == 4);

    // cube
    static_assert(ra::cexpr_math::cube<double>(-2) == -8);
    static_assert(ra::cexpr_math::cube<double>(-1) == -1);
    static_assert(ra::cexpr_math::cube<double>(0) == 0);
    static_assert(ra::cexpr_math::cube<double>(1) == 1);
    static_assert(ra::cexpr_math::cube<double>(2) == 8);

    // modulo
    static_assert(ra::cexpr_math::mod<double>(3, 6) == 3);
    static_assert(ra::cexpr_math::mod<double>(6, 3) == 0);
    static_assert(ra::cexpr_math::mod<double>(3, -6) == 3);
    static_assert(ra::cexpr_math::mod<double>(-6, 3) == 0);
    static_assert(ra::cexpr_math::mod<double>(6, 6) == 0);

    // sin
    static_assert(ra::cexpr_math::sin<double>(-1) == -0.8414709848078965);
    static_assert(ra::cexpr_math::sin<double>(0) == 0);
    static_assert(ra::cexpr_math::sin<double>(1) == 0.8414709848078965);
    static_assert(ra::cexpr_math::sin<double>(9) == 0.4121184852417566);

    // cos
    static_assert(ra::cexpr_math::cos<double>(-1) == -0.5403023058681398);
    static_assert(ra::cexpr_math::cos<double>(0) == 1);
    static_assert(ra::cexpr_math::cos<double>(1) == 0.5403023058681398);
    static_assert(ra::cexpr_math::cos<double>(9) == 0.8685889638065807);

    // tan
    static_assert(ra::cexpr_math::tan<double>(-1) == -1.5574077246549022);
    static_assert(ra::cexpr_math::tan<double>(0) == 0);
    static_assert(ra::cexpr_math::tan<double>(1) == 1.5574077246549022);
    static_assert(ra::cexpr_math::tan<double>(9) == -0.452315659441810);

    // sqrt
    static_assert(ra::cexpr_math::sqrt<double>(0) == 0);
    static_assert(ra::cexpr_math::sqrt<double>(4) == 2);
    static_assert(ra::cexpr_math::sqrt<double>(9) == 3);
    
    return 0;
}