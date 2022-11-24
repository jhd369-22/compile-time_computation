To compile the code(for example):<br>
cmake -S . -B tmp -D CMAKE_CXX_COMPILER=clang++<br>

To test the code of mandelbrot set:<br>
./tmp/test_mandelbrot >> mandelbrot.pnm<br>
display mandelbrot.pnm<br>
