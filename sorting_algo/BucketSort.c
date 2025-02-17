#include<stdio.h>
#include<stdlib.h>

typedef struct Bucket{
    float val;
    struct Bucket *next;
} Bucket;


float getMin(float *Arr, int size);
float getMax(float *Arr, int size);
void printArray(float arr[], int size);

Bucket *createNode(float val);
void InsertInBucket(Bucket** head, float val);
void BucketSort(float *Arr, int size);


void printArray(float arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}



float getMax(float *Arr, int size){
    float max = Arr[0];
    for(int i=0; i<size; i++){
        if(max < Arr[i]) max = Arr[i];
    }
    return max;
}

float getMin(float *Arr, int size){
    float min = Arr[0];
    for(int i=0; i<size; i++){
        if(min > Arr[i]) min = Arr[i];
    }
    return min;
}


Bucket *createNode(float val){
    Bucket *node = (Bucket*)malloc(sizeof(Bucket));
    node->val = val;
    node->next = NULL;

    return node;
}

void InsertInBucket(Bucket** head, float val){
    Bucket *node = createNode(val);

    if((*head) == NULL || (*head)->val >= val){
        node->next = *head;
        *head = node;
        return;
    }

    Bucket *cur = *head;
    while(cur->next != NULL && cur->next->val < val){
        cur = cur->next;
    }

    node->next = cur->next;
    cur->next = node;

}


void BucketSort(float *Arr, int size){
    Bucket **buckets = (Bucket**)calloc(size, sizeof(Bucket*));

    float min = getMin(Arr, size);
    float max = getMax(Arr, size);

    for(int i=0; i<size; i++){
        int index = (int)((Arr[i] - min) / (max - min) * (size - 1));
        InsertInBucket(&buckets[index], Arr[i]);
    } 
    
    int j = 0;
    for(int i=0; i<size; i++){
        Bucket *temp = buckets[i];
        while(temp != NULL && j < size){
            Arr[j++] = temp->val; 
            Bucket *node = temp;
            temp = temp->next;
            free(node);
        }
    }

    free(buckets);
}





int main(){
    float Arr[] = {42.5, -12.3, 0.6, 8.4, -30.2, 19.8, 15.3, 22.7};
    int size = sizeof(Arr) / sizeof(Arr[0]); 

    BucketSort(Arr, size);

    printArray(Arr, size);
}