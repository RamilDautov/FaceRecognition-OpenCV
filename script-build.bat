@echo off
cd 'paste here path of the current directory'
cmake -S . -B build -D OPEN_CV_LIB_PATH='paste here path of the .../opencv/build directory'
cmake --build build --config Release
pause