#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int parent;
    int rank;
} Node;

Node *InitSet(int V){
    Node *set = (Node*)calloc(V, sizeof(Node));
    for(int i = 0; i < V; i++){
        set[i].parent = i;
        set[i].rank = 0;
    }
    return set;
}

int find(Node *set, int v){
    if(set[v].parent != v) set[v].parent = find(set, set[v].parent);
    return set[v].parent;
}

void Union(Node*set, int x, int y){
    int rootX = find(set, x);
    int rootY = find(set, y);

    if (rootX == rootY) return; 

    if(set[rootX].rank > set[rootY].rank){
        set[rootY].parent = rootX;
    }else if(set[rootX].rank < set[rootY].rank){
        set[rootX].parent = rootY;
    }else{
        set[rootY].parent = rootX;
        set[rootX].rank++;
    }
}

int main() {
    int V = 5;
    Node *set = InitSet(V);

    Union(set, 0, 1);
    Union(set, 1, 2);
    Union(set, 3, 4);

    printf("Find(2): %d\n", find(set, 2)); 
    printf("Find(4): %d\n", find(set, 4)); 

    Union(set, 2, 3);

    printf("Find(4) after merging: %d\n", find(set, 4));

    free(set);
    return 0;
}