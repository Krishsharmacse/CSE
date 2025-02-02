#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000000

typedef struct Block {
    int key;
    int val;
    struct Block* next;
} Block;

Block* hashTable[TABLE_SIZE] = {NULL};

// Hash function using multiplicative method
int hashFunction(int key) {
    double fraction = key * 0.6180339887;
    fraction = fraction - (long long)fraction;  // Extract fractional part
    return (int)(TABLE_SIZE * fraction);
}

// Create a new Block
Block* createBlock(int key, int val) {
    Block* node = (Block*)malloc(sizeof(Block));
    node->key = key;
    node->val = val;
    node->next = NULL;
    return node;
}

// Insert key-value pair into hash table
void put(int key, int val) {
    int index = hashFunction(key);
    Block* node = createBlock(key, val);
    node->next = hashTable[index];
    hashTable[index] = node;
}

// Search for the value by key in the hash table
int search(int key) {
    int index = hashFunction(key);
    Block* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return temp->val;  // Return the value associated with the key
        }
        temp = temp->next;
    }
    return -1;  // Key not found
}

int main() {
    // Test the hash table
    put(1, 100);
    put(2, 200);
    put(3, 300);

    // Search for keys
    printf("Value for key 1: %d\n", search(1)); 
    printf("Value for key 2: %d\n", search(2)); 
    printf("Value for key 3: %d\n", search(3)); 
    printf("Value for key 4: %d\n", search(4)); 

    return 0;
}
