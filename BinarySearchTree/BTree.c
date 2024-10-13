#include<stdio.h>
#include<stdlib.h>

typedef struct tnode{
    struct tnode *parent, *lchild, *rchild;
    int data;
} treeNode;


void preOrderTraversal(treeNode*);
void inOrderTraversal(treeNode*);
void postOrderTraversal(treeNode*);

void BST_insertion(int val);
void BST_deletion(int val);
treeNode * root = NULL; 

int main(){
    BST_insertion(50);
    BST_insertion(30);
    BST_insertion(70);
    BST_insertion(60);
    BST_insertion(80);
    BST_insertion(10);
    BST_insertion(65);
    BST_insertion(35);
    BST_insertion(40);


    printf("\nPre order traversal : ");
    preOrderTraversal(root);
    printf("\nIn order traversal  : ");
    inOrderTraversal(root);
    printf("\npost order traversal: ");
    postOrderTraversal(root);

    // BST_deletion(60);
    // BST_deletion(50);
    BST_deletion(30);

    printf("\n traversal  : ");
    printf("\nPre order traversal : ");
    preOrderTraversal(root);
    printf("\nIn order traversal  : ");
    inOrderTraversal(root);
    printf("\npost order traversal: ");
    postOrderTraversal(root);


    return 0;
}


void BST_insertion(int val) {
    treeNode *cur, *prev, *temp;

    temp = (treeNode*)malloc(sizeof(treeNode));
    if (temp == NULL) {
        printf("memory allocation error");
        return;
    }
    
    temp->data = val;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->parent = NULL;

    if (root == NULL) {
        root = temp;
        return;
    }

    prev = NULL;
    cur = root;

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

void  BST_deletion(int val){
    if(root == NULL){
        printf(" empty tree ");
        return;
    }

    treeNode *cur = root, *prev = NULL, *temp;
    while (cur != NULL && cur->data != val) {
        prev = cur;
        if (cur->data > val) {
            cur = cur->lchild;
        } else {
            cur = cur->rchild;
        }
    }

    if(cur == NULL){
        printf("\nnode doesn't exist\n");
        return;
    }

    if(cur->lchild != NULL && cur->rchild != NULL){
        temp = cur->lchild;
        
        while(temp->rchild != NULL){ 
            temp = temp->rchild;
        }
        printf("\n\n---------> %d\n",temp->data);
        cur->data = temp->data;
        
        if (temp->lchild != NULL) {
            temp->lchild->parent = temp->parent; 
        }

        if (temp->parent == cur) {
            cur->lchild = temp->lchild;
        } else {
            temp->lchild->parent = temp->parent;
            temp->parent->rchild = temp->lchild;

        }
        free(temp); 
        return;  
    }
    
    treeNode *child;
    if(cur->lchild != NULL){
       child = cur->lchild;
    }else{
       child = cur->rchild;
    }


    if(prev->data < val){
        prev->rchild = child;
    }else{
        prev->lchild = child;
    }
    free(cur);   
}


void preOrderTraversal(treeNode *temp){
    if(temp != NULL){
        printf(" %d ", temp->data);
        preOrderTraversal(temp->lchild);
        preOrderTraversal(temp->rchild);
    }
}

void inOrderTraversal(treeNode * temp){
    if(temp != NULL){
        inOrderTraversal(temp->lchild);
        printf(" %d ", temp->data);
        inOrderTraversal(temp->rchild);
    }
}

void postOrderTraversal(treeNode * temp){
    if(temp != NULL){
        postOrderTraversal(temp->lchild);
        postOrderTraversal(temp->rchild);
        printf(" %d ", temp->data);
    }
}
