#include<iostream>
using namespace std;

class ComplexNumber{
    int real, img;
    public:

        ComplexNumber(int real, int img){
            cout<< "const with two arguments "<< endl;
            this->real = real;
            this->img = img;
        }

        ComplexNumber(ComplexNumber &obj){
            cout<<"copy const\n";
            real = obj.real;
            img = obj.img;
        }

        void show(){
            cout<< real << " + i" << img << endl;
        }
};

int main(){
    ComplexNumber a(5,2); 
    ComplexNumber b(a);

    a.show();
    b.show();

    return 0;
}