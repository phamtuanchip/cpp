# cpp
C++ best practice
# Online IDE
https://ide.geeksforgeeks.org
# Local
g++

https://curl.haxx.se/docs/install.html
mingw32-make mingw32

g++ request.cpp -I"C:\projects\vcpkg\installed\x64-windows\include" -L"C:\projects\vcpkg\installed\x64-windows\lib\" -lcpprest_2_10.lib

buil cpprest
cmake . -A x64 -DCMAKE_TOOLCHAIN_FILE=C:\projects\vcpkg\scripts\buildsystems\vcpkg.cmake

vsc++
cl /EHsc request.cpp /IC:\projects\vcpkg\installed\x64-windows\include /IC:\projects\vcpkg\installed\x64-windows\share /IC:\projects\vcpkg\installed\x64-windows\bin

cl /EHsc request.cpp /IC:\projects\vcpkg\installed\x86-windows\include /IC:\projects\vcpkg\installed\x86-windows\share /IC:\projects\vcpkg\installed\x86-windows\bin