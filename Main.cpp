/*Allen Rehkemper 11/22/24 - 11/24/24 MS549 Assignment 431 Linked LIst Implemented as a stack and a queu

The initial expectation for this project was about 3.5 hours, I was close to being right on.  The biggest issue
with this was keeping tack of what the elements were doing and where they were, hence the number of comments in this
project being more than I usually do.  I was getting confused lol.  */

#include "functions.h"
//I found this library to help generate random numbers
#include <cstdlib> 

// Test stack operations and measure the time it takes to execute
void TestStack(int size) {
    Stack<int> stack;

    // Measure the time to insert elements into the stack
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        stack.Push(rand() % 10000);  
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Stack: Time to insert " << size << " elements: " << elapsed.count() << " seconds." << endl;

   
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        stack.Pop();
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Stack: Time to remove " << size << " elements: " << elapsed.count() << " seconds." << endl;
}

// Test queue operations and measure the time to execute
void TestQueue(int size) {
    Queue<int> queue;

    // Measure the time it takes to insert elements
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        queue.Enqueue(rand() % 10000);  
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Queue: Time to insert " << size << " elements: " << elapsed.count() << " seconds." << endl;

    // Measure the time to remove elements from the queue
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        queue.Dequeue();
    }
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    cout << "Queue: Time to remove " << size << " elements: " << elapsed.count() << " seconds." << endl;
}

int main() {
    // Test sizes for stack and queue
    vector<int> sizes = { 100, 1000, 10000 };

    for (int size : sizes) {
        cout << "Testing with " << size << " elements:" << endl;
        TestStack(size);
        TestQueue(size);
        cout << "----------------------------------" << endl;
    }

    return 0;
}
