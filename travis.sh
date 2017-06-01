#!/usr/bin/env bash
echo ${PATH}

echo "CMake path:"
which cmake

# create cmake directory
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles"

# run tests
cmake --build cmake-build-debug --target runSnakePlusPlusTests

# run program
cmake --build cmake-build-debug --target runSnakePlusPlusTests
