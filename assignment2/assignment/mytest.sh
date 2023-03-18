#!/bin/bash

# Create a new output file
output_file="output.txt"
echo "Output:" > "$output_file"

# Get a list of all the directories in the testfiles directory
directories=$(find test_files -type d)

# Loop through all the directories and run your C++ program for each file with the .cpp extension
for dir in $directories
do
  for file in $dir/*.java
  do
    echo "Processing $file"
    echo "============================================" >> "$output_file"
    echo "File: $file" >> "$output_file"
    echo "============================================" >> "$output_file"
    if ./compiler "$file" >> "$output_file"; then
      echo "Success: $file"
    else
      echo "Error: $file"
    fi
  done
done
