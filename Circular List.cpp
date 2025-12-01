
#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node* next;
public:
    Node(int d, Node* n = nullptr) : data(d), next(n) {}
    int retrieve() { return data; }
    friend class List;
};
class List {
private:
    Node* head;
public:
    List() : head(nullptr) {}
    bool empty() { return head == nullptr; }
    // Insert at head
    void InsertAtHead(int d) {
        Node* n = new Node(d);
        if (empty()) {
            head = n;
            n->next = head;
            return;
        }
        // Find last node
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = n;
        n->next = head;
        head = n;
    }
    void InsertAtEnd(int d) {
        Node* n = new Node(d);
        Node* temp = head;
        for (temp;temp->next != head;temp = temp->next) {}
        temp->next = n;
        n->next = head;
        if (head->next == head) {
            head->next = n;
            n->next = head;
        }
        if (empty()) {
            head = n;
            n->next = head;
        }
    }
    void InsertAtMid(int d, int pos) {
        Node* n = new Node(d);
        if (head->next == head || pos == 1) {
            head->next = n;
            n->next = head;
        }
        if (empty()) {
            head = n;
            n->next = head;
        }
        Node* temp = head;
        for (int i = 1;i < pos - 1 && temp != nullptr;i++) {
            temp = temp->next;
        }
        Node* t = temp->next;
        temp->next = n;
        n->next = t;
    }
     void pop_front() {
        // empty List
        if (head == nullptr) {
        cout << "-------Error Empty List--------" << endl;
        return;
        }
        // only one node
        else if (head->next==head) { 
        delete head;
        head = nullptr;
        return;
        }
        //Multiple Nodes
         else {
         Node * temp=head;
          Node* last;
         for(last=head;last->next!=head;last=last->next){
            
         }
         //Moving head forward
         head=head->next;
         //separating the 1st node
         last->next=head;
         //1st node's next become nullptr
         temp->next=nullptr;
         //deleting the 1st node
         delete temp;
        }
        }

        void pop_back() {
        
        if (head == nullptr) {
        cout << "-------Error Empty List--------" << endl;
        }
        //single node
        if(head->next==head){
         delete head;
         return;
        }        
        //Multiple Nodes
        else {
        Node* temp;
        for(temp=head;temp->next->next!=head;temp=temp->next){
        }
        //temp is 2nd last and temp ->next is last 
        Node * last=temp->next;
        temp->next=temp->next->next;
        last->next=nullptr;
        delete last;
        }
        }
    // Delete all occurrences of a value
    void DeletionAtMid(int d) {
        if (empty()) return;

        Node* curr = head;
        Node* prev = nullptr;
        bool firstPass = true;

        do {
            if (curr->retrieve() == d) {
                Node* toDelete = curr;

                // Case: deleting head
                if (curr == head) {
                    // find last node
                    Node* last = head;
                    while (last->next != head) last = last->next;

                    if (head->next == head) { // only one node
                        delete head;
                        head = nullptr;
                        return;
                    }

                    head = head->next;
                    last->next = head;
                    curr = head;
                }
                else { // deleting middle/end node
                    prev->next = curr->next;
                    curr = curr->next;
                }toDelete->next = nullptr;
                delete toDelete;
            }
            else {
                prev = curr;
                curr = curr->next;
            }firstPass = false;
        } while (curr != head || firstPass);
    }
    // Display the list
    void display() {
        if (empty()) {
            cout << "List is empty\n";
            return;
        } Node* temp = head;
        do {
            cout << temp->retrieve() << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)\n";
    }
};
int main() {
    List l;
    // Insertions
    l.InsertAtHead(24);
    l.InsertAtHead(35);
    l.InsertAtHead(20);
    l.InsertAtHead(23);
    cout << "After Insertions:" << endl;
    l.display();
     cout << "After Pop Back:" << endl;
    l.pop_back();
     l.display();
     cout << "After Pop Front:" << endl;
    l.pop_front();
    l.display();
    // Delete all occurrences of 23
    l.DeletionAtMid(35);
    cout << "After Deletion of 23:" << endl;
    l.display();
    return 0;
}
