#include"Backpropagation.h"
double ELUderivative(double x) {
    if (x > 0) {
        return 1.0;
    } else {
        return 1.0 * exp(x);
        // return (y + ELU_ALPHA); // for x <= 0
    }
}
double sigmoidDerivative(double x) {
    double s = sigmoid(x); // Calculate sigmoid(x) once to avoid redundant computation
    return s * (1.0 - s);
}

void computeAllNetworkGradients(NeuralNetwork* network) {
    double** deltas = (double**)malloc(network->numLayers * sizeof(double*));
    for (size_t layer = 0; layer < network->numLayers; layer++) {
        deltas[layer] = (double*)calloc(network->layers[layer].numNeurons, sizeof(double));
    }
    
    size_t outputLayer = network->numLayers - 1;
    for (size_t neuron = 0; neuron < network->layers[outputLayer].numNeurons; neuron++) {
        double z = network->layers[outputLayer].neurons[neuron].Z;
        deltas[outputLayer][neuron] = ELUderivative(z) * 1.0; // Replace 1.0 with actual loss derivative
    }
    
    for (int layer = network->numLayers - 2; layer >= 0; layer--) {
        for (size_t neuron = 0; neuron < network->layers[layer].numNeurons; neuron++) {
            double sum = 0.0;
            
            for (size_t nextNeuron = 0; nextNeuron < network->layers[layer + 1].numNeurons; nextNeuron++) {
                double weight = network->layers[layer].neurons[neuron].weights[nextNeuron];
                sum += deltas[layer + 1][nextNeuron] * weight;
            }
            
            double z = network->layers[layer].neurons[neuron].Z;
            deltas[layer][neuron] = sum * ELUderivative(z);
        }
    }
    
    for (size_t layer = 0; layer < network->numLayers - 1; layer++) {
        for (size_t neuron = 0; neuron < network->layers[layer].numNeurons; neuron++) {
            for (size_t nextNeuron = 0; nextNeuron < network->layers[layer + 1].numNeurons; nextNeuron++) {
                double input_activation = network->layers[layer].neurons[neuron].val;
                double gradient = input_activation * deltas[layer + 1][nextNeuron];
                
                network->layers[layer].neurons[neuron].weightsGradients[nextNeuron] = gradient;
            }
        }
    }
    
    for (size_t layer = 1; layer < network->numLayers; layer++) {
        for (size_t neuron = 0; neuron < network->layers[layer].numNeurons; neuron++) {
            network->layers[layer].neurons[neuron].biasGradient = deltas[layer][neuron];
        }
    }
    
    for (size_t layer = 0; layer < network->numLayers; layer++) {
        free(deltas[layer]);
    }
    free(deltas);
}

