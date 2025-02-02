#include<iostream>
using namespace std;


int main(){
    string name; int age;

    cout<< "enter your age: ";
    cin>>age;
    
    cin.ignore();
    
    cout<< "enter your name: ";
    getline(cin, name);

    cout << "Name: " << name << ", Age: " << age << endl;

}