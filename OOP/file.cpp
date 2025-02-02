#include<iostream>
#include<fstream>

using namespace std;

int main(){
    fstream file("test.txt", ios::out | ios::in | ios::app);
    if(!file.is_open()){
        cout<< "error while opening the file"<<endl;
    }

    string msg;
    cout<< "enter the data to be entered in file: ";
    getline(cin, msg);
    
    file<<msg;



    cout<<"data from the file "<<endl;
    while(file.eof() == 0){
        getline(file, msg);
        cout<<msg <<endl;
    }
}