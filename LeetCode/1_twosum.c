#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};


  
void insert(struct ListNode **head, int val){
    struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;

    if(*head == NULL){
        
        *head = n;
        return;
    }

    struct ListNode *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* res = NULL;
    int carry = 0;
    while(l1 != NULL && l2 != NULL){
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode*));
        
        int val = carry + l1->val + l2->val;
        carry = val / 10;
        val = val % 10;
        printf("c %d, v %d\n", carry, val);

        insert(&res, val);
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 != NULL){
        int val = carry + l1->val;
        carry = val / 10;
        val = val % 10;
        insert(&res, val);
        l1 = l1->next;
    }
    
    while(l2 != NULL){
        int val = carry + l2->val;
        carry = val / 10;
        val = val % 10;
        insert(&res, val);
        l2 = l2->next;
    }

    if(carry > 0){
        insert(&res, carry);
    }

    return res;
} 






struct ListNode* createList(int args[], int n){
    struct ListNode* head = NULL;
    int index = 0;
    while(index<n){
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = args[index];
        node->next = head;
        head = node;
        index++;
    }
    return head;
}


void printLL(struct ListNode *head){
    while(head != NULL){
        printf("%d", head->val);
        head = head->next;
        printf("--> ");
    }
    printf("NULL\n");
}



int main(){
    int a[] = {9,9,9,9,9,9,9};
    int b[] = {9,9,9,9};
    struct ListNode *l1 = createList(a,7);
    struct ListNode *l2 = createList(b,4);

    printLL(l1);
    struct ListNode *res = addTwoNumbers(l1,l2);
    printLL(res);
}