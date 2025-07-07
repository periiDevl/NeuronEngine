#ifndef H_NEURAL_NETWORK
#define H_NEURAL_NETWORK
#include "Layer.h"

typedef struct
{
    Layer* layers; //the Layers of the NeuralNetwork pointer to a dynamic array
}NeuralNetwork;

#endif