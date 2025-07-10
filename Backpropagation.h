#ifndef H_BACKPROP
#define H_BACKPROP
#include"NeuralNetwork.h"

double followWeightPath(NeuralNetwork* network, unsigned long long int targetLayer, unsigned long long int targetNeuron, unsigned long long targetWeight);
double sigmoidDerivative(double Z);
#endif