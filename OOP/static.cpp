#include<iostream>

using namespace std;

void count(){
    static int a = 0;
    cout<< a++ << " ";
}

int main(){
    count();
    count();
    count();
    count();

    return 0;
}