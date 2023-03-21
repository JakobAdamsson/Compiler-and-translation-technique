#!/bin/bash

# Clean old files
make clean

# Build the compiler
make

# Run the compiler on the input file
./compiler test.txt

make tree

make st

make ir