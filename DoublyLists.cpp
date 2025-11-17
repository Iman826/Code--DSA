#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node* next;
    Node* prev;
public:
    Node(int d, Node* n = nullptr, Node* p = nullptr) :data(d), next(n), prev(p) {}
    int retrieve() {
        return data;
    }
    friend class List;
};
class List {
    Node* head;
public:
    List() :head(nullptr) {}
    bool empty() {
        return head == nullptr;
    }
    void InsertAtHead(int d) {
        Node* n = new Node(d, head, nullptr);
        if (empty()) {
            head = n;
            return;
        }
        else {
            head->prev = n;
            head = n;
        }
    }
    void InsertionAtEnd(int d) {
        Node* n = new Node(d, nullptr, nullptr);
        if (empty()) {
            head = n;
            return;
        }
        Node* temp;
        for (temp = head;temp->next != nullptr;temp = temp->next) {}
        temp->next = n;
        n->prev = temp;
    }
    void InsertionAtMid(int d, int pos) {
        Node* n = new Node(d, nullptr, nullptr);
        Node* temp = head;
        if (empty()) {
            head = n;
            return;
        }
        for (int i = 1;i < pos - 1 && temp->next != nullptr;i++) {
            temp = temp->next;
        }
        Node* t = temp->next;
        n->next = t;
        n->prev = temp;
        temp->next = n;
        if (t != nullptr) {
            temp->next->prev = n;
        }
    } 
    void pop_front() {
        if (empty()) {
            throw underflow_error("List is Empty");
        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        else {
            Node* temp = head;
            head = head->next;
            temp->next = nullptr;
            head->prev = nullptr;
            delete temp;
        }
    }
    void pop_End() {
        if (empty()) {
            throw underflow_error("List is Empty");
        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        for (temp;temp->next->next != nullptr;temp = temp->next) {}
        Node* SecondLast = temp;
        Node* Last = SecondLast->next;
        SecondLast->next = nullptr;
        delete Last;
    }
    void Erase(int d) {
        if (head == nullptr) { return; }
        if (head->retrieve() == d) {
            pop_front();
            return;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->retrieve() == d) {
                prev->next = curr->next;
                if (curr->next!=nullptr) {
                    curr->next->prev = prev;
                }
               
                curr->next = nullptr;
                curr->prev = nullptr;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    void EraseAll(int d) {
    if (head == nullptr) return; // Empty list

    Node* curr = head;
    while (curr != nullptr) {
        if (curr->retrieve() == d) {
            // If curr is head
            if (curr == head) {
                head = head->next;
                if (head != nullptr)
                    head->prev = nullptr;
            } 
            // If curr is not head
            else {
                if (curr->prev != nullptr)
                    curr->prev->next = curr->next;
                if (curr->next != nullptr)
                    curr->next->prev = curr->prev;
            }

            // Clean up and delete
            curr->next = nullptr;
            curr->prev = nullptr;
            delete curr;
            return; // Delete only first occurrence
        }
        curr = curr->next;
    }
}

};
int main() {
    List l;
    l.InsertAtHead(14);
    l.InsertAtHead(34);
    l.InsertAtHead(24);
    l.InsertAtHead(24);
    l.InsertAtHead(24);
    l.InsertAtHead(44);
    l.pop_front();
    l.pop_End();
    l.Erase(24);
    l.Erase(24);
    return 0;
}
