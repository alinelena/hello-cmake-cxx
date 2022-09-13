# hello-cmake-cxx
simple hello world like example using cmake with C++ as programming language.

* shows usage of optional features: -DWITH_MYMATH=On (default: On)
* building shared and static libs: -DBUILD_SHARED_LIBS=On (defaut: On)
* building api documentation with doxygen: -DBUILD_DOCS=On (default: On)
* generating tests: -DBUILD_TESTING=On (default: On)

## build the project
```bash

   #clone
   git clone https://github.com/alinelena/hello-cmake-cxx.git
   cmake -S. -Bbuild -DBUILD_TESTING=On
   cmake --build build
   ctest --test-dir build

   cmake --install  build# use -DCMAKE_INSTALL_PREFIX=/path  to control the installation path
   cmake --build build -t docs
   cmake --build build -t test
   cmake --build -t coverage
   cmake --build -t  runcoverage
```

## cross-compile for windows
opensuse mingw32 chain assumed. Edit winhelper.cmake to match other chains
```
mkdir build-win
pushd build-win
cmake ../ -DCMAKE_TOOLCHAIN_FILE=../cmake/winhelper.cmake
make
popd
```
