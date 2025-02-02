#include<iostream>
using namespace std;

// class A{
//     int x;
//     public:
//         A(int val) : x(val){}
//         friend void disp(A obj);
// };

// void disp(A obj){
//     cout<< obj.x<<endl;
// }



// // friend of two class
// class B;
// class A{
//     int x;
//     public:
//         A(int val) : x(val){}
//         friend void add(A n1, B n2);
// };



// class B{
//     int y;
//     public:
//         B(int val) : y(val){}
//         friend void add(A n1, B n2);
        
// };

// void add(A n1, B n2){
//     cout<< n1.x + n2.y <<endl;
// }




// // friend classs

// class A{
//     int x;
//     public:
//         A(int val) : x(val){}
//         friend class B;
// };



// class B{
//     public:
//         void disp(A obj){
//             cout<< obj.x <<endl;
//         }
        
// };




// int main(){ 
//     A a(10);
//     B obj;

//     obj.disp(a);
//     return 0;
// }




// #include <iostream>
// using namespace std;

// class A;

// class B {
// public:
//     void disp(A obj);
// };

// class A {
// private:
//     int value;

// public:
//     A(int val) : value(val) {}

//     // Declare B's member function as a friend
//     friend void B::disp(A obj);
// };




// void B::disp(A obj){
//     cout << "Value from A: " << obj.value << endl;
// }


// int main() {
//     A a(42);
//     B b;
//     b.disp(a); // Access A's private member using B's function
//     return 0;
// }
