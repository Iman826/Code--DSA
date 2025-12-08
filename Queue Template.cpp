#include<iostream>
using namespace std;

template<typename T>
class Node {
private:
    T data;
    Node<T>* next;

public:
    Node(T d) {
        data = d;
        next = nullptr;
    }

    T retrieve() {
        return data;
    }

    template<typename U>
    friend class Queue;
};

template<typename T>
class Queue {
private:
    Node<T>* tail;
    Node<T>* head;

public:
    Queue() {
        tail = head = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    T peek() {
        if (empty()) {
            throw underflow_error("Queue is Empty");
        }
        return head->retrieve();
    }

    void PopFront() {
        if (empty()) {
            cout << "Empty Queue...";
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    void PushEnd(T d) {
        Node<T>* n = new Node<T>(d);

        if (empty()) {
            head = tail = n;
            return;
        }

        tail->next = n;
        tail = n;
    }

    void display() {
        if (empty()) {
            cout << "\nQueue Empty";
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->retrieve() << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue<int> q;   // Template queue for int

    q.PushEnd(23);
    q.display();

    q.PushEnd(22);
    q.display();

    q.PushEnd(20);
    q.display();

    q.PopFront();
    q.display();

    q.PopFront();
    q.display();

    cout << "Front Element is: " << q.peek() << endl;

    q.PopFront();
    q.display();

    return 0;
}
