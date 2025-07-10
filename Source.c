#include <stdio.h>
#include <stdbool.h>
#include "Neuron.h"
#include "Layer.h"
#include"NeuralNetwork.h"
#include"Backpropagation.h"
int main() {

    // Based on your network setup, here's what should happen:

// Network structure:
// Layer 0: 3 neurons (input layer)
// Layer 1: 2 neurons (hidden layer) 
// Layer 2: 1 neuron (output layer)

// Your weights setup:
// Layer 0, Neuron 0: weights[0]=0.70, weights[1]=0.4, weights[2]=0.45
// Layer 1, Neuron 0: weights[0]=0.8
// Layer 1, Neuron 1: weights[0]=0.1

// The problem: You need to set INPUT VALUES, not just Z values
// Here's the corrected setup:

    NeuralNetwork network;
    createNeuralNetwork(&network, 3);
    linkLayers(&network);
    setNeuronsSize(&network.layers[0], 3);
    setNeuronsSize(&network.layers[1], 2);
    setNeuronsSize(&network.layers[2], 1);
    setLayersParam(&network);
    // Set weights
    network.layers[0].neurons[0].val = 0.20;
    network.layers[0].neurons[0].val = 0.1;
    network.layers[0].neurons[0].val = 0.35;
    network.layers[0].neurons[0].Z = 0.20;
    network.layers[0].neurons[0].Z = 0.1;
    network.layers[0].neurons[0].Z = 0.35;

    network.layers[0].neurons[0].weights[0] = 0.70;
    network.layers[0].neurons[0].weights[1] = 0.4;
    network.layers[0].neurons[0].weights[2] = 0.45;

    network.layers[0].neurons[1].weights[0] = 0.30;
    network.layers[0].neurons[1].weights[1] = 0.25;
    network.layers[0].neurons[1].weights[2] = 0.35; 

    network.layers[0].neurons[2].weights[0] = 0.15;
    network.layers[0].neurons[2].weights[1] = 1.20; 
    network.layers[0].neurons[2].weights[2] = 2.10;

    network.layers[1].neurons[0].weights[0] = 0.9;
    network.layers[1].neurons[1].weights[0] = 0.9;

    // Set biases
    network.layers[0].neurons[0].bias = 0;
    network.layers[0].neurons[1].bias = 0;
    network.layers[0].neurons[2].bias = 0;
    network.layers[1].neurons[0].bias = 0;
    network.layers[1].neurons[1].bias = 0;
    network.layers[2].neurons[0].bias = 0;

    forwardPass(&network);
    activate(&network.layers[2].neurons[0]);
    printf("N1 = %f", network.layers[2].neurons[0].val);
    printf("w1 gradient contribution = %f\n", followWeightPath(&network,1,0,0));
    freeNetwork(&network);
    
}