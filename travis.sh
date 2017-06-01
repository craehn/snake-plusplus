#!/usr/bin/env bash

# create cmake-build-debug dir
sudo mkdir cmake-build-debug

# build to directory
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles"

# run tests
cmake --build . --target runSnakePlusPlusTests

# run program
cmake --build . --target snake-plusplus_run
