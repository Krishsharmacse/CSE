#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    int V;
    int **adjMatrix;
    int *visited;
} Graph;

Graph *initGraph(int V){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->visited = (int *)calloc(V, sizeof(int));
    graph->adjMatrix = (int **)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++)
        graph->adjMatrix[i] = (int *)calloc(V, sizeof(int));
    return graph;
}
void addEdge(Graph *graph, int src, int dest){
    graph->adjMatrix[src][dest] = 1;
}
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d ", i);
        for (int j = 0; j < graph->V; j++)
            if(graph->adjMatrix[i][j]) printf("--> %d ", j);
        printf("\n");
    }
    printf("\n");
}

int t = 0;
void DFS(Graph *graph, int startingVertex, int Stime[], int Ftime[], int stack[]){
    int v = startingVertex;
    graph->visited[v] = 1;
    Stime[v] = ++t;
    for(int i = 0; i < graph->V; i++){
        if(graph->adjMatrix[v][i] && !graph->visited[i]){
            DFS(graph, i, Stime, Ftime, stack);
        }
    }

    Ftime[v] = ++t;
    stack[t] = v;
}

void topologicalSort(Graph* graph) {
    int Stime[graph->V];
    int Ftime[graph->V];
    int stack[MAX];

    for(int i = 0; i < graph->V; i++) {
        graph->visited[i] = 0;
        Stime[i] = 0;
        Ftime[i] = 0;
    }

    for(int i = 0; i < graph->V; i++) {
        if(!graph->visited[i]) {
            DFS(graph, i, Stime, Ftime, stack);
        }
    }

    printf("Topological Sort: ");
    for(int i = graph->V-1; i >= 0; i--) {
        printf("%c ", 65 + stack[i]);
    }
    printf("\n");
}

int main() {
    Graph* graph = initGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    printf("Input Graph:\n");
    printGraph(graph);
    topologicalSort(graph);

    return 0;
}
