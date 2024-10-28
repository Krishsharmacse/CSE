#include<stdio.h>
#include<stdlib.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
} List;


void Insert(List **head, int value){
    List *node =  (List*)malloc(sizeof(List));
    node->val = value;
    node->next = NULL;
    if(*head == NULL){
        *head = node;
        return;
    } 

    List *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = node;
    return; 

}


List* mergeTwoLists(List* list1, List* list2) {
    List* Result = NULL;
    List* l1 = list1, *l2 = list2;

    while(l1 != NULL && l2 != NULL){      
        if(l1->val < l2->val){
            Insert(&Result, l1->val);            
            l1 = l1->next;
        }else if(l1->val > l2->val){
            Insert(&Result, l2->val);            
            l2 = l2->next;
        }else{
            Insert(&Result, l1->val);
            Insert(&Result, l2->val);
            l1 = l1->next;            
            l2 = l2->next;
        }
    }

    while(l1 != NULL){
        Insert(&Result, l1->val);            
        l1 = l1->next;
    }

    while(l2 != NULL){
        Insert(&Result, l2->val);            
        l2 = l2->next;
    }

    return Result;
}