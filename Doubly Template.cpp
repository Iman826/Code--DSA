#include <iostream>
using namespace std;

template<typename T>
class Node {
private:
    T data;
    Node* next;
    Node* prev;

public:
    Node(T d, Node* n = nullptr, Node* p = nullptr)
        : data(d), next(n), prev(p) {}

    T retrieve() {
        return data;
    }

    template<typename U> friend class List;
};

template<typename T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}

    bool empty() {
        return head == nullptr;
    }

    void InsertAtHead(T d) {
        Node<T>* n = new Node<T>(d, head, nullptr);
        if (empty()) {
            head = n;
            return;
        }
        head->prev = n;
        head = n;
    }

    void InsertionAtEnd(T d) {
        Node<T>* n = new Node<T>(d, nullptr, nullptr);
        if (empty()) {
            head = n;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }

    void InsertionAtMid(T d, int pos) {
        Node<T>* n = new Node<T>(d, nullptr, nullptr);
        if (empty()) {
            head = n;
            return;
        }

        Node<T>* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        Node<T>* t = temp->next;
        n->next = t;
        n->prev = temp;

        temp->next = n;
        if (t != nullptr)
            t->prev = n;
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

        Node<T>* temp = head;
        head = head->next;
        head->prev = nullptr;

        temp->next = nullptr;
        delete temp;
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

        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node<T>* last = temp->next;
        temp->next = nullptr;

        delete last;
    }

    void Erase(T d) {
        if (head == nullptr) return;

        // Delete head
        if (head->retrieve() == d) {
            pop_front();
            return;
        }

        Node<T>* prev = head;
        Node<T>* curr = head->next;

        while (curr != nullptr) {
            if (curr->retrieve() == d) {
                prev->next = curr->next;

                if (curr->next != nullptr)
                    curr->next->prev = prev;

                curr->next = nullptr;
                curr->prev = nullptr;

                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void EraseAll(T d) {
        if (head == nullptr) return;

        Node<T>* curr = head;

        while (curr != nullptr) {
            if (curr->retrieve() == d) {
                Node<T>* toDelete = curr;
                curr = curr->next;

                // If deleting head
                if (toDelete == head) {
                    head = head->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                }
                else {
                    if (toDelete->prev != nullptr)
                        toDelete->prev->next = toDelete->next;

                    if (toDelete->next != nullptr)
                        toDelete->next->prev = toDelete->prev;
                }

                toDelete->next = nullptr;
                toDelete->prev = nullptr;
                delete toDelete;
            }
            else {
                curr = curr->next;
            }
        }
    }
};

int main() {
    List<int> l;

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
