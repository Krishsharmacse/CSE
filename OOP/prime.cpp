#include <iostream>
using namespace std;


int fact(int n){
    if(n==0 || n == 1) return 1;
    return n * fact(n-1);
}


bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    
    return ( ( 1 + fact(num-1) ) % num ==0 );
}

int main() {
    cout << "Prime numbers from 1 to 100 are:" << endl;

    for (int i = 1; i <= 100; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }


    return 0;
}
