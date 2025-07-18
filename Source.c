#include <stdio.h>
#include <stdbool.h>
#include "Neuron.h"
#include "Layer.h"
#include"NeuralNetwork.h"
#include"Backpropagation.h"
#include <stdlib.h>
#include <time.h>


double randomDouble(double min, double max) {
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}
int main() {
    srand(time(NULL));
    NeuralNetwork network;
    createNeuralNetwork(&network, 3);
    linkLayers(&network);
    
    setNeuronsSize(&network.layers[0], 2); //Input layer: 2 neurons
    setNeuronsSize(&network.layers[1], 2); //Hidden layer: 2 neurons  
    setNeuronsSize(&network.layers[2], 1); //Output layer: 1 neuron
    
    setLayersParam(&network);
    
    double max = 3.0; 
    
    network.layers[0].neurons[0].weights[0] = randomDouble(-max, max);
    network.layers[0].neurons[0].weights[1] = randomDouble(-max, max);
    network.layers[0].neurons[1].weights[0] = randomDouble(-max, max);
    network.layers[0].neurons[1].weights[1] = randomDouble(-max, max);
    network.layers[1].neurons[0].weights[0] = randomDouble(-max, max);
    network.layers[1].neurons[1].weights[0] = randomDouble(-max, max);
    
    network.layers[1].neurons[0].bias = randomDouble(-max, max);
    network.layers[1].neurons[1].bias = randomDouble(-max, max);
    network.layers[2].neurons[0].bias = randomDouble(-max, max);
    
    network.layers[0].neurons[0].bias = 0.0;
    network.layers[0].neurons[1].bias = 0.0;
    
    double inputs[2] = {500, 300};
    double expected[1] = {0.8777};
    
    for (size_t i = 0; i < 2000; i++) {
        learnFromSample(&network, inputs, expected, 0.01);
    }
    forwardPass(&network);
    printf("\n %f", network.layers[2].neurons[0].val);
    freeNetwork(&network);
    return 0;
}