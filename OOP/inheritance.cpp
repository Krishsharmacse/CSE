#include<iostream>
using namespace std;

// class Base {
// public:
//     int x = 1;  // Public member
// protected:
//     int y = 2;  // Protected member
// private:
//     int z = 3;  // Private member
// };

// // class Derived : public Base {
// // class Derived : private Base {
// class Derived : protected Base {
// public:
//     void display() {
//         cout << "Public member x: " << x << endl; 
//         cout << "Protected member y: " << y << endl; 
//         // cout << "Private member z: " << z << endl; // Error: Private members are not accessible
//     }
// };

// int main() {
//     Derived obj;
//     obj.display(); 
//     return 0;
// }



/*                           -------------BASE CLASS MEMBERS-------------

                            public members       protected members   private members 
public inheritance              public               protected             X           
private inheritance             private              private               X 
protected inheritance           protected            protected             X

*/



class A{
    int x;
    public:
        A(int a): x(a){}
        void display(){
            cout<<"base class : "<< x <<endl;
        }
};


class B : public A{
    int y;
    public:
        B(int a, int b): y(a), A(b) {}

        void display(){
            A::display();
            cout<<"derived class: "<<y <<endl;
        }
};


int main(){
    B obj(2,3);
    obj.display();
}