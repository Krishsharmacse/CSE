#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

int main(){
    vector<int> ar = {1,2,4,3,4,5};
    vector<int>::iterator ptr = ar.begin();
    cout << *ptr << endl;
    advance(ptr,69);
    cout<< *ptr << endl;

    return 0;
}