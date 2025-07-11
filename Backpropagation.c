#include"Backpropagation.h"
enum NextCalculationType{
    DERIV_WEIGHT, //How much is a weight affecting the 
    DERIV_NEURON, //How much a neuron is affecting the Z of another neuron
    DERIV_ACTIVATION, //How much is a value affecting the activation func
    DERIV_BIAS
};
double ELUderivative(double x) {
    if (x > 0) {
        return 1.0;
    } else {
        return 1.0 * exp(x);
        // Alternatively, if you have the activated output 'y = elu_activation(x)':
        // return (y + ELU_ALPHA); // for x <= 0
    }
}
double followPathNeuron(NeuralNetwork* network, unsigned long long int targetLayer, unsigned long long int targetNeuron, unsigned long long int currNeuron, unsigned long long int currLayer, double val)
{
    if (currLayer == network->numLayers - 1)
    {
        return val;
    }
    
    double totalContribution = 0.0;
    
    for (size_t nextNeuron = 0; nextNeuron < network->layers[currLayer + 1].numNeurons; nextNeuron++)
    {
        double weight = network->layers[currLayer].neurons[currNeuron].weights[nextNeuron];
        double derivative = ELUderivative(network->layers[currLayer + 1].neurons[nextNeuron].Z);
        totalContribution += followPathNeuron(network, targetLayer, targetNeuron, nextNeuron, currLayer + 1, val * weight * derivative);
    }
    
    return totalContribution;
}

double followWeightPath(NeuralNetwork* network, unsigned long long int targetLayer, 
                       unsigned long long int targetNeuron, unsigned long long targetWeight) {
    if (targetLayer == 0) {
        return 0.0;  // Input layer has no weights to update
    }
    
    double input_activation = network->layers[targetLayer - 1].neurons[targetWeight].val;
    double activation_derivative = ELUderivative(network->layers[targetLayer].neurons[targetNeuron].Z);
    
    // For output layer, the gradient is just the error * activation_derivative
    if (targetLayer == network->numLayers - 1) {
        return input_activation * activation_derivative;
    }
    
    // For hidden layers, we need to accumulate contributions from all downstream paths
    double downstream_gradient = 0.0;
    for (size_t nextNeuron = 0; nextNeuron < network->layers[targetLayer + 1].numNeurons; nextNeuron++) {
        double weight = network->layers[targetLayer].neurons[targetNeuron].weights[nextNeuron];
        double next_derivative = ELUderivative(network->layers[targetLayer + 1].neurons[nextNeuron].Z);
        downstream_gradient += followPathNeuron(network, targetLayer, targetNeuron, nextNeuron, targetLayer + 1, weight * next_derivative);
    }
    
    return input_activation * activation_derivative * downstream_gradient;
}