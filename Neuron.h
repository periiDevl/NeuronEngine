#ifndef NEURON_H
#define NEURON_H
#include <math.h> 
typedef struct
{
    double* weights; //Pointer to the weights array
    unsigned long long int weightsSize; //Size for the array of weights
    double bias; // Pointer to the Biases array
    double Z; //The raw value of the Neuron
    double val; //The value of the Neuron
}Neuron;
void inputWeightsSize(Neuron* neuron, unsigned long long int n); //Input the size of weights to have so we can Malloc the right size
double sigmoid(double x);
void activate(Neuron* neuron);
void freeNeuron(Neuron* neuron); // Free allocated mem
#endif