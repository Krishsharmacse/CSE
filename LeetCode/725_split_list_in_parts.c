#include<stdio.h>
#include<stdlib.h>

/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.
*/




struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode** res = (struct ListNode**)calloc(k, sizeof(struct ListNode*));

    int length = 0;
    struct ListNode* temp = head, *prev = NULL;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    int partSize = length/k, rem = length % k;
    temp = head;
    for(int i=0; temp != NULL && i < k; i++){
        res[i] = temp;

        int size = (rem>0) ? partSize+1: partSize;
        for(int j= 0; j < size;j++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        rem--;
    }   

    *returnSize = k;
    return res;

}