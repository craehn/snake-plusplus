#!/usr/bin/env bash
echo ${PATH}

echo "CMake path:"
which cmake

# create cmake-build-debug dir
sudo mkdir cmake-build-debug

# build to directory
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" cmake-build-debug

# run tests
cmake --build cmake-build-debug --target runSnakePlusPlusTests

# run program
cmake --build cmake-build-debug --target runSnakePlusPlusTests
