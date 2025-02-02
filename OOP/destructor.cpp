#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {  // Virtual destructor
        cout << "Base class destructor called." << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived class destructor called." << endl;
    }
};

int main() {
    Base* obj = new Derived;  // Create a Derived object but use a Base pointer
    delete obj;  // Destructor of Derived and then Base will be called
    return 0;
}
