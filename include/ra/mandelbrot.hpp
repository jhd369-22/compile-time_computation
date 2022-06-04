namespace ra::fractal {

// A variable template for a string that represents an image depicting
// the Mandelbrot set. The image has width W and height H.
// This object must be of type cexpr_string<M> for some appropriate M.
// The string is a binary image encoded in the text-based bitmap PNM
// format.
// The values of W and H must be such that W >= 2 and H >= 2.
template <std::size_t W, std::size_t H>
constexpr auto mandelbrot = implementation-defined;

}