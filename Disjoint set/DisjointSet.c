#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* head;
} Node;


Node* makeSet(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->head = node;
    return node;
}


Node* findSet(Node* node) {
    return node->head;
}


void unionSets(Node* x, Node* y) {
    Node* headX = findSet(x);
    Node* headY = findSet(y);

    if (headX == headY) {
        return;
    }

    Node* temp = headX;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = headY;

    Node* current = headY;
    while (current != NULL) {
        current->head = headX;
        current = current->next;
    }
}


void printSet(Node* node) {
    Node* head = findSet(node);
    printf("Set containing %d: ", node->data);
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* node1 = makeSet(1);
    Node* node2 = makeSet(2);
    Node* node3 = makeSet(3);
    Node* node4 = makeSet(4);
    Node* node5 = makeSet(5);
    Node* node6 = makeSet(6);

    unionSets(node1, node2);
    unionSets(node2, node3);
    unionSets(node3, node4);
    unionSets(node5, node6);

    printSet(node1);
    printSet(node5);

    return 0;
}
