#include <iostream>
using namespace std;

//------------------ Node Class ------------------
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

//------------------ Singly List Class ------------------
class SinglyLst {
private:
    Node* head;

public:
    SinglyLst() {
        head = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        if (empty()) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //--------------- INSERTIONS -----------------

    void push_front(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void push_back(int val) {
        Node* n = new Node(val);

        if (empty()) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = n;
    }

    //--------------- DELETIONS -----------------

    void pop_front() {
        if (empty()) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if (empty()) {
            cout << "List is empty!\n";
            return;
        }

        // Only one element
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;
        delete curr;
    }

    //---------------- Insert at Middle -----------------
    void InsertAtMid(int val) {
        int n = size();
        int mid = n / 2;

        Node* nnode = new Node(val);

        // If inserting at head
        if (mid == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        nnode->next = temp->next;
        temp->next = nnode;
    }

    //---------------- Erase First Occurrence -----------------
    void EraseFirst(int val) {
        if (empty()) return;

        // If first node is the value
        if (head->data == val) {
            pop_front();
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

//------------------ MAIN ------------------

int main() {
    SinglyLst sl;

    sl.push_front(2);
    sl.push_back(8);
    sl.InsertAtMid(34);
    sl.push_back(24);

    cout << "After insertion: ";
    sl.display();  // Expected: 2 34 8 24

    sl.pop_front();
    sl.pop_back();
    cout << "After pop front & back: ";
    sl.display();  // 34 8

    sl.EraseFirst(8);
    cout << "After erasing 8: ";
    sl.display();  // 34

    cout << "Size: " << sl.size() << endl;  // 1

    return 0;
}
