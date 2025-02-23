#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct {
    int Vertices;
    Node **adjList;
    int *visited;
} Graph;

Graph *CreateGraph(int vertices);
Node *CreateVertex(int val);
void addEdge(Graph** graph, int src, int dest);
void DFS(Graph* graph, int vertex);
void printGraph(Graph *graph);

int DFSCycleetection(Graph *graph, int vertex);
void detectCycle(Graph *graph);

int main() {
    Graph *graph = CreateGraph(7);

    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 4, 2);
    addEdge(&graph, 4, 5);
    addEdge(&graph, 5, 6);
    addEdge(&graph, 6, 3);


    // printGraph(graph);

    // DFS(graph, 1);

    detectCycle(graph);

    return 0;
}

Graph *CreateGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->Vertices = vertices;

    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

Node *CreateVertex(int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->vertex = val;
    node->next = NULL;

    return node;
}

void addEdge(Graph** graph, int src, int dest) {
    // Add edge from src to dest
    Node *destNode = CreateVertex(dest);
    destNode->next = (*graph)->adjList[src];
    (*graph)->adjList[src] = destNode;

    /*
    Node *srcNode = CreateVertex(src);
    srcNode->next = (*graph)->adjList[dest];
    (*graph)->adjList[dest] = srcNode;
    */
}

void DFS(Graph* graph, int vertex){
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int DFSCycleetection(Graph *graph, int vertex){
    graph->visited[vertex] = 1;

    Node *AjdNode = graph->adjList[vertex];
    while(AjdNode != NULL){
        int vertex = AjdNode->vertex;
        if(graph->visited[vertex] == 1) return 1;        
        
        if(DFSCycleetection(graph, vertex)) return 1;

        AjdNode = AjdNode->next;

    }
}

void detectCycle(Graph *graph) {
    for (int i = 0; i < graph->Vertices; i++) {
        graph->visited[i] = 0;
    }

    for (int i = 0; i < graph->Vertices; i++) {
        if (graph->visited[i] == 0) { 
            if (DFSCycleetection(graph, i)) {
                printf("Cycle Detected");
                return; 
            }
        }
    }
    printf("No Cycle Found");
}


void printGraph(Graph *graph) {
    for (int i = 0; i < graph->Vertices; i++) {
        Node *temp = graph->adjList[i];
        printf("%d:", i);
        while (temp != NULL) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}
