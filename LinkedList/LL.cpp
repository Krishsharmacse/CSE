#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int val){
            data = val;
            next = nullptr;
        }   
};

void Insert(Node* &head, int val){
    Node *n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = n;
}


void disp(Node *head){
    Node *temp = head;

    while (temp != nullptr){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL";
}


int main(){

    Node *head =  nullptr;

    int arr[5] = {1,2,3,4,5};
    int i=0;

    while(i<5){
        Insert(head, arr[i]);
        i++;
    }


    disp(head);


    return 0;
}