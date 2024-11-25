#include "functions.h"

// Constructor for initializing the empy stack
template <typename T>
Stack<T>::Stack() : top(nullptr) {}

// Push adds an element to the top of the stack LIFO
template <typename T>
void Stack<T>::Push(T data) {

    // Create a new node 
    Node<T>* newNode = new Node<T>(data);

    // If the stack is not empty, link the new node to the current top
    if (top) {

        // The new node's "next" points to the current head
        newNode->Next = top;  
        top->Prev = newNode; 
    }

    // Updates the top pointer to the new node
    top = newNode;
}

// Pop: Removes the top element from the stack
template <typename T>
bool Stack<T>::Pop() {
    if (!top) return false;  

    // Saves the current top node to delete it later then updates the top pointer to the next node
    Node<T>* temp = top;
    top = top->Next;

    // If the new top is not null, unlink its "prev" pointer
    if (top) {
        top->Prev = nullptr;
    }

    // Delete the old top node
    delete temp;
    return true;
}

// Print: Displays the stack's contents from top to bottom
template <typename T>
void Stack<T>::Print() {
    Node<T>* current = top;  

    // Traverse the stack, printing each node's data
    while (current) {
        cout << current->Data << " ";
        current = current->Next;
    }
    cout << endl;
}


// Constructor: Initializes an empty queue FIFO
template <typename T>
Queue<T>::Queue() : front(nullptr), back(nullptr) {}

// Enqueue: Adds an element to the back of the queue
template <typename T>
void Queue<T>::Enqueue(T data) {
    Node<T>* newNode = new Node<T>(data);

    // If the queue is not empty, link the new node to the current back
    if (back) {

        // The current back's "next" points to the new node and the new node's "prev" points back to the current back
        back->Next = newNode;  
        newNode->Prev = back;  
    }

    // Update the back pointer to the new node
    back = newNode;

    if (!front) {
        front = back;
    }
}

// Dequeue: Removes an element from the front of the queue
template <typename T>
bool Queue<T>::Dequeue() {
    if (!front) return false;  

    // Save the current front node to delete it later
    Node<T>* temp = front;
    front = front->Next;

    // If the new front is not null, unlink its "prev" pointer, if now empty, reset the back pointer
    if (front) {
        front->Prev = nullptr;
    }
    else {
        back = nullptr;
    }

    delete temp;
    return true;
}

//print
template <typename T>
void Queue<T>::Print() {
    Node<T>* current = front;  

    
    while (current) {
        cout << current->Data << " ";
        current = current->Next;
    }
    cout << endl;
}


template class Stack<int>;
template class Queue<int>;
