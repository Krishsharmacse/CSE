#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int V;
    int **adjMatrix;
} Graph;

typedef struct {
    int v;
    int d;
    int pi;
} Vertex;

Graph *initGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph->adjMatrix[i] = (int *)calloc(V, sizeof(int));
    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    graph->adjMatrix[src][dest] = weight;
    // graph->adjMatrix[dest][src] = weight;
}

int BellmanFord(Graph *graph, int src, Vertex Sol[]) {
    int V = graph->V;

    for (int i = 0; i < V; i++) {
        Sol[i].v = i;
        Sol[i].d = (i == src) ? 0 : INT_MAX;
        Sol[i].pi = -1;
    }

    for (int i = 1; i <= V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph->adjMatrix[u][v] != 0 && Sol[u].d != INT_MAX) {
                    int weight = graph->adjMatrix[u][v];
                    if (Sol[v].d > Sol[u].d + weight) {
                        Sol[v].d = Sol[u].d + weight;
                        Sol[v].pi = u;
                    }
                }
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph->adjMatrix[u][v] != 0 && Sol[u].d != INT_MAX) {
                int weight = graph->adjMatrix[u][v];
                if (Sol[u].d + weight < Sol[v].d) {
                    return 0;  // Negative cycle
                }
            }
        }
    }

    return 1; // No negative cycle
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d ", i);
        for (int j = 0; j < graph->V; j++) {
                printf("%02d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n = 5;
    Graph *graph = initGraph(n);

    addEdge(graph, 0, 1, -1);
    addEdge(graph, 0, 2, 4);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 2);
    addEdge(graph, 3, 2, 5);
    addEdge(graph, 3, 1, 1);
    addEdge(graph, 4, 3, -3);

    printGraph(graph);

    Vertex Sol[n];
    int success = BellmanFord(graph, 0, Sol);

    if (success) {
        for (int i = 1; i < n; i++) {
            if (Sol[i].pi == -1) continue;
            printf("src(%d) --> dest(%d) cost= %d\n", Sol[0].v, Sol[i].v, Sol[i].d);
        }
    } else {
        printf("Graph contains negative weight cycle.\n");
    }

    for (int i = 0; i < n; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);



    return 0;
}
