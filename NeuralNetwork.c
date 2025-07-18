#include"NeuralNetwork.h"
void resetNeuralNetwork(NeuralNetwork* network){
    for (size_t i = 0; i < network->numLayers; i++)
    {
        resetLayer(&network->layers[i]);
    }
    
}
void createNeuralNetwork(NeuralNetwork* network, unsigned long long int n)
{
    assert(network != NULL && "NETWORK CANNOT BE NULL!"); //Cannot be NULL at all!
    if (network->layers != NULL) {free(network->layers); network->layers = NULL;} //Free if not null
    network->numLayers = 0;
    network->layers = (Layer*)malloc(n*sizeof(Layer)); //Allocate size

    if (network->layers == NULL) {
        printf("Error: Allocation FAILED for network.\n");
        network->numLayers = 0; 
        return;
    }
    network->numLayers = n;
    printf("Allocated Neurons Successfully!");
    
}
void linkLayers(NeuralNetwork* network)
{
    for (size_t i = 0; i < network->numLayers - 1; i++)
    {
        network->layers[i].next = &network->layers[i+1];
    }
    
}
void setLayersParam(NeuralNetwork* network)
{
    for (size_t i = 0; i < network->numLayers - 1; i++)
    {
        setUpNeuronsParam(&network->layers[i]);
    }
}
void forwardPass(NeuralNetwork* network)
{
    //Reset Z values for all neurons except input layer
    for (size_t layer = 1; layer < network->numLayers; layer++) {
        for (size_t neuron = 0; neuron < network->layers[layer].numNeurons; neuron++) {
            network->layers[layer].neurons[neuron].Z = 0.0;
        }
    }
    
    for (size_t layer = 0; layer < network->numLayers - 1; layer++) {
        for (size_t neuron = 0; neuron < network->layers[layer].numNeurons; neuron++) {
            double activation = network->layers[layer].neurons[neuron].val;
            
            for (size_t nextNeuron = 0; nextNeuron < network->layers[layer + 1].numNeurons; nextNeuron++) {
                double weight = network->layers[layer].neurons[neuron].weights[nextNeuron];
                network->layers[layer + 1].neurons[nextNeuron].Z += activation * weight;
            }
        }
        if (layer + 1 > 0) {
            for (size_t neuron = 0; neuron < network->layers[layer + 1].numNeurons; neuron++) {
                network->layers[layer + 1].neurons[neuron].Z += network->layers[layer + 1].neurons[neuron].bias;
                activate(&network->layers[layer + 1].neurons[neuron]);
            }
        }
    }
}

void freeNetwork(NeuralNetwork* network)
{
    if (network == NULL) {
        return;
    }
    for (size_t i = 0; i < network->numLayers; i++)
    {
        freeLayer(&network->layers[i]);
    }
    if (network->layers != NULL) {
        free(network->layers);      
        network->layers = NULL;     
    } 
}