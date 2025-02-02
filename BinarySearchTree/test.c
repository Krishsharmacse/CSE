#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Tnode{
    int data;
    struct Tnode* parent;
    struct Tnode* lchild;
    struct Tnode* rchild;
    
} Tnode;


Tnode* createnode(int val){
    Tnode* node =(Tnode*)malloc(sizeof(struct Tnode));
    node->data = val;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

Tnode* insertion(Tnode* root ,int val ){
    if(root == NULL){
        return createnode(val);
    }
    if(val < root->data){
        root->lchild = insertion(root->lchild, val);
    }
    else if (val > root->data){
        root->rchild = insertion(root->rchild, val);
    }

        return root;
    
}

bool search(Tnode* root , int target){
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    } else if(root->data > target){
       return search(root->lchild , target);
    } else{
        return search(root->rchild , target);
    }

}

void inorder(Tnode* root){
    if(root != NULL){
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }

}

void preorder(Tnode* root){
    if(root != NULL){
        printf("%d\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(Tnode* root){
    if(root != NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",  root->data);
    }
}

int main(){
    Tnode* Root = NULL;

    Root = insertion(Root ,50);
    Root = insertion(Root ,40);
    Root = insertion(Root ,30);
    Root = insertion(Root ,20);
    Root = insertion(Root ,10);
    Root = insertion(Root ,15);
    Root = insertion(Root ,5);

    inorder(Root);
    printf("\n");
    preorder(Root);
    printf("\n");
    postorder(Root);

    printf("\n\n");
    int key = 30;

    bool result = search(Root , key);
    
    if(result) printf("value %d found in the bst.\n",key);
    else printf("value %d not found in bst.\n",key);
    
    return 0;
}