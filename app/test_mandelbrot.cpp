#include <iostream>
#include <ra/mandelbrot.hpp>

int main()
{
// Force the image (in PNM format) to be computed at compile time.
constexpr auto s = ra::fractal::mandelbrot<512, 512>;

// Output the image (in PNM format).
std::cout << s.begin() << '\n';

return (std::cout) ? 0 : 1;
}