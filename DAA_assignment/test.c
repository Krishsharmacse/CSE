#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX  
void printSolution(int **dist, int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            dist[i][j] == INF ? printf("%7s", "INF") : printf("%7d", dist[i][j]);
        printf("\n");
    }
}
void floydWarshall(int **adjMatrix, int V) {
    printf("\n\t\t Input \t\t\n");
    printf("--------------------------------------------\n");
    printSolution(adjMatrix, V);
    printf("--------------------------------------------\n");
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][k] != INF && adjMatrix[k][j] != INF && adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
            }
        }
    }
    printf("\n All Pair Shortest path\n");
    printf("---------------------------------------------------\n");
    printSolution(adjMatrix, V);
    printf("---------------------------------------------------\n\n");
}
int main() {
    int V = 5;
    int inputGraph[5][5] = {
        {0,   2,   10,  11,  INF},
        {INF, 0,   3,   INF, INF},
        {6,   INF, 0,   INF, 5},
        {INF, INF, 2,   0,   18},
        {7,   INF, INF, INF, 0},
    };
    int **adjMatrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++){
        adjMatrix[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            adjMatrix[i][j] = inputGraph[i][j];
    }   
    floydWarshall(adjMatrix, V);
    return 0;
}

