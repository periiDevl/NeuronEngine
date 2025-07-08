#ifndef H_NEURAL_NETWORK
#define H_NEURAL_NETWORK
#include "Layer.h"

typedef struct NeuralNetwork
{
    Layer* layers; //the Layers of the NeuralNetwork pointer to a dynamic array
    unsigned long long int numLayers;
}NeuralNetwork;
void createNeuralNetwork(NeuralNetwork* network, unsigned long long int n); //Creates the WHOLE network and has an arc, array that stores the way the network will be genrated
void linkLayers(NeuralNetwork* network);
void setLayersParam(NeuralNetwork* network);
void forwardPass(NeuralNetwork* network);
void freeNetwork(NeuralNetwork* network);
#endif