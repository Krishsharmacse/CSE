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
    graph->visited = (int *)calloc(V, sizeof(int*));
    graph->adjMatrix = (int **)malloc(V * sizeof(int*));
    for(int i = 0; i< V; i++)
        graph->adjMatrix[i] = (int *)calloc(V, sizeof(int*));

    return graph;
}

void addEdge(Graph *graph, int src, int dest){
    graph->adjMatrix[src][dest] = 1;
}


void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d ", i);
        for (int j = 0; j < graph->V; j++) {
            if(graph->adjMatrix[i][j]){
                printf("--> %d ", j);
            }
        }
        printf("\n");
    }
    printf("\n");
}




int t = 0;
void DFS(Graph *graph, int startingVertex, int Stime[], int Ftime[]){
    int v = startingVertex;
    graph->visited[v] = 1;
    Stime[v] = ++t;

    printf("%c  ", 65+v);

    for(int i = 0; i<graph->V; i++){
        if(graph->adjMatrix[v][i] && !graph->visited[i]){
            DFS(graph, i, Stime, Ftime);
        }
    }

    Ftime[v] = ++t;
}




int main(){
    
    Graph* graph = initGraph(8);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 6);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 7);
    addEdge(graph, 6, 5);
    addEdge(graph, 7, 5);
    addEdge(graph, 7, 6);

    printf("Input");
    printGraph(graph);

    int Stime[8] = {0};
    int Ftime[8] = {0};
    printf("DFS Sequence: ");
    DFS(graph, 0, Stime, Ftime);


    printf("\n\n");
    for(int i = 0; i<8; i++){
        printf("%c (start = %02d, Finish = %02d)\n",65+i, Stime[i], Ftime[i]);
    }


    return 0;

}