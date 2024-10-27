#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *cur = head, *nex = NULL;
    while (head != NULL){
        nex = head->next;
        head->next = prev;
        prev = head;
        head = nex;
    }
    return prev;
}