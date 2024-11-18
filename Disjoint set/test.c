#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data, rank;
    struct Node *parent;
} Node;

Node* makeSet(int val);
Node* find(Node *node);
void Union(Node *x, Node *y);
// void printSet(Node *node);
void printSet(Node **nodes, int size);

int main(){

    Node *s1 = makeSet(4);
    Node *s2 = makeSet(3);
    Node *s3 = makeSet(6);
    Node *s4 = makeSet(10);
    Node *s5 = makeSet(1);
    Node *s6 = makeSet(22);
    
    Union(s1, s2);
    Union(s2, s3);
    Union(s3, s4);
    Union(s5, s6);

    Node *nodes[] = {s1, s2, s3, s4, s5, s6};
    int size = sizeof(nodes) / sizeof(nodes[0]);

    printSet(nodes, size);

    // printSet(s1);
    // printSet(s2);
    // printSet(s3);
    // printSet(s5);



    return 0;
}


Node* makeSet(int val){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->parent = node;
    node->rank = 0;

    return node;
}

Node* find(Node *node){
    if (node->parent != node) {
        node->parent = find(node->parent); 
    }
    return node->parent;
}

void Union(Node *x, Node *y){
    Node *xHead = find(x);
    Node *yHead = find(y);

    if(xHead == yHead){
        return;
    }

    if(xHead->rank > yHead->rank){
        yHead->parent = xHead;
    }else if(xHead->rank < yHead->rank){
        xHead->parent = yHead;
    }else{
        yHead->parent = xHead;
        xHead->rank++;
    }

}   


// void printSet(Node *node){
//     Node* head = find(node);
//     printf("Element: %d RE: %d: \n", node->data, head->data);   
// }

void printSet(Node **nodes, int size) {
    printf("Sets:\n");
    for (int i = 0; i < size; i++) {
        Node *rep = find(nodes[i]); // Find the representative of the set
        printf("Element: %d, Representative: %d\n", nodes[i]->data, rep->data);
    }

    printf("\nGrouped Sets:\n");
    for (int i = 0; i < size; i++) {
        Node *rep = find(nodes[i]);
        printf("Set with Representative %d: ", rep->data);
        for (int j = 0; j < size; j++) {
            if (find(nodes[j]) == rep) {
                printf("%d ", nodes[j]->data);
            }
        }
        printf("\n");
    }
}





