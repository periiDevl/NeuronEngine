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
double OmniWeightContribute(NeuralNetwork* network, unsigned long long int indexLayer, unsigned long long int path)
{
    double contribute = 1;
    for (size_t i = network->numLayers-1; i > indexLayer; i--)
    {
        if (i != network->numLayers - 1){
            contribute = contribute * network->layers[i].neurons[path].weights[0];
        }
        contribute = contribute * ELUderivative(network->layers[i].neurons[path].Z);
    }
    
    contribute = contribute * network->layers[indexLayer].neurons[path].val;
    contribute = contribute * ELUderivative(network->layers[indexLayer].neurons[path].Z);
    
    return contribute;
    
}