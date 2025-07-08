#ifndef H_BACKPROP
#define H_BACKPROP
#include"NeuralNetwork.h"

double OmniWeightContribute(NeuralNetwork* network, unsigned long long int indexLayer, unsigned long long int path);
double sigmoidDerivative(double Z);
#endif