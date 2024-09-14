#include<iostream>
using namespace std;


class Calc{
    public:
        int add(int a, int b){
            return a+ b;
        }
};

int main(){
    int a,b;
    cout<<"fist num: ";
    cin>>a;
    cout<<"second num: ";
    cin>>b;
    Calc calc;
    cout<<a <<" + "<< b << " = " << calc.add(a,b);
}

// int main(){

//     cout<< "hello world";

//     return 0;
// }

