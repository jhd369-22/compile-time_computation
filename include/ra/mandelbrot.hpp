#include <ra/cexpr_basic_string.hpp>

namespace ra::fractal {

    template <std::size_t W, std::size_t H>
    constexpr bool binary_map(std::size_t K, std::size_t L) {
        const double r = -1.6 + K * ((0.6 + 1.6) / (W - 1));
        const double i = -1.1 + (H - 1 - L) * ((1.1 + 1.1) / (H - 1));
        double z_r = r;
        double z_i = i;
        int count = 0;

        while (true) {
            double temp_z_r = z_r;

            z_r = z_r * z_r - z_i * z_i + r;
            z_i = temp_z_r * z_i + z_i * temp_z_r + i;
            ++count;

            if (z_r * z_r + z_i * z_i > 4) {
                return false;
            } else if (count == 16) {
                return true;
            }
        }
    }

    // returns a cexpr_string<M> object that contains the Mandelbrot set.
    template <std::size_t W, std::size_t H>
    constexpr auto mandelbrot_to_binary() {
        char width[10];
        char height[10];
        char* width_ptr = width;
        char* height_ptr = height;

        ra::cexpr::to_string(W, width, 10, &(width_ptr));
        ra::cexpr::to_string(H, height, 10, &(width_ptr));

        ra::cexpr::cexpr_string<(W + 1) * (H + 1)> s("P1 ");

        //char* temp = s.end();
        //ra::cexpr::to_string(W, temp, W * H, &(temp));
        s.append(width);
        s.push_back(' ');

        //temp = s.end();
        //ra::cexpr::to_string(H, temp, W * H, &(temp));
        s.append(height);
        s.push_back('\n');

        for (std::size_t L = 0; L < H; ++L) {
            for (std::size_t K = 0; K < W; ++K) {

                binary_map<W, H>(K, L) ? s.push_back('1') : s.push_back('0');
            }
            s.push_back('\n');
        }
        return s;
    }

    // A variable template for a string that represents an image depicting
    // the Mandelbrot set. The image has width W and height H.
    // This object must be of type cexpr_string<M> for some appropriate M.
    // The string is a binary image encoded in the text-based bitmap PNM
    // format.
    // The values of W and H must be such that W >= 2 and H >= 2.
    template <std::size_t W, std::size_t H>
    constexpr auto mandelbrot = mandelbrot_to_binary<W, H>();

}  // namespace ra::fractal