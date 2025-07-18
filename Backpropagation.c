#include"Backpropagation.h"
double ELUderivative(double x) {
    if (x > 0) {
        return 1.0;
    } else {
        return 1.0 * exp(x);
    }
}
double sigmoidDerivative(double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}
double getIndvCost(double expected, double output){
    return (expected-output)*(expected-output);
}

double getIndvCostDeriv(double expected, double output){
    return 2*(output-expected);
}

double calculateNetworkCost(NeuralNetwork* network, double* expectedOutputs) {
    double totalCost = 0.0;
    size_t outputLayer = network->numLayers - 1;
    
    for (size_t neuron = 0; neuron < network->layers[outputLayer].numNeurons; neuron++) {
        double output = network->layers[outputLayer].neurons[neuron].val;
        double expected = expectedOutputs[neuron];
        totalCost += getIndvCost(expected, output);
    }
    
    return totalCost / network->layers[outputLayer].numNeurons; // Mean squared error
}
void computeAllNetworkGradients(NeuralNetwork* network, double* expectedOutputs) {
    double** deltas = (double**)malloc(network->numLayers * sizeof(double*));
    for (size_t layer = 0; layer < network->numLayers; layer++) {
        deltas[layer] = (double*)calloc(network->layers[layer].numNeurons, sizeof(double));
    }
    
    size_t outputLayer = network->numLayers - 1;
    for (size_t neuron = 0; neuron < network->layers[outputLayer].numNeurons; neuron++) {
        double z = network->layers[outputLayer].neurons[neuron].Z;
        double output = network->layers[outputLayer].neurons[neuron].val;
        double expected = expectedOutputs[neuron];
        
        double costDeriv = getIndvCostDeriv(expected, output);
        double activationDeriv = ELUderivative(z);
        deltas[outputLayer][neuron] = costDeriv * activationDeriv;
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

void updateNetworkWeights(NeuralNetwork* network, double learningRate) {
    for (size_t layer = 0; layer < network->numLayers - 1; layer++) {
        for (size_t neuron = 0; neuron < network->layers[layer].numNeurons; neuron++) {
            for (size_t nextNeuron = 0; nextNeuron < network->layers[layer + 1].numNeurons; nextNeuron++) {
                double gradient = network->layers[layer].neurons[neuron].weightsGradients[nextNeuron];
                network->layers[layer].neurons[neuron].weights[nextNeuron] -= learningRate * gradient;
            }
        }
    }
    for (size_t layer = 1; layer < network->numLayers; layer++) {
        for (size_t neuron = 0; neuron < network->layers[layer].numNeurons; neuron++) {
            double gradient = network->layers[layer].neurons[neuron].biasGradient;
            network->layers[layer].neurons[neuron].bias -= learningRate * gradient;
        }
    }
}

double learnFromSample(NeuralNetwork* network, double* inputs, double* expectedOutputs, double learningRate) {
    for (size_t i = 0; i < network->layers[0].numNeurons; i++) {
        network->layers[0].neurons[i].val = inputs[i];
    }
    forwardPass(network);
    double cost = calculateNetworkCost(network, expectedOutputs);
    computeAllNetworkGradients(network, expectedOutputs);
    updateNetworkWeights(network, learningRate);
    printf("\nCost: %f", cost);
    return cost;
}