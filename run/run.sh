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

# Run the application
g++ -std=c++11 *.cpp -o threadmainrun.exe -lpthread

#Execute the program
echo "Running ThreadMe application..."
./threadmainrun.exe
