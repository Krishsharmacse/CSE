#include<iostream>
using namespace std;


namespace MyNameSpcae{
    int x = 10;

    void greet(){
        cout<<"hello world"<<endl;
    }

    class A{
        public:
        void display(){
            cout<< "this is class in namespace"<<endl;
        }
    };

}

void greet(){
    cout<<"good eve"<<endl;
}

int main(){
    greet();
    MyNameSpcae::greet();
    MyNameSpcae::A obj;
    obj.display();
}