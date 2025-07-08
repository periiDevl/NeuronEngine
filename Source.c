#include <stdio.h>
#include <stdbool.h>
#include "Neuron.h"
#include "Layer.h"
#include"NeuralNetwork.h"
#include"Backpropagation.h"
int main() {

    NeuralNetwork network;
    createNeuralNetwork(&network, 3);
    linkLayers(&network);
    setNeuronsSize(&network.layers[0],1);
    setNeuronsSize(&network.layers[1],1);
    setNeuronsSize(&network.layers[2],1);
    setLayersParam(&network);
    network.layers[0].neurons[0].Z = 0.5;
    network.layers[0].neurons[0].bias = 0;
    network.layers[0].neurons[0].weights[0] = 0.7;

    network.layers[1].neurons[0].weights[0] = 0.8;
    network.layers[1].neurons[0].bias = 0;

    forwardPass(&network);
    activate(&network.layers[2].neurons[0]);
    printf("N1 = %f", network.layers[2].neurons[0].val);
    printf("w1 gradient contribution = %f\n", OmniWeightContribute(&network,1,0));
    freeNetwork(&network);
    
}