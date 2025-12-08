#include<iostream>
using namespace std;

template<typename T>
class Stack {
private:
    T arr[5];     // fixed-size array
    int top;

public:
    Stack() {
        top = -1;
    }

    // Check if empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if full
    bool isFull() {
        return top == 4;
    }

    // Pop element
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
            return;
        }
        top--;
    }

    // Push element
    void push(T d) {
        if (isFull()) {
            cout << "Stack OverFlow";
            return;
        }
        arr[++top] = d;
    }

    // Peek element
    T Peek() {
        if (isEmpty()) {
            throw underflow_error("Stack Empty");
        }
        return arr[top];
    }

    // Display all elements
    void Display() {
        if (isEmpty()) {
            cout << "Stack Empty";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }

   // Capacity function
    int capacity() {
        return 5;
    }
};

int main() {
    Stack<int> k;   // Template version

    try {
        cout << "Stack Capacity: " << k.capacity() << endl << endl;

        k.push(23);
        k.push(12);
        k.Display();

        k.pop();
        k.Display();
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
