#!/bin/bash

# Navigate to the project directory (optional, if you run the script from elsewhere)
# cd ~/Documents/C/NeuronEngine

echo "Compiling NeuronEngine..."
gcc -o NeuronEngine *.c -I. -lm

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running NeuronEngine..."
    ./NeuronEngine
else
    echo "Compilation failed. Please check for errors."
fi

