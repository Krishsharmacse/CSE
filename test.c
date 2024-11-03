#include <stdio.h>
#include <string.h>

// #define MAX_CHAR 256

// int longestUniqueSubstring(char *str) {
//     int n = strlen(str);
    
//     int lastIndex[MAX_CHAR];
//     for (int i = 0; i < MAX_CHAR; i++) {
//         lastIndex[i] = -1;
//     }
    
//     int maxLength = 0; 
//     int start = 0;     

//     for (int end = 0; end < n; end++) {
//         int charAscii = (int)str[end];
//         if (lastIndex[charAscii] >= start) {
//             start = lastIndex[charAscii] + 1;
//         }

//         lastIndex[charAscii] = end;

//         int currentLength = end - start + 1;
//         if (currentLength > maxLength) {
//             maxLength = currentLength;
//         }
//     }

//     return maxLength;
// }

// int main() {
//     char str[] = "abcabcbb";
//     int length = longestUniqueSubstring(str);
//     printf("%d", length);
//     return 0;
// }

// C program to illustrate Call by Reference
// #include <stdio.h>
// #include<limits.h>

// Defining a structure to represent a person
// typedef struct Person {
//     char name[50];
//     int age;
//     float height;
// } Person;

// int main() {
//     // Declaring a structure variable of type Person
//     Person p1;

//     // Assigning values to the members of the structure
//     strcpy(p1.name, "John Doe");  // Using strcpy() to assign a string
//     p1.age = 30;
//     p1.height = 5.9;

//     // Accessing and printing the structure members
//     printf("Name: %s\n", p1.name);
//     printf("Age: %d\n", p1.age);
//     printf("Height: %.1f\n", p1.height);

//     return 0;
// }


// int reverse(int x){
//     int res = 0;
//     while(x > 0){
//         res = 10*res + x%10;
//         x = x/10;
//     }

// }

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// void sort(int *arr, int n)
// {
//     // Implementing a simple bubble sort for sorting
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             int x = arr[j], y = arr[j+1];
//             if (x > y)
//             {
//                 swap(&arr[j], &arr[j + 1]);
//             }
//         }
//     }
// }

// int main(){
//     int arr[] = {5,3,6,8};
//     sort(arr,4);

//     for(int i = 0; i< 4; i++){
//         printf("%d ",arr[i]);
//     }
// }




// ------------------- reverse K nodes -----------------
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;

}Node;

Node *head = NULL;
Node *NewHead = NULL;



void Insert(int val){
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;

    
    if(head == NULL){
        head = n;
        return;
    }

    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;

}


void disp(Node *head){
    Node *temp = head;
    while (temp != NULL){
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }  

    printf("\n");
}

Node* reverse( Node *previousNodes, Node *start, int k){
    // if(previousNodes != NULL){
    //     printf("\n\tprevious Node val %d\n\n", previousNodes->data);
    // }

    int c = 0;
    Node* temp = start;
    while(temp != NULL){
        c++;
        temp = temp->next;
    }
    if(c < k){
        // printf("remaining nodes is less than %d", k);
        return NULL;
    }

    Node *prev = NULL;
    Node *cur = start;
    Node *nex = NULL;

    // printf("cur -> %d\n", cur->data);

    while(cur != NULL && k > 0){
        nex = cur->next;
        cur->next = prev; 
        prev = cur;
        cur = nex;
        k--; 
    }
    
    // if(cur != NULL && nex != NULL && prev != NULL){
    //     printf("%d %d %d\n", prev->data, cur->data, nex->data);
    // }

    if(previousNodes != NULL){
        previousNodes->next = prev;
    }

    // disp(NewHead);

    while(prev != NULL && prev->next != NULL){
        prev = prev->next;
    }

    prev->next = cur;

   

    return prev;
}

int main(){

   
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Insert(6);
    Insert(7);
    Insert(8);

    disp(head);
    Node* start = head, *temp = head;
    int i = 1;
    int k = 3;
    while(temp->next != NULL && i<k){
        temp = temp->next;
        i++;
    }

    NewHead = temp;

    
    Node* previousNodes = NULL;

    while(start != NULL && start->next != NULL){
        previousNodes = reverse(previousNodes, start, k);
        start = start->next;
    }

    // printf("%d\n", start->data);
    

    disp(NewHead);




}