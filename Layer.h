#ifndef H_LAYER
#define H_LAYER
#include"Neuron.h"
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Layer Layer;
typedef struct Layer
{
    Neuron* neurons; //The array of Neurons
    unsigned long long int numNeurons; // Size of Neurons array
    Layer* next;
}Layer;
void resetLayer(Layer* layer);
void setNeuronsSize(Layer* layer, unsigned long long int n);;
void setUpNeuronsParam(Layer* layer);
void freeLayer(Layer* Layer); // Free allocated mem
#endif