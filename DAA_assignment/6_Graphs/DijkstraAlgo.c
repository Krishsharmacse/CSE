#include<stdio.h>
#include<stdlib.h>
#include <limits.h>


typedef struct{
    int V;
    int **adjMatrix;
} Graph;

typedef struct{
    int v;
    int d;
    int pi;
}Vertex;

typedef struct{
    Vertex *items;
    int capacity;
    int size;
}PriorityQ;


void swap(Vertex *a, Vertex *b, int *pos){
    int tempPos = pos[a->v];
    pos[a->v] = pos[b->v];
    pos[b->v] = tempPos;

    Vertex temp = *a;
    *a = *b;
    *b = temp;    
}

void Heapify(Vertex *arr, int size, int i, int *pos){
    int L = 2*i + 1;
    int R = 2*i + 2;

    int min = i;
    if(L < size && arr[min].d > arr[L].d) min = L;
    if(R < size && arr[min].d > arr[R].d) min = R;

    if(min != i){
        swap(&arr[i], &arr[min], pos);
        Heapify(arr, size, min, pos);
    }
    
}


PriorityQ *initQueue(int capacity){
    PriorityQ *Queue = (PriorityQ*)malloc(sizeof(PriorityQ));
    Queue->items = (Vertex*)calloc(capacity , sizeof(Vertex));
    Queue->size = 0;
    Queue->capacity = capacity;
    return Queue;
}

void EnQ(PriorityQ *Q, Vertex val, int *pos){
    if(Q->size == Q->capacity){
        printf("Queue is full");
        return;
    }

    int i = Q->size;
    Q->items[i] = val;
    pos[val.v] = i;
    Q->size++;

    while(i != 0 && Q->items[(i - 1) / 2].d > Q->items[i].d){
        swap(&Q->items[i], &Q->items[(i - 1) / 2], pos);
        i = (i - 1) / 2;
    }

}

Vertex ExtractMin(PriorityQ *Q, int *pos){
    if(Q->size == 0){
        printf("Queue is Empty");
        return (Vertex){-1,-1,-1};
    }

    Vertex val = Q->items[0];
    Q->items[0] = Q->items[Q->size - 1];
    pos[Q->items[0].v] = 0;
    Q->size--;
    Heapify(Q->items, Q->size, 0, pos);
    return val;
}


int isEmpty(PriorityQ *Q){
    return Q->size == 0;
}

void decreaseKey(PriorityQ *Q, int vertex, int newDist, int newPi, int *pos) {
    int i = pos[vertex];
    Q->items[i].d = newDist;
    Q->items[i].pi = newPi;

    while (i != 0 && Q->items[(i - 1) / 2].d > Q->items[i].d) {
        swap(&Q->items[i], &Q->items[(i - 1) / 2], pos);
        i = (i - 1) / 2;
    }
}


void printQueue(PriorityQ *Q){
    printf("Queue (Min-Heap): ");
    for(int i = 0; i < Q->size; i++){
        printf("%d(%d)  ", Q->items[i].v, Q->items[i].d);
    }
    printf("\n");
}





Graph *initGraph(int V){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjMatrix = (int **)malloc(V * sizeof(int*));
    for(int i = 0; i< V; i++)
        graph->adjMatrix[i] = (int *)calloc(V, sizeof(int*));

    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight){
    graph->adjMatrix[src][dest] = weight;
    // graph->adjMatrix[dest][src] = weight;
}


void Dijkstra(Graph *graph, int src, Vertex Sol[]){
    int visited[graph->V];
    int *pos = (int *)malloc(sizeof(int) * graph->V);
    for (int i = 0; i < graph->V; i++) visited[i] = 0;

    PriorityQ *Q = initQueue(graph->V);
    for(int i=0; i<graph->V; i++){
        if(i == src) EnQ(Q, (Vertex){i , 0, -1}, pos);
        else EnQ(Q, (Vertex){i , INT_MAX, -1}, pos);   
    }

    while(!isEmpty(Q)){
        Vertex vertex = ExtractMin(Q, pos);
        visited[vertex.v] = 1;
        Sol[vertex.v] = vertex; 
        for(int i = 0; i<graph->V; i++){
            if(graph->adjMatrix[vertex.v][i] != 0 && !visited[i]){
                int j = pos[i];
                int newDist = vertex.d + graph->adjMatrix[vertex.v][i];
                if( Q->items[j].d > newDist ){
                    decreaseKey(Q, i, newDist, vertex.v, pos);
                }
            }
        }
    }

    free(pos);
    free(Q->items);
    free(Q);

}



void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%02d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}




int main(){
    int n= 6;
    Graph* graph = initGraph(n);
    addEdge(graph, 0, 1, 50);
    addEdge(graph, 0, 2, 45);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 1, 3, 45);
    addEdge(graph, 2, 4, 30);
    addEdge(graph, 3, 0, 10);
    addEdge(graph, 3, 4, 15);
    addEdge(graph, 4, 1, 20);
    addEdge(graph, 4, 2, 35);
    addEdge(graph, 5, 5, 3);

    printf("Input: \n");
    printGraph(graph);

    Vertex Sol[n];
    Dijkstra(graph, 0, Sol);

    for(int i = 1; i<n; i++){
        if(Sol[i].pi == -1) continue;
        printf("src(%d) ", Sol[0].v);
        printf("--> dest(%d) cost= %d \n", Sol[i].v, Sol[i].d);
    }
}