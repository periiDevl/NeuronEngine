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
void forwardPass(NeuralNetwork* network) {
    Layer* layer = &network->layers[0];
    while (layer != NULL && layer->next != NULL) {
        layerForward(layer);
        layer = layer->next;
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