#include<iostream>

using namespace std;

class A{
    public:
        virtual void disp(){
            cout<<"class A"<<endl;
        }

        virtual ~A(){
            cout<<"class A destrutor"<<endl;
        }
};

class B : public A{
    public:
        void disp(){
            cout<<"class B"<<endl;
        }

        ~B(){
            cout<<"class B destrutor"<<endl;
        }
};

class C : public A{
    public:
        void disp(){
            cout<<"class C"<<endl;
        }

        ~C(){
            cout<<"class C destrutor"<<endl;
        }
};

int main(){
    A *obj  = new B(); 
    obj->disp();

    obj  = new C();
    obj->disp();

    delete obj;

    return 0;
}