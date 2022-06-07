#include <ra/cexpr_math.hpp>
#include <stdexcept>

namespace ra::biquad {

    // Biquad filter coefficients class.
    template <class Real>
    struct biquad_filter_coefs {
            // The real number type used to represent the filter coefficients.
            using real = Real;

            // Creates a set of filter coefficients where the coefficients
            // a0, a1, a2, b0, b1, and b2 are initialized to a0_, a1_, a2_,
            // b0_, b1_, and b2_, respectively.
            constexpr biquad_filter_coefs(real a0_, real a1_, real a2_, real b0_,
                                          real b1_, real b2_) : a0(a0_), a1(a1_), a2(a2_), b0(b0_), b1(b1_), b2(b2_) {}

            // Creates a set of filter coefficients by copying from another set.
            // Since Real and OtherReal need not be the same, this constructor
            // can be used to convert between filter coefficients of different
            // types.
            template <class OtherReal>
            constexpr biquad_filter_coefs(const biquad_filter_coefs<OtherReal>& coefs) : a0(coefs.a0), a1(coefs.a1), a2(coefs.a2), b0(coefs.b0), b1(coefs.b1), b2(coefs.b2) {}

            // The filter coefficients a0, a1, a2, b0, b1, and b2.
            real a0;
            real a1;
            real a2;
            real b0;
            real b1;
            real b2;
    };
    

    // Returns the coefficients for a biquad lowpass filter with normalized
    // cutoff frequency f and Q factor q, where f in [0,1] and q > 0.
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real>
    constexpr biquad_filter_coefs<Real> lowpass(Real f, Real q) {
        if (f < 0 || f > 1 || q <= 0) {
            throw std::invalid_argument("invalid lowpass filter parameters");
        }

        const Real omega = ra::cexpr_math::tan<Real>(ra::cexpr_math::pi<Real> / 2.0 * f);
        const Real a0 = ra::cexpr_math::sqr<Real>(omega);
        const Real a1 = 2.0 * a0;
        const Real a2 = a0;
        const Real b0 = a0 + omega / q + 1.0;
        const Real b1 = 2.0 * (a0 - 1.0);
        const Real b2 = a0 - omega / q + 1.0;

        return biquad_filter_coefs<Real>(a0, a1, a2, b0, b1, b2);
    }

    // Returns the coefficients for a biquad highpass filter with
    // normalized cutoff frequency f and Q factor q, where f in [0,1]
    // and q > 0.
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real>
    constexpr biquad_filter_coefs<Real> highpass(Real f, Real q) {
        if (f < 0 || f > 1 || q <= 0) {
            throw std::invalid_argument("invalid highpass filter parameters");
        }

        const Real omega = ra::cexpr_math::tan<Real>(ra::cexpr_math::pi<Real> / 2.0 * f);
        const Real a0 = 1.0;
        const Real a1 = -2.0;
        const Real a2 = 1.0;
        const Real b0 = ra::cexpr_math::sqr<Real>(omega) + omega / q + 1.0;
        const Real b1 = 2.0 * (ra::cexpr_math::sqr<Real>(omega) - 1.0);
        const Real b2 = ra::cexpr_math::sqr<Real>(omega) - omega / q + 1.0;

        return biquad_filter_coefs<Real>(a0, a1, a2, b0, b1, b2);
    }

    // Returns the coefficients for a biquad bandpass filter with
    // normalized cutoff frequency f and Q factor q, where f in [0,1]
    // and q > 0.
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real>
    constexpr biquad_filter_coefs<Real> bandpass(Real f, Real q) {
        if (f < 0 || f > 1 || q <= 0) {
            throw std::invalid_argument("invalid bandpass filter parameters");
        }

        const Real omega = ra::cexpr_math::tan<Real>(ra::cexpr_math::pi<Real> / 2.0 * f);
        const Real a0 = omega / q;
        const Real a1 = 0.0;
        const Real a2 = -omega / q;
        const Real b0 = ra::cexpr_math::sqr<Real>(omega) + omega / q + 1.0;
        const Real b1 = 2.0 * (ra::cexpr_math::sqr<Real>(omega) - 1.0);
        const Real b2 = ra::cexpr_math::sqr<Real>(omega) - omega / q + 1.0;

        return biquad_filter_coefs<Real>(a0, a1, a2, b0, b1, b2);
    }

