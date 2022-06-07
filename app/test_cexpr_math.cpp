#include<ra/cexpr_math.hpp>

namespace math = ra::cexpr_math;

template<typename T>
void test_case(){

    // pi
    constexpr auto m1 = math::pi<T>;

    // abs
    static_assert(math::abs<T>(T(-1)) == T(1));
    static_assert(math::abs<T>(T(1)) == T(1));
    static_assert(math::abs<T>(T(0)) == T(0));

    // square
    static_assert(math::sqr<T>(T(-2)) == T(4));
    static_assert(math::sqr<T>(T(-1)) == T(1));
    static_assert(math::sqr<T>(T(0)) == T(0));
    static_assert(math::sqr<T>(T(1)) == T(1));
    static_assert(math::sqr<T>(T(2)) == T(4));

    // cube
    static_assert(math::cube<T>(T(-2)) == T(-8));
    static_assert(math::cube<T>(T(-1)) == T(-1));
    static_assert(math::cube<T>(T(0)) == T(0));
    static_assert(math::cube<T>(T(1)) == T(1));
    static_assert(math::cube<T>(T(2)) == T(8));

    // modulo
    static_assert(math::mod<T>(T(3), T(6)) == T(3));
    static_assert(math::mod<T>(T(6), T(3)) == T(0));
    static_assert(math::mod<T>(T(3), T(-6)) == T(3));
    static_assert(math::mod<T>(T(-6), T(3)) == T(0));
    static_assert(math::mod<T>(T(6), T(6)) == T(0));

    // sin
    constexpr auto m2 = math::sin<T>(T(-1));
    constexpr auto m3 = math::sin<T>(T(0));
    constexpr auto m4 = math::sin<T>(T(1));
    constexpr auto m5 = math::sin<T>(T(9));

    // cos
    constexpr auto m6 = math::cos<T>(T(-1));
    constexpr auto m7 = math::cos<T>(T(0));
    constexpr auto m8 = math::cos<T>(T(1));
    constexpr auto m9 = math::cos<T>(T(9));

    // tan
    constexpr auto m10 = math::tan<T>(T(-1));
    constexpr auto m11 = math::tan<T>(T(0));
    constexpr auto m12 = math::tan<T>(T(1));
    constexpr auto m13 = math::tan<T>(T(9));

    // sqrt
    static_assert(math::sqrt<T>(T(0)) == T(0));
    static_assert(math::sqrt<T>(T(4)) == T(2));
    static_assert(math::sqrt<T>(T(9)) == T(3));
}

int main(){
    test_case<float>();
    test_case<double>();
    test_case<long double>();
    
    return 0;
}