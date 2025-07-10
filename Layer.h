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
void setNeuronsSize(Layer* layer, unsigned long long int n);
void connectToFirstLayer(Layer* l1,Layer* l2);
void connectNeuronToLayer(Neuron* neuron, Layer* layer, int activ);
void connectToLayer(Layer* l1,Layer* l2);
void setUpNeuronsParam(Layer* layer);
void freeLayer(Layer* Layer); // Free allocated mem
#endif