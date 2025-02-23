#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;
} Node;


typedef struct MyLinkedList{
    Node *head;
    Node *tail;
    int Size;
} MyLinkedList;


void printList(Node *temp) {
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}



MyLinkedList* myLinkedListCreate() {
    MyLinkedList *List = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    List->head = NULL;
    List->tail = NULL;
    List->Size = 0;
    return List;
}


int myLinkedListGet(MyLinkedList* obj, int index) {
    if(obj == NULL) return -1;
    if(obj->head == NULL) return -1;
    if(index < 0) return -1;
    if(obj->Size == 0) return -1;
    if (index >= obj->Size) return -1;



    int i = 0;
    Node *temp = obj->head;
    while( temp != NULL && i<index){
        temp = temp->next;
        i++;
    }


    return (temp == NULL)? -1 : temp->val;
}


void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if(obj == NULL) return;
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if(obj->head == NULL){
        obj->head = node;
        obj->tail = node;
    }else{
        node->next = obj->head;
        obj->head = node;
    }

    obj->Size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

    if(obj == NULL) return;

    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if(obj->head == NULL){
        obj->head = node;
        obj->tail = node;
    }else{
        obj->tail->next = node;
        obj->tail = node;
    }

    obj->Size++;

}


void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(obj == NULL) return;
    if(index < 0) return;
    if (index > obj->Size) return;
    if(index == 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->Size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }

    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;


    int i=0;
    Node *temp = obj->head;
    while(temp != NULL && i < index-1) {
        temp = temp->next;
        i++;
    }


    if (temp == NULL){
        free(node);
        return;
    }

    node->next = temp->next;
    temp->next = node;
    obj->Size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0) return;
    if(obj == NULL) return;
    if(obj->head == NULL) return;
    if(obj->Size == 0) return;
    if(index >= obj->Size) return;

    if (index == 0) {
        Node *tmpHead = obj->head;
        obj->head = obj->head->next;
        free(tmpHead);
        obj->Size--;
        if(obj->Size == 0) obj->tail = NULL;
        return;
    }


    int i = 0;
    Node *prev = NULL, *cur = obj->head;
    while(cur != NULL && i<index){
        prev = cur;
        cur = cur->next;
        i++;
    }
    if(cur == NULL) return;

    if (index == obj->Size - 1) { 
        obj->tail = prev;
    }else{
        prev->next = cur->next;
    }

    free(cur); 
    obj->Size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if(obj == NULL) return;
    while(obj->head != NULL){
        Node *temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    obj->head = NULL;
    obj->tail = NULL;
    obj->Size = 0;
    free(obj);
}




int main() {
    // Initialize the linked list
    MyLinkedList* myList = myLinkedListCreate();
    
    // Perform operations
    myLinkedListAddAtHead(myList, 2);       // ["addAtHead", [2]]
    myLinkedListDeleteAtIndex(myList, 1);   // ["deleteAtIndex", [1]]
    myLinkedListAddAtHead(myList, 2);       // ["addAtHead", [2]]
    myLinkedListAddAtHead(myList, 7);       // ["addAtHead", [7]]
    myLinkedListAddAtHead(myList, 3);       // ["addAtHead", [3]]
    myLinkedListAddAtHead(myList, 2);       // ["addAtHead", [2]]
    myLinkedListAddAtHead(myList, 5);       // ["addAtHead", [5]]
    myLinkedListAddAtTail(myList, 5);       // ["addAtTail", [5]]

    int val = myLinkedListGet(myList, 5);   // ["get", [5]]
    printf("Value at index 5: %d\n", val);  // Print the result

    myLinkedListDeleteAtIndex(myList, 6);   // ["deleteAtIndex", [6]]
    myLinkedListDeleteAtIndex(myList, 4);   // ["deleteAtIndex", [4]]

    // Free memory
    myLinkedListFree(myList);

    return 0;
}