#build
cd build
# linux
cmake ..
make -j
# windows
cmake -G "MinGW Makefiles" ..
cmake --build .
