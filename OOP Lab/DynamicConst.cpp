#include<iostream>
#include<cstring>
using namespace std;

class String{
    char* str;
    int length;
    public:
        String(const char* s1){
            length = strlen(s1);
            str = new char[length+1];
            strcpy(str, s1);
        }

        void show(){
            cout<< "stored string: " << str;
        }
};

int main(){
    String str("Hello");
    str.show();

    return 0;
}