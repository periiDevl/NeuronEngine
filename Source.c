#include <stdio.h>
#include <stdbool.h>
#include "Neuron.h"
#include "Layer.h"
#include"NeuralNetwork.h"
#include"Backpropagation.h"
#include"TerminalGraph.h"
#include <stdlib.h>
#include <time.h>


double randomDouble(double min, double max) {
    return ((double)rand() / RAND_MAX) * (max - min) + min;
}
int main() {
    srand(time(NULL));
    
    NeuralNetwork network;
    createNeuralNetwork(&network, 3);
    linkLayers(&network);
    setNeuronsSize(&network.layers[0], 2);  // Input layer: 2 neurons
    setNeuronsSize(&network.layers[1], 2);  // Hidden layer: 2 neurons  
    setNeuronsSize(&network.layers[2], 1);  // Output layer: 1 neuron
    setLayersParam(&network);
    double max = 3;
    network.layers[0].neurons[0].val = 5;
    network.layers[0].neurons[1].val = 10; 

    network.layers[0].neurons[0].weights[0] = randomDouble(-max, max); 
    network.layers[0].neurons[0].weights[1] = randomDouble(-max, max);
    network.layers[0].neurons[1].weights[0] = randomDouble(-max, max);
    network.layers[0].neurons[1].weights[1] = randomDouble(-max, max); 

    network.layers[1].neurons[0].weights[0] = randomDouble(-max, max); 
    network.layers[1].neurons[1].weights[0] = randomDouble(-max, max);

    network.layers[0].neurons[0].bias = randomDouble(-max, max);
    network.layers[0].neurons[1].bias = randomDouble(-max, max);
    network.layers[1].neurons[0].bias = randomDouble(-max, max);
    network.layers[1].neurons[1].bias = randomDouble(-max, max);
    network.layers[2].neurons[0].bias = randomDouble(-max, max);

    network.layers[1].neurons[0].val = 0.0;
    network.layers[1].neurons[1].val = 0.0;
    network.layers[2].neurons[0].val = 0.0;

    forwardPass(&network);
    activate(&network.layers[2].neurons[0]);
    printf("N1 = %f", network.layers[2].neurons[0].val);
    computeAllNetworkGradients(&network);
    //printf("w1 gradient contribution = %f\n", followWeightPath(&network,1,0,0));
    printf("w1 gradient contribution 2 = %f\n", network.layers[0].neurons[0].weightsGradients[0]);

    TerminalGraph terminalGraph;
    createTerminalGraph(&terminalGraph, 40);
    for (size_t epoch = 0; epoch < 1; epoch++)
    {
    
        network.layers[0].neurons[0].weights[0] = randomDouble(-max, max);
        network.layers[0].neurons[0].weights[1] = randomDouble(-max, max);
        network.layers[0].neurons[1].weights[0] = randomDouble(-max, max);
        network.layers[0].neurons[1].weights[1] = randomDouble(-max, max);
        network.layers[1].neurons[0].weights[0] = randomDouble(-max, max);
        network.layers[1].neurons[1].weights[0] = randomDouble(-max, max);
        
        network.layers[1].neurons[0].bias = randomDouble(-max, max);
        network.layers[1].neurons[1].bias = randomDouble(-max, max);
        network.layers[2].neurons[0].bias = randomDouble(-max, max);
        
        for (int i = 0; i < terminalGraph.graphSize; i++) {
            for (int j = 0; j < terminalGraph.graphSize; j++) {
                resetNeuralNetwork(&network);
                
                network.layers[0].neurons[0].val = i;
                network.layers[0].neurons[1].val = j; 
                forwardPass(&network);
                activate(&network.layers[2].neurons[0]);

                if (network.layers[2].neurons[0].val > 0.7) {
                    terminalGraph.Gmatrix[i][j] = 1;
                } else {
                    terminalGraph.Gmatrix[i][j] = 0;
                }
            }
        }
        drawTerminalGraph(&terminalGraph);
        printf("Eopch %d",epoch);
    }

    destroyTerminalGraph(&terminalGraph);
    freeNetwork(&network);
}