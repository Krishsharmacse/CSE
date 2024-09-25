#include<stdio.h>
#include<stdlib.h>

typedef struct tnode *treeptr;
typedef struct tnode{
    treeptr parent, lchild, rchild;
    int data;
} treeNode;


void BST_insertion(treeptr *root, int val);
void BST_deletion(treeptr *root, int val);

int main(){

    return 0;
}


void BST_insertion(treeptr *root, int val) {
    treeptr cur, prev, temp;

    temp = (treeptr)malloc(sizeof(treeNode));
    if (temp == NULL) {
        printf("memory allocation error");
        return;
    }
    
    temp->data = val;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->parent = NULL;

    if (*root == NULL) {
        *root = temp;
        return;
    }

    prev = NULL;
    cur = *root;

    while (cur != NULL) {
        prev = cur;
        if (cur->data < val ) {
            cur = cur->rchild;
        } else {
            cur = cur->lchild;
        }
    }

    if (prev->data > val) {
        prev->lchild = temp;
    } else {
        prev->rchild = temp;
    }

    temp->parent = prev;
}

void  BST_deletion(treeptr *root, int val){

}