    // Returns the coefficients for a biquad low-frequency shelving
    // boost filter with normalized cutoff frequency f and gain-control
    // parameter a, where f in [0,1] and a >= 0.
    // For a gain in dB of G (where G > 0), choose a = 10 ˆ (G / 20).
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real>
    constexpr biquad_filter_coefs<Real> lowshelf_boost(Real f, Real a) {
        if (f < 0 || f > 1 || a < 0) {
            throw std::invalid_argument("invalid low-frequency shelving boost filter parameters");
        }

        const Real omega = ra::cexpr_math::tan<Real>(ra::cexpr_math::pi<Real> / 2.0 * f);
        const Real a0 = a * ra::cexpr_math::sqr<Real>(omega) + ra::cexpr_math::sqrt<Real>(2.0 * a) * omega + 1.0;
        const Real a1 = 2.0 * (a * ra::cexpr_math::sqr<Real>(omega) - 1.0);
        const Real a2 = a * ra::cexpr_math::sqr<Real>(omega) - ra::cexpr_math::sqrt<Real>(2.0 * a) * omega + 1.0;
        const Real b0 = ra::cexpr_math::sqr<Real>(omega) + ra::cexpr_math::sqrt<Real>(2.0) * omega + 1.0;
        const Real b1 = 2.0 * (ra::cexpr_math::sqr<Real>(omega) - 1.0);
        const Real b2 = ra::cexpr_math::sqr<Real>(omega) - ra::cexpr_math::sqrt<Real>(2.0) * omega + 1.0;

        return biquad_filter_coefs<Real>(a0, a1, a2, b0, b1, b2);
    }

    // Returns the coefficients for a biquad low-frequency shelving
    // cut filter with normalized cutoff frequency f and gain-control
    // parameter a, where f in [0,1] and a >= 0.
    // For a gain in dB of G (where G < 0), choose a = 10 ˆ (-G / 20).
    // The filter coefficients are always normalized such that the
    // coefficient b0 is 1.
    // The type Real is a floating-point type.
    // All real arithmetic should be performed with the Real type.
    template <class Real>
    constexpr biquad_filter_coefs<Real> lowshelf_cut(Real f, Real a) {
        if (f < 0 || f > 1 || a < 0) {
            throw std::invalid_argument("invalid low-frequency shelving cut filter parameters");
        }

        const Real omega = ra::cexpr_math::tan<Real>(ra::cexpr_math::pi<Real> / 2.0 * f);
        const Real a0 = ra::cexpr_math::sqr<Real>(omega) + ra::cexpr_math::sqrt<Real>(2.0) * omega + 1.0;
        const Real a1 = 2.0 * (ra::cexpr_math::sqr<Real>(omega) - 1.0);
        const Real a2 = ra::cexpr_math::sqr<Real>(omega) - ra::cexpr_math::sqrt<Real>(2.0) * omega + 1.0;
        const Real b0 = a * ra::cexpr_math::sqr<Real>(omega) + ra::cexpr_math::sqrt<Real>(2.0 * a) * omega + 1.0;
        const Real b1 = 2.0 * (a * ra::cexpr_math::sqr<Real>(omega) - 1.0);
        const Real b2 = a * ra::cexpr_math::sqr<Real>(omega) - ra::cexpr_math::sqrt<Real>(2.0 * a) * omega + 1.0;

        return biquad_filter_coefs<Real>(a0, a1, a2, b0, b1, b2);
    }

}  // namespace ra::biquad