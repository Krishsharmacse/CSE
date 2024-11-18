//BST
#include<stdio.h>
#include<stdlib.h>

typedef struct tnode{
    struct tnode *parent, *lchild, *rchild;
    int data;
} treeNode;


void inOrderTraversal(treeNode*);


void BST_insertion(int val);
void BST_deletion(int val);
int BST_Search(treeNode* root, int val);

treeNode * root = NULL; 

int main(){
    BST_insertion(50);
    BST_insertion(30);
    BST_insertion(70);
    BST_insertion(60);
    BST_insertion(80);
    BST_insertion(10);
    BST_insertion(65);
    BST_insertion(40);
    BST_insertion(35);

    printf("\na) Insertion : ");
    inOrderTraversal(root);


    BST_deletion(70);
    printf("\nb) Delete 70 : ");
    inOrderTraversal(root);

    int val = 35;
    printf("\nc) search %d : ", val);
    if(BST_Search(root, val)){
        printf("\n\tvalue %d exist in the tree\n", val);
    }else{
        printf("\n\tvalue %d doesn't exist in the tree\n", val);
    }

    


    return 0;
}

treeNode *CreateNode(int val){
    treeNode *Node = (treeNode *)malloc(sizeof(treeNode));
    if(Node == NULL){
        printf("allocation failed");
        exit(1);
    }

    Node->data = val;
    Node->parent = NULL;
    Node->lchild = NULL;
    Node->rchild = NULL;

    return Node;
}


void BST_insertion(int val) {
   treeNode *Node = CreateNode(val);

    if(root == NULL){
        root = Node;
        return;
    }

   treeNode *prev = NULL, *cur = root;
    while(cur != NULL){
        prev = cur;
        if(cur->data > val){
            cur = cur->lchild;
        }else{
            cur = cur->rchild;
        }
    }
    if(prev->data > val){
        prev->lchild = Node;
    }else{
        prev->rchild = Node;
    }
    Node->parent = prev;
}

void  BST_deletion(int val){
    if(root == NULL){
        printf("tree is empty\n");
        return;
    }

   treeNode *prev = NULL, *cur = root;
    while(cur != NULL && cur->data != val){
        prev = cur;
        if(cur->data > val){
            cur = cur->lchild;
        }else{
            cur = cur->rchild;
        }
    }

    if(cur == NULL){
        printf("not found\n");
        return;
    }

    if(cur->lchild != NULL && cur->rchild != NULL){
        treeNode *temp = cur->lchild;
        while(temp->rchild != NULL){
            temp = temp->rchild;
        }

        cur->data = temp->data;

        if (temp->lchild != NULL) {
            temp->lchild->parent = temp->parent; 
        }

        if (temp->parent == cur) {
            cur->lchild = temp->lchild;
        } else {
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


int BST_Search(treeNode *root, int val){
    if(root == NULL){
        return 0;
    }

    if(root->data == val){
        return 1;
    }else if(root->data > val){
        return BST_Search(root->lchild, val);
    }else{
        return BST_Search(root->rchild, val);
    }
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




//  treeNode *cur, *prev, *temp;

//     temp = (treeNode*)malloc(sizeof(treeNode));
//     if (temp == NULL) {
//         printf("memory allocation error");
//         return;
//     }
    
//     temp->data = val;
//     temp->lchild = NULL;
//     temp->rchild = NULL;
//     temp->parent = NULL;

//     if (root == NULL) {
//         root = temp;
//         return;
//     }

//     prev = NULL;
//     cur = root;

//     while (cur != NULL) {
//         prev = cur;
//         if (cur->data < val ) {
//             cur = cur->rchild;
//         } else {
//             cur = cur->lchild;
//         }
//     }


//     if (prev->data > val) {
//         prev->lchild = temp;
//     } else {
//         prev->rchild = temp;
//     }

//     temp->parent = prev;





// deletion

// if(root == NULL){
//         printf(" empty tree ");
//         return;
//     }

//     treeNode *cur = root, *prev = NULL, *temp;
//     while (cur != NULL && cur->data != val) {
//         prev = cur;
//         if (cur->data > val) {
//             cur = cur->lchild;
//         } else {
//             cur = cur->rchild;
//         }
//     }

//     if(cur == NULL){
//         printf("\nnode doesn't exist\n");
//         return;
//     }

    // if(cur->lchild != NULL && cur->rchild != NULL){
    //     temp = cur->lchild;
        
    //     while(temp->rchild != NULL){ 
    //         temp = temp->rchild;
    //     }
    //     printf("\n\n---------> %d\n",temp->data);
    //     cur->data = temp->data;
        
    //     if (temp->lchild != NULL) {
    //         temp->lchild->parent = temp->parent; 
    //     }

    //     if (temp->parent == cur) {
    //         cur->lchild = temp->lchild;
    //     } else {
    //         temp->lchild->parent = temp->parent;
    //         temp->parent->rchild = temp->lchild;

    //     }
    //     free(temp); 
    //     return; 
    // }
    
//     treeNode *child;
//     if(cur->lchild != NULL){
//        child = cur->lchild;
//     }else{
//        child = cur->rchild;
//     }


//     if(prev->data < val){
//         prev->rchild = child;
//     }else{
//         prev->lchild = child;
//     }
//     free(cur); 