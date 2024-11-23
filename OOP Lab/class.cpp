#include<iostream>
using namespace std;

void Greet(string msg = "world"){
    cout << "Hello " << msg << endl;
}

int main(){

    Greet();
    Greet("ujjwal");


    return 0;
}