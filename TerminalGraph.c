#include"TerminalGraph.h"
#define ANSI_COLOR_RED_BACKGROUND    "\033[41m"
#define ANSI_COLOR_BLUE_BACKGROUND   "\033[44m"
#define ANSI_COLOR_RESET             "\033[0m"
void createTerminalGraph(TerminalGraph* termGraph, int size) {
    termGraph->graphSize = size;
    termGraph->Gmatrix = (int**)malloc(size * sizeof(int*));
    if (termGraph->Gmatrix == NULL) {
        perror("Failed to allocate memory for graph rows"); 
        exit(EXIT_FAILURE); 
    }

    for (int i = 0; i < size; i++) {
        termGraph->Gmatrix[i] = (int*)malloc(size * sizeof(int));
        if (termGraph->Gmatrix[i] == NULL) {
            perror("Failed to allocate memory for graph columns");
            for (int k = 0; k < i; k++) {
                free(termGraph->Gmatrix[k]);
            }
            free(termGraph->Gmatrix); 
            exit(EXIT_FAILURE);
        }
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            termGraph->Gmatrix[i][j] = rand() % 2; 
        }
    }
}
void drawTerminalGraph(TerminalGraph* termGraph)
{
    for (int i = 0; i < termGraph->graphSize; i++) {
        for (int j = 0; j < termGraph->graphSize; j++) {
            if (termGraph->Gmatrix[i][j] == 1) {
                printf("%s  ", ANSI_COLOR_BLUE_BACKGROUND); 
            } else {
                printf("%s  ", ANSI_COLOR_RED_BACKGROUND);
            }
        }
        printf("%s\n", ANSI_COLOR_RESET);
    }
}
void destroyTerminalGraph(TerminalGraph* termGraph) {
    if (termGraph != NULL && termGraph->Gmatrix != NULL) {
        for (int i = 0; i < termGraph->graphSize; i++) {
            free(termGraph->Gmatrix[i]);
        }
        free(termGraph->Gmatrix);
        termGraph->Gmatrix = NULL;
        termGraph->graphSize = 0;
    }
}