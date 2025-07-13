#ifndef H_BACKPROP
#define H_BACKPROP
#include"NeuralNetwork.h"

double ELUderivative(double x);
double sigmoidDerivative(double x);
void computeAllNetworkGradients(NeuralNetwork* network);
#endif