#include<iostream>

using namespace std;


// unary operator 
class Number{
    int x;
    public:
        Number(int num) : x(num) {}

        void display(){
            cout << "value in class: " << x;
        }

        void operator++(){
            ++x;
        }
        
        void operator++(int){
            x++;
        }
};



//binary operator overloading
class Complex{
    int real, img;
    public:
        Complex(int r, int i){
            real = r; img = i;
        }


        Complex operator+(Complex n2){
            int r = real + n2.real;
            int i = img + n2.img;
            return Complex(r,i);
        }

        void disp(){
            cout<< real << " + i" << img;
        }
};

int main(){
    Complex n1(2,3);
    Complex n2(5,6);

    Complex sum = n1+n2;

    sum.disp();

    Number n(10);
    n++;

    n.display();

}