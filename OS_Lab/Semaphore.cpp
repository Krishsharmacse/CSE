#include <iostream> 
using namespace std;

class Semaphore {

    int count; // available resources that can be shared between threads

    public:
        Semaphore(int initCount){
            count = initCount;
        }
        
        /* 
        wait
            If the count is less than or equal to zero, it means all resources are allocated, 
            so the thread that wants to use this function will wait until count is greater than 0.
        */
        void wait() {
            while (count <= 0){}
            count--;
        }

        /* 
        signal
            This function is used by a thread after its job is done. 
            It increments the count, meaning it releases the resource so that other
            processes waiting can continue.
        */
        void signal() {
            count++;
        }

        int getValue() const {
            return count;
        }
};





int main() {
    Semaphore S(1);;

    cout << "\nInitial semaphore value: ------------------- " << S.getValue() << endl;

    // Process 1
    // Wait: If the count is greater than 0, Process 1 acquires a resource.
    S.wait();
    cout << "Semaphore value after Process 1 wait(): ---- " << S.getValue() << endl;
   
    // Process 1
    // Signal: Process 1 releases a resource, incrementing the count.
    S.signal();
    cout << "Semaphore value after Process 1 signal(): -- " << S.getValue() << endl;
   
    return 0;
}

