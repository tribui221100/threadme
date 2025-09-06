#!/bin/bash

# Script to run the ThreadMe application

# Stop on errors
set -e

# Navigate to the application directory
app_dir="$(dirname "$0")/../threadme"
if [ ! -d "$app_dir" ]; then
  echo "Error: Application directory '$app_dir' does not exist."
  exit 1
fi

cd "$app_dir"

# List avalailable cpp files
echo "Available C++ files in the directory:"
select cpp_file in *.cpp; do
    if [ -n "$cpp_file" ]; then 
        echo "You selected '$cpp_file'"
        break
    else
        echo "Invalid selection. Please try again."
    fi
done

# Run the application
g++ -std=c++11 main.cpp "$cpp_file" -o threadmainrun.exe -lpthread

#Execute the program
echo "Running ThreadMe application..."
./threadmainrun.exe