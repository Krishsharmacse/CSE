#include<iostream>
using namespace std;

class Calc{
    float a, b;
    public:
        Calc(int a, int b){
            this->a = a;
            this->b = b;
        }

        void add(){
            cout<< "sum: " << a+b << endl;
        }

        void average(){
            cout << "avg: " << (a+b)/2 << endl;
        }

        void min(){
            cout<< "min: " << ((a<b)? a:b) << endl;
        }
        
        void max(){
            cout<< "max: " << ((a>b)? a:b) << endl;
        }

};


int main(){
    Calc obj(5 , 10);
    obj.add();
    obj.average();
    obj.min();
    obj.max();

    return 0; 
}