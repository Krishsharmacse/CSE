#include <iostream> 

using namespace std;

/*
A semaphore is a synchronization mechanism used in concurrent programming,
It controls access to a common resource by multiple threads, 
ensuring no race conditions occur (when two or more threads try to change the same resource at the same time). 
*/

class Semaphore {

    int count; // number of availble resources that can be shared between the threads

    public:
        Semaphore(int initCount){
            count = initCount;
        }
        
        /* 
            P -> to test
            if the count is less than or equal to zero means all the resources are allocated 
            so the thread which wants to use this function will wait until count is grater than 0
        */

        void wait() {
            while (count <= 0){}
            count--;
        }

        /* 
            V -> increment
            this functino is used by the thread after the job is done 
            it will increment the count meaning it will release the resource so that other
            process which are waiting may continue
        */
        void signal() {
            count++;
        }

        int getValue() const {
            return count;
        }
};

int main() {
    Semaphore S(2); 

    cout << "\nInitial semaphore value: ------------------- " << S.getValue() << endl;

    // Process/Thread 1
    // Wait: If the count is greater than 0, Process 1 acquires a resource.
    S.wait(); 
    cout << "Semaphore value after Process 1 wait(): ---- " << S.getValue() << endl;
   
    // Process/Thread 2
    // Wait: Process 2 acquires the second available resource.
    S.wait(); 
    cout << "Semaphore value after Process 2 wait(): ---- " << S.getValue() << endl;

    // Process/Thread 1
    // Signal: Process 1 releases a resource, incrementing the count.
    S.signal();
    cout << "Semaphore value after Process 1 signal(): -- " << S.getValue() << endl;
    
    // Process/Thread 2
    // Signal: Process 2 releases its resource, further incrementing the count.
    S.signal();
    cout << "Semaphore value after Process 2 signal(): -- " << S.getValue() << "\n\n";

    return 0;
}

