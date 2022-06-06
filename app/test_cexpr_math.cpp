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
    static_assert(ra::cexpr_math::sin<double>(-1) == -0.84147098481076599);
    static_assert(ra::cexpr_math::sin<double>(0) == 0);
    static_assert(ra::cexpr_math::sin<double>(1) == 0.84147098481076599);
    static_assert(ra::cexpr_math::sin<double>(9) == 0.41211848523097472);

    // cos
    static_assert(ra::cexpr_math::cos<double>(-1) == 0.54030230587561978);
    static_assert(ra::cexpr_math::cos<double>(0) == 1);
    static_assert(ra::cexpr_math::cos<double>(1) == 0.54030230585970229);
    static_assert(ra::cexpr_math::cos<double>(9) == -0.91113026190384661);

    // tan
    static_assert(ra::cexpr_math::tan<double>(-1) == -1.557407724638652);
    static_assert(ra::cexpr_math::tan<double>(0) == 0);
    static_assert(ra::cexpr_math::tan<double>(1) == 1.5574077246845337);
    static_assert(ra::cexpr_math::tan<double>(9) == -0.45231565942045993);

    // sqrt
    static_assert(ra::cexpr_math::sqrt<double>(0) == 0);
    static_assert(ra::cexpr_math::sqrt<double>(4) == 2);
    static_assert(ra::cexpr_math::sqrt<double>(9) == 3);
    
    return 0;
}