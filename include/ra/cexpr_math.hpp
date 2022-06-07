#include <limits>
#include <numbers>
#include <stdexcept>

namespace ra::cexpr_math {
    // The math constant pi.
    // The type T is a floating-point type.
    template <class T>
    constexpr T pi = std::numbers::pi_v<T>;

    // Returns the absolute value of x.
    // The type T is a floating-point type.
    template <class T>
    constexpr T abs(T x) {
        return x < 0 ? -x : x;
    }

    // Returns the square of x.
    // The type T is a floating-point type.
    template <class T>
    constexpr T sqr(T x) {
        return x * x;
    }

    // Returns the cube of x.
    // The type T is a floating-point type.
    template <class T>
    constexpr T cube(T x) {
        return x * x * x;
    }

    // Returns the remainder after division when x is divided by y.
    // In particular, x - n y is returned where n is the result obtained by
    // dividing x by y and then rounding (to an integer value) toward zero.
    // If y is zero, an exception of type std::overflow_error is thrown.
    // The type T is a floating-point type.
    template <class T>
    constexpr T mod(T x, T y) {
        if (y == 0) {
            throw std::overflow_error("modulus by zero");
        }

        int n = x / y;

        return x - y * n;
    }

    // Returns the sine of x.
    // Note that a particular algorithm must be used to implement this
    // function.
    // The type T is a floating-point type.
    template <class T>
    constexpr T sin(T x) {
        if (x < 0) {
            return -sin<T>(-x);
        }

        if (x <= 10e-6) {
            return x;
        }

        return 3.0 * sin<T>(mod<T>(x, 2.0 * pi<T>) / 3.0) - 4.0 * cube<T>(sin<T>(mod<T>(x, 2.0 * pi<T>) / 3.0));
    }

    // Returns the cosine of x.
    // Note that a particular algorithm must be used to implement this
    // function.
    // The type T is a floating-point type.
    template <class T>
    constexpr T cos(T x){
        return sin<T>(x + pi<T> / 2.0);
    }

    // Returns the tangent of x.
    // Note that a particular algorithm must be used to implement this
    // function.
    // If the tangent of x is infinite, an exception of type
    // std::overflow_error is thrown.
    // The type T is a floating-point type.
    template <class T>
    constexpr T tan(T x){
        T value = cos<T>(x);
        if(value == 0){
            throw std::overflow_error("tangent of infinite");
        }
        return sin<T>(x) / value;
    }

    // Returns the square root of x.
    // If x is negative, an exception of type std::domain_error is thrown.
    // Note that a particular algorithm must be used to implement this
    // function.
    // The type T is a floating-point type.
    template <class T>
    constexpr T sqrt(T x){
        if(x < 0){
            throw std::domain_error("square root of negative");
        }

        if(x == 0){
            return 0;
        }

        constexpr T epsilon = std::numeric_limits<T>::epsilon();
        constexpr T m = std::numeric_limits<T>::max_exponent;
        T x_0 = x + 6.0;
        T x_n = x;
        T f_x = 0.0;
        T f_der = 0.0;
        const T c = x;
        T n = 0.0;

        while (abs<T>(x_n - x_0) > epsilon && n < m) {
            x_0 = x_n;
            f_x = sqr<T>(x_0) - c;
            f_der = 2.0 * x_0;
            x_n = x_0 - f_x / f_der;
            n++;
        }

        return x_n;
    }

}  // namespace ra::cexpr_math