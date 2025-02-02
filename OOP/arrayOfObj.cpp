#include<iostream>

using namespace std;


class Student{
    string name;
    int rollno;

    public:
        Student(string n, int r) : name(n), rollno(r) {}

        void getData(){
            cout << "Name: " << name << ", Roll No.: " << rollno << endl;
        }
};


int main(){

    Student students[3] = {
        Student("John", 20),
        Student("Alice", 21),
        Student("Bob", 22)
    };

    for (int i = 0; i < 3; i++) {
        students[i].getData();
    }

}