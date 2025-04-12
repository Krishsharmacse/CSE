#include <stdio.h>
#define MAX 100

int parent[MAX];
int rank[MAX];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return;

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int countDisjointSets(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i)
            count++;
    }
    return count;
}

void printDisjointSets(int n) {
    int sets[MAX][MAX];     
    int size[MAX] = {0};

    for (int i = 0; i < n; i++) {
        int root = find(i);
        sets[root][size[root]++] = i;
    }

    printf("Disjoint Sets:\n");
    for (int i = 0; i < n; i++) {
        if (size[i] > 0) {
            printf("{ ");
            for (int j = 0; j < size[i]; j++) {
                printf("%d ", sets[i][j]);
            }
            printf("}\n");
        }
    }
}

int main() {
    int n = 7; 

    makeSet(n);

    unionSets(0, 1);
    unionSets(1, 2);
    unionSets(3, 4);
    unionSets(5, 6);

    printf("no. of disjoint sets: %d\n", countDisjointSets(n));
    printDisjointSets(n);

    return 0;
}
