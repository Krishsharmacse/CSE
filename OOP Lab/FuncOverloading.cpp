#include<iostream>
using namespace std;

void add(int a, int b){
    cout << a+b << endl;
}

void add(int a, int b, int c){
    cout << a+b+c << endl;
}

void add(double a, double b){
    cout<< a+b << endl;;
}



int main(){

    add(5, 2);
    add(5, 2, 3);
    add(22.2, 14.3);

    return 0;
}