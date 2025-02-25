#include<stdio.h>
#include<stdlib.h>

bool isPalindrome(struct ListNode* head) {
    int arr[100000];
    int top = -1;
    struct ListNode* temp = head; 
    while(temp != NULL){
        arr[++top] = temp->val;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(arr[top--] != temp->val) return false;
        temp = temp->next;
    }

    return true;

}