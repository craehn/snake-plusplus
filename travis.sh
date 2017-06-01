#!/usr/bin/env bash

# create cmake-build-debug dir
sudo mkdir cmake-build-debug

# build to directory
cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles"

# run tests
echo "\n\n\nBuilding and running tests"
cmake --build . --target runSnakePlusPlusTests

# run program
echo "\n\n\nBuilding and running executable"
cmake --build . --target snake-plusplus_run
