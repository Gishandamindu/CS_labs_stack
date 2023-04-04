
//Implement Stack and its functions using LinkedList.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std::chrono;
using namespace std;

// Define the Node class for creating nodes
class Node {
public:
    int data; // Data of the node
    Node* next; // Pointer to the next node

    Node(int data) { // Constructor to initialize the node
        this->data = data;
        next = NULL;
    }
};

// Define the Stack class for creating stacks
class Stack {
private:
    Node* top; // Top node of the stack

public:
    Stack() { // Constructor to initialize the stack
        top = NULL;
    }

    // Function to push data onto the stack
    void Push(int data) {
        Node* newNode = new Node(data); // Create a new node with the given data

        if (top == NULL) { // If stack is empty, make the new node as top
            top = newNode;
        }
        else { // Else, add the new node at the top and make it the new top
            newNode->next = top;
            top = newNode;
        }
    }

    // Function to pop data from the stack
    void Pop() {
        if (isEmpty()) { // If stack is empty, print "Stack Underflow"
            cout << "Stack Underflow\n";
        }
        else { // Else, remove the top node and delete it
            int data = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Function to get the top element of the stack
    int stackTop() {
        if (isEmpty()) { // If stack is empty, return -1
            return -1;
        }
        else { // Else, return the data of the top node
            return top->data;
        }
    }

    // Function to display the elements of the stack
    void Display() {
        if (isEmpty()) { // If stack is empty, print "Stack is empty"
            cout << "Stack is empty\n";
        }
        else { // Else, display all the elements of the stack
            cout << "Stack elements: ";
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    auto start_time = high_resolution_clock::now(); // Start measuring the execution time
    Stack S;
    S.Push(8);
    S.Push(10);
    S.Push(5);
    S.Push(11);
    S.Push(15);
    S.Push(23);
    S.Push(6);
    S.Push(18);
    S.Push(20);
    S.Push(17);
    S.Display();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Pop();
    S.Display();
    S.Push(4);
    S.Push(30);
    S.Push(3);
    S.Push(1);
    S.Display();
    auto end_time = high_resolution_clock::now(); // Stop measuring the execution time
    auto execution_time = duration_cast<microseconds>(end_time - start_time); // Calculate the execution time
    cout << "Execution time: " << execution_time.count() << " microseconds" << endl; // Display the execution time

    return 0;
}
