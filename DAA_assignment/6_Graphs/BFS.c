#include<stdio.h>
#include<stdlib.h>

#define MAX 100


typedef struct{
    int *items;
    int size;
    int front, end;
}Queue;


Queue *initQueue(int size){
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    Q->size = size;
    Q->items = (int *)calloc(size, sizeof(int));
    Q->front = Q->end = -1;
    return Q;
}


void EnQ(Queue *Q, int val){
    if((Q->end+1)%Q->size == Q->front){
        printf("Queue is full");
        return;
    }

    if(Q->front == -1) Q->front = 0;

    Q->end = (Q->end+1)%Q->size;
    Q->items[Q->end] = val; 
}

int DeQ(Queue *Q){
    if(Q->front == -1){
        printf("Queue is empty");
        return -1;
    }

    int val = Q->items[Q->front];

    if(Q->front == Q->end) Q->front = Q->end = -1;
    else Q->front = (Q->front+1)%Q->size;

    return val;
}

int isEmpty(Queue *Q){
    if(Q->front == -1) return 1;
    return 0;
}


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


void BFS(Graph *graph, int startingVertex, int PiMatrix[8][8]){
    Queue *Q = initQueue(graph->V);
    
    EnQ(Q, startingVertex);

    while(!isEmpty(Q)){
        int v = DeQ(Q);
        printf("%d ", v);
        graph->visited[v] = 1;
        for(int i = 0; i<graph->V; i++){
            if(graph->adjMatrix[v][i] && !graph->visited[i]){
                graph->visited[i] = 1;
                PiMatrix[v][i] = v;
                EnQ(Q, i);
            }
        }
    }
}


void printPiMatrix(int PiMatrix[8][8], int V) {
    printf("\n\nBFS tree: \n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (PiMatrix[i][j] != -1) {
                printf("%c --> %c\n", 65+PiMatrix[i][j], 65+j);
            }
        }
    }
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

    printf("Input\n");
    printGraph(graph);
    
    int PiMatrix[8][8];
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            PiMatrix[i][j] = -1;
        }
    }
    
    printf("BFS Sequence: ");
    BFS(graph, 0, PiMatrix);
    
    printPiMatrix(PiMatrix, 0);


    return 0;

}