#include <iostream>
using namespace std;

// Function template for swapping two elements
template <typename T>
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    Swap(x, y);  // Calls swap<int>(x, y)
    cout << "After swap: x = " << x << ", y = " << y << endl;

    double p = 1.23, q = 4.56;
    cout << "Before swap: p = " << p << ", q = " << q << endl;
    Swap(p, q);  // Calls swap<double>(p, q)
    cout << "After swap: p = " << p << ", q = " << q << endl;

    return 0;
}
