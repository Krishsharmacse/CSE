#include<iostream>
using namespace std;

class Engine {
    string type;
    public:
        Engine(string t) : type(t) {}
        void display() { cout << "Engine: " << type << endl; }

        ~Engine(){
            cout<<"destructor of engine" << endl;
        }
};

class Car {
    string model;
    Engine *engine; 
    public:

        Car(string m, string e) {
            model = m;
            engine = new Engine(e);
        }
        void display() {
            cout << "Car: " << model << endl;
            engine->display();
        }

        ~Car(){
            cout<<"destructor of car" << endl;
        }
};

int main() {
    Car myCar("Tesla", "Electric");
    myCar.display();
    return 0;
}
