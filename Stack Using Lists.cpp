#include<iostream>
using namespace std;
class Node {
private:
	int data;
    Node* next;
public:
    Node(int d) :data(d), next(nullptr) {}
    int retrieve() {
        return data;
    }
    friend class list;
};
class list {
    Node* head;
public:
    list() :head(nullptr) {}
    bool empty() {
        return head == nullptr;
    }
    //Insertion At Front
    void InsertAtFront(int d) {
        Node* n = new Node(d);
        if (empty()) {
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }
    //Pop Front
    void pop_front() {
        if (empty()) {
            throw underflow_error("List is Empty");
        }
        else {
            Node* temp = head;
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
    }
    //Peek
    int peek() {
        return head->retrieve();
    }
    //Display Function
    void display() {
        if (empty()) {
            cout << "[List is Empty]" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

class Stack {
private:
    list l;
public:
    void push(int d) {
        l.InsertAtFront(d);
   }
    void pop() {
        l.pop_front();
    }
    void peek() {
        l.peek();
    }
    bool empty() {
        return l.empty();
    }
    void display() {
        l.display();
    }

};
int main() {
    Stack s;
    try {
        s.push(23);
        s.push(24);
        s.push(26);
        s.push(28);
        s.display();
        s.pop();
        s.display();
        s.peek();
        s.display();
       
    }
    catch (exception& e) {
        cout << "ERROR: " << e.what() << endl;
    }
    return 0;
}