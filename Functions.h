#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

// Node class for the doubly-linked list
template <typename T>
class Node {
public:

    T Data;               
    Node<T>* Next;        
    Node<T>* Prev;        

    Node(T data) : Data(data), Next(nullptr), Prev(nullptr) {}
};

// Stack implemented as a doubly-linked list
template <typename T>
class Stack {
private:
    Node<T>* top;  

public:
    
    Stack();

    void Push(T data);
    bool Pop();
    void Print();
};

// Queue implemented as a doubly-linked list
template <typename T>
class Queue {
private:
    Node<T>* front;  
    Node<T>* back;   

public:
 
    Queue();

    // Enqueue method to add an element to the back of the queue
    void Enqueue(T data);

    // Dequeue method to remove an element from the head of the queue
    bool Dequeue();
    void Print();
};

#endif
