#include<iostream>

using namespace std;

class A{
    int a, b;
    int *arr = NULL, size = 0;
    public:

        // non parametrized constructor
        A(){
            a = 0; b = 0;
        }

        // parametrized constructor 
        A(int a, int b){
            this->a = a;
            this->b = b;
        }


        // copy constructor
        A(A &obj){
            a = obj.a;
            b = obj.b;
        }

        // dynamic constructor :  allocates memoery dynamically
        A(int s){
            size = s;
            arr = new int[size];
            for(int i = 0; i< s; i++){
                arr[i] = i+1;
            }
        }


        void printArray(){
            for(int i = 0; i< size; i++){
                cout<< arr[i] << " ";
            }
            cout<<endl;
        }
        void disp(){
            cout<< a << " " << b << endl;
        }
};


int main(){
    // A obj(1,2);

    // A obj2(obj);

    // obj.disp();
    // obj2.disp();

    A obj(4);
    obj.printArray();

}