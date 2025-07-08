#include"Layer.h"
void setNeuronsSize(Layer* layer, unsigned long long int n)
{
    assert(layer != NULL && "LAYER CANNOT BE NULL!"); //Cannot be NULL at all!
    if (layer->neurons != NULL) {free(layer->neurons); layer->neurons = NULL;} //Free if not null
    layer->numNeurons = 0;
    layer->neurons = (Neuron*)malloc(n*sizeof(Neuron)); //Allocate size

    if (layer->neurons == NULL) {
        printf("Error: Allocation FAILED for neurons.\n");
        layer->numNeurons = 0; 
        return;
    }
    layer->numNeurons = n;
    printf("Allocated Neurons Successfully!");
    
}


void connectNeuronToLayer(Neuron* neuron, Layer* layer)
{
    activate(neuron);
    for (size_t i = 0; i < layer->numNeurons; i++)
    {
        layer->neurons[i].Z += neuron->val*neuron->weights[i];
    }
    
}
void connectToLayer(Layer* l1,Layer* l2)
{
    for (size_t i = 0; i < l1->numNeurons; i++)
    {
        connectNeuronToLayer(&l1->neurons[i],l2);
    }
    
}
void setUpNeuronsParam(Layer* layer)
{
    for (size_t i = 0; i < layer->numNeurons; i++)
    {
        calNeuronWeightsSize(&layer->neurons[i], layer->next->numNeurons);
    }
}


void freeLayer(Layer* layer){
    if (layer == NULL) {
        return;
    }
    for (size_t i = 0; i < layer->numNeurons; i++)
    {
        freeNeuron(&layer->neurons[i]);
    }
    
    if (layer->neurons != NULL) {
        free(layer->neurons);      
        layer->neurons = NULL;     
    } 
}