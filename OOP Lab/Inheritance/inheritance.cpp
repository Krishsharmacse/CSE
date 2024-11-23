#include <iostream>
using namespace std;

class base{
    public:
        int a,b;
        base(int x, int y){
            a = x; b = y;
        }
        
        void add(){
            cout << a + b << endl;
        }
        
        void sub(){
            cout << a - b << endl;
        }
        
};
class Derived : public base
{
    public:
        Derived(int x, int y) : base(x,y){ }
        
        void mul(){
            cout << a * b << endl;
        }
        
        void div(){
            cout << a / b << endl;
        }
};

int main() {
    Derived obj(10,5);
    obj.add();
    obj.sub();
    obj.mul();
    obj.div();
    return 0;
}
