#include<iostream>
#include<iomanip>

using namespace std;


ostream& custom_manip(ostream& os) {
    os << ">>> ";
    return os;
}



int main(){
    int num = 17;
    float x = 10.213546;
    string s;

    // cout<<"int input: ";
    // cin>>a;

    // cout<<"string: ";
    // getline(cin,s);

    // cout << "Hello, World!" << flush;
    cout << setw(10) << "Hi" << endl;
    cout << setfill('*') <<setw(10) << 123<<endl;

    double pi = 3.14159265359;

    // cout << setprecision(3) << pi << endl;
    cout << fixed << setprecision(3) << pi << endl;

    cout << dec << "dec: " <<  num << endl; 
    cout << hex << "hex: " << num << endl; 
    cout << oct << "oct: " << num << endl;


    cout << custom_manip << "Hello, World!" << endl;

}