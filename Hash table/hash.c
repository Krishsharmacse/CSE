#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 100

typedef struct Block{
    int key;
    int val;
    struct Block* next;
} Block;

Block* hashTable[size] = {NULL};

int Hash(int val){
    int hash = (val * 9973) % size;
    return hash;
}

Block *createBlock(int key, int val){
    Block *node = (Block*)malloc(sizeof(Block));
    node->key = key;
    node->val = val;
    node->next = NULL;

    return node;
}

void put(int key, int val){
    int index = Hash(key);
    Block *node = createBlock(key, val);
    node->next = hashTable[index];
    hashTable[index] = node;
}

int get(int key){
    int index = Hash(key);
    Block *temp = hashTable[index];

    while(temp != NULL){
        if(temp->key == key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1; 
}

void delete(int key){
    int index = Hash(key);
    Block *node = hashTable[index], *prev = NULL;

    if (node != NULL && node->key == key) {
        hashTable[index] = node->next; 
        free(node);
        return;
    }

    while(node != NULL && node->key != key){
        node = node->next;
    }

    if(node == NULL){
        printf("not found\n");
        return;
    }

    prev->next = node->next;
    free(node);
}

void printTable(){
    printf("Key   Value\n");
    for(int i = 0; i < size; i++){
        if(hashTable[i] != NULL){
            Block *temp = hashTable[i];
            while(temp != NULL){
                printf("%02d  :  %02d\n", temp->key, temp->val);
                temp = temp->next;
            }
        }
    }
    printf("\n\n");
}

int main(){
    put(1,20);
    put(10,25);
    put(5,2);
    put(105,3);
    put(16,29);
    put(20,44);

    printTable();

    int key = 10;
    printf("value of key %d -> ", key);
    printf("%d\n\n", get(key));

    delete(key);
    printTable();

    return 0;
}