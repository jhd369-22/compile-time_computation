To compile the code(for example):
cmake -S . -B tmp -D CMAKE_CXX_COMPILER=clang++

To test the code of mandelbrot set:
./tmp/test_mandelbrot >> mandelbrot.pnm
display mandelbrot.pnm
