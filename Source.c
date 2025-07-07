#include <stdio.h>
#include <stdbool.h>
#include "Neuron.h"
#include "Layer.h"
int main() {

    Layer layer1;
    Layer layer2;
    layer1.next = &layer2;
    setNeuronsSize(&layer2, 2);
    setNeuronsSize(&layer1, 2);
    setUpNeuronsParam(&layer1);
    layer1.neurons[0].Z = 0.6;
    layer1.neurons[1].Z = 0.8;

    layer1.neurons[0].bias = 0.15;
    layer1.neurons[1].bias = 0.05;

    layer1.neurons[0].weights[0] = 0.3;
    layer1.neurons[0].weights[1] = 0.9;
    
    layer1.neurons[1].weights[0] = 0.5;
    layer1.neurons[1].weights[1] = 0.1;

    connectToLayer(&layer1, &layer2);
    printf("N1 = %f", layer2.neurons[0].Z);
    printf("N2 = %f", layer2.neurons[1].Z);
    freeLayer(&layer1);
    freeLayer(&layer2);

}