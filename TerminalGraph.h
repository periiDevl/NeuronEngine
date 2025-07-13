#ifndef H_TERM_GRAPH
#define H_TERM_GRAPH
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

typedef struct TerminalGraph
{
    int** Gmatrix;
    int graphSize;
}TerminalGraph;
void createTerminalGraph(TerminalGraph* termGraph,int size);
void drawTerminalGraph(TerminalGraph* termGraph);
void destroyTerminalGraph(TerminalGraph* termGraph);
void calculateCostTerminalGraph(TerminalGraph* termGraph);
#endif