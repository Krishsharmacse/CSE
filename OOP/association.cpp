#include<iostream>
using namespace std;

class Teacher{
        string name;
    public: 

        Teacher(string n) : name(n) {}

        void disp(){
            cout<<"Teacher: "<< name<<endl;
        }

    ~Teacher(){
        cout<< "Desctructor of teacher class"<<endl;
    }
};

class Student{
    string name;
    Teacher *teacher;
    public:

        Student(string n, Teacher *obj){
            name = n;
            teacher = obj;
        }

        void disp(){
            cout<<"Student: "<< name << endl;
            if(teacher) teacher->disp();
        }

    ~Student(){
        cout<< "Desctructor of student class"<<endl;
    }
};


int main(){

    Teacher t1("xyz");

    Student s1("abc", &t1);

    s1.disp();

}   