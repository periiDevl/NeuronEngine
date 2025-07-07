#include"Neuron.h"
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
void inputWeightsSize(Neuron* neuron, unsigned long long int n)
{
    assert(neuron != NULL && "NEURON CANNOT BE NULL!"); //Cannot be NULL at all!
    if (neuron->weights != NULL) {free(neuron->weights); neuron->weights = NULL;} //Free if not null
    neuron->weightsSize = 0;
    neuron->weights = (double*)malloc(n*sizeof(double)); //Allocate size

    if (neuron->weights == NULL) {
        printf("Error: Allocation FAILED for neuron weights.\n");
        neuron->weightsSize = 0; 
        return;
    }
    neuron->weightsSize = n;
    printf("Allocated Weights Successfully!");
    
}
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void activate(Neuron* neuron)
{
    neuron->val = sigmoid(neuron->Z+neuron->bias);
}
void freeNeuron(Neuron* neuron) {
    if (neuron == NULL) {
        printf("Warning: Attempted to free memory for a NULL Neuron pointer. No action taken.\n");
        return;
    }

    if (neuron->weights != NULL) {
        free(neuron->weights);      
        neuron->weights = NULL;     
        printf("Freed weights array for neuron.\n");
    } else {
        printf("Weights array for neuron was already NULL or not allocated. No free needed.\n");
    }

}
