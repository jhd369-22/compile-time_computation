#include <ra/cexpr_basic_string.hpp>

namespace ra::fractal {

// returns a cexpr_string<M> object that contains the Mandelbrot set.
template <std::size_t W, std::size_t H>
constexpr ra::cexpr::cexpr_string<W * H> mandelbrot() {
    ra::cexpr::cexpr_string<W * H> s("P1 ");
    std::size_t r = 0;
    std::size_t i = 0;

    s.to_string(W, &(*(s.end())), W * H, &(s.end()));
    s.push_back(' ');
    s.to_string(H, &(*(s.end())), W * H, &(s.end()));
    s.push_back('\n');

    for (std::size_t idx = 0; idx < H; ++idx) {
        for (std::size_t idx2 = 0; idx2 < W; ++idx2) {
            s.to_string();
        }
        return s;
    }
}

constexpr std::size_t binary_map(std::size_t r, std::size_t i) {

}

    // A variable template for a string that represents an image depicting
    // the Mandelbrot set. The image has width W and height H.
    // This object must be of type cexpr_string<M> for some appropriate M.
    // The string is a binary image encoded in the text-based bitmap PNM
    // format.
    // The values of W and H must be such that W >= 2 and H >= 2.
    template <std::size_t W, std::size_t H>
    constexpr auto mandelbrot = ra::cexpr::cexpr_string<W * H>();

}  // namespace ra::fractal
   /*
   [](auto& s) {
       for (std::size_t i = 0; i < H; ++i) {
           for (std::size_t j = 0; j < W; ++j) {
               s[i * W + j] = (s[i * W + j] == 0) ? '0' : '1';
           }
       }
   }*/