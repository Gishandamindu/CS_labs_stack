#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std::chrono;
using namespace std;

// Implement Stack and its functions using Array.
#define MAX_SIZE 100 // Define maximum size of the stack

class Stack {
private:
    int top; // Top index of the stack
    int arr[MAX_SIZE]; // Array to hold stack elements

public:
    Stack() { // Constructor to initialize the stack
        top = -1; // set top index to -1
    }

    void Push(int data) { // Push function to insert element into stack
        if (isFull()) { // if stack is full
            cout << "Stack Overflow\n"; // display error message
        }
        else {
            top++; // increment top index
            arr[top] = data; // insert element into stack
        }
    }

    void Pop() { // Pop function to remove element from stack
        if (isEmpty()) { // if stack is empty
            cout << "Stack Underflow\n"; // display error message
        }
        else {
            int data = arr[top]; // store the top element in a variable
            top--; // decrement top index
        }
    }

    bool isEmpty() { // function to check if stack is empty
        return top == -1; // return true if top index is -1 (stack is empty)
    }

    bool isFull() { // function to check if stack is full
        return top == MAX_SIZE - 1; // return true if top index is equal to the maximum size of the stack minus 1 (stack is full)
    }

    int stackTop() { // function to return the top element of the stack
        if (isEmpty()) { // if stack is empty
            return -1; // return -1 (stack is empty)
        }
        else {
            return arr[top]; // return the top element of the stack
        }
    }

    void Display() { // function to display the elements of the stack
        if (isEmpty()) { // if stack is empty
            cout << "Stack is empty\n"; // display error message
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) { // loop through the elements of the stack
                cout << arr[i] << " "; // display the elements of the stack
            }
            cout << endl;
        }
    }
};

int main() {
    Stack S; // create an object of class Stack
    auto start_time = high_resolution_clock::now(); // start measuring the execution time
    S.Push(8); // insert element into stack
    S.Push(10);
    S.Push(5);
    S.Push(11);
    S.Push(15);
    S.Push(23);
    S.Push(6);
    S.Push(18);
    S.Push(20);
    S.Push(17);
    S.Display(); // display the elements of the stack
    S.Pop(); // remove the top element from the stack
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Display(); // display the elements of the stack
    S.Push(4); // insert element into stack
    S.Push(30);
    S.Push(3);
    S.Push(1);
    S.Display(); // display the elements of the stack
    auto end_time = high_resolution_clock::now(); // stop measuring the execution time
    auto execution_time = duration_cast<microseconds>(end_time - start_time); //
    cout << "Execution time: " << execution_time.count() << "microseconds" << endl;

    return 0;
}