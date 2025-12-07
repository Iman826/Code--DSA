// simple_tree_lab.cpp
// Lab_11_BSAI_00000    <-- replace with your actual Lab/Degree/Roll
// Author: (aapka naam yahan)
// Description: Implementation of a general tree (Simple_tree) using templates,
// linked-list based children (List/Node), and Queue for BFS. Includes DFS (preorder)
// and BFS traversals and example usage.

#include <iostream>
#include <cassert>
#include <algorithm> // for std::max
#include <string>

using namespace std;

// ---------------------------
// Node for singly linked list (templated)
// ---------------------------
template<typename T>
class Node {
private:
    T data_;
    Node<T>* next_;
public:
    Node(const T& data, Node<T>* next = nullptr) : data_(data), next_(next) {}
    T retrieve() const { return data_; }
    T& retrieve_ref() { return data_; }
    Node<T>* next() const { return next_; }
    void set_next(Node<T>* n) { next_ = n; }
};

// ---------------------------
// Simple singly-linked List (templated) to hold elements (like children pointers)
// Provides head(), tail(), push_back, remove (erase), size, for iteration helper
// ---------------------------
template<typename T>
class List {
private:
    Node<T>* head_;
    Node<T>* tail_;
    size_t count_;
public:
    List() : head_(nullptr), tail_(nullptr), count_(0) {}
    ~List() {
        Node<T>* cur = head_;
        while (cur) {
            Node<T>* nxt = cur->next();
            delete cur;
            cur = nxt;
        }
    }

    bool empty() const { return head_ == nullptr; }
    size_t size() const { return count_; }

    // return pointer to head node (for iteration)
    Node<T>* head() const { return head_; }
    Node<T>* tail() const { return tail_; }

    void push_back(const T& item) {
        Node<T>* n = new Node<T>(item, nullptr);
        if (!head_) {
            head_ = tail_ = n;
        } else {
            tail_->set_next(n);
            tail_ = n;
        }
        ++count_;
    }

    // remove first occurrence of item (compares by pointer or operator==)
    bool erase(const T& item) {
        Node<T>* cur = head_;
        Node<T>* prev = nullptr;
        while (cur) {
            if (cur->retrieve() == item) {
                if (prev) prev->set_next(cur->next());
                else head_ = cur->next();
                if (cur == tail_) tail_ = prev;
                delete cur;
                --count_;
                return true;
            }
            prev = cur;
            cur = cur->next();
        }
        return false;
    }

    // get element at index (1-based as in some textbook code) -> we'll provide 1-based and 0-based helper
    T get_at_1based(int idx) const {
        assert(idx >= 1 && idx <= (int)count_ && "Index out of range in List::get_at_1based");
        Node<T>* cur = head_;
        int i = 1;
        while (cur && i < idx) {
            cur = cur->next();
            ++i;
        }
        return cur->retrieve();
    }
};

// ---------------------------
// Simple Queue (templated) - using singly linked nodes
// ---------------------------
template<typename T>
class SimpleQueue {
private:
    Node<T>* front_;
    Node<T>* back_;
    size_t count_;
public:
    SimpleQueue() : front_(nullptr), back_(nullptr), count_(0) {}
    ~SimpleQueue() {
        while (front_) {
            Node<T>* tmp = front_->next();
            delete front_;
            front_ = tmp;
        }
    }
    bool empty() const { return front_ == nullptr; }
    size_t size() const { return count_; }
    void push(const T& item) {
        Node<T>* n = new Node<T>(item, nullptr);
        if (!back_) front_ = back_ = n;
        else {
            back_->set_next(n);
            back_ = n;
        }
        ++count_;
    }
    // pop returns the item (and removes it)
    T pop() {
        assert(front_ && "pop on empty queue");
        T val = front_->retrieve();
        Node<T>* tmp = front_;
        front_ = front_->next();
        if (!front_) back_ = nullptr;
        delete tmp;
        --count_;
        return val;
    }
    // peek front
    T& front() {
        assert(front_ && "front on empty queue");
        return front_->retrieve_ref();
    }
};

// ---------------------------
// Simple_tree class (templated)
// ---------------------------
template<typename Type>
class Simple_tree {
private:
    Type element;
    Simple_tree<Type>* parent_node;
    List<Simple_tree<Type>*> children;

public:
    // constructor (default element value, parent default nullptr)
    Simple_tree(const Type& obj = Type(), Simple_tree<Type>* p = nullptr)
        : element(obj), parent_node(p) {
    }

    // Retrieve element
    Type retrieve() const {
        return element;
    }

    // parent
    Simple_tree<Type>* parent() const {
        return parent_node;
    }

    // child (1-based index in textbook; code uses 1..degree)
    Simple_tree<Type>* child(int n) const {
        if (n < 1 || n > (int)degree()) {
            return nullptr;
        }
        // List stores Simple_tree<Type>* and provides get_at_1based
        return children.get_at_1based(n);
    }

    // degree (number of children)
    int degree() const {
        return (int)children.size();
    }

    // is_root
    bool is_root() const {
        return (parent_node == nullptr);
    }

    // is_leaf
    bool is_leaf() const {
        return (degree() == 0);
    }

    // insert (create new child with obj)
    void insert(const Type& obj) {
        Simple_tree<Type>* ch = new Simple_tree<Type>(obj, this);
        children.push_back(ch);
    }

    // attach an existing subtree (must become child of this)
    void attach(Simple_tree<Type>* tree) {
        if (!tree) return;
        if (!tree->is_root()) {
            tree->detach();
        }
        tree->parent_node = this;
        children.push_back(tree);
    }

    // detach this node from its parent
    void detach() {
        if (is_root()) {
            return;
        }
        Simple_tree<Type>* p = parent();
        // remove this from parent's children list
        if (p) {
            p->children.erase(const_cast<Simple_tree<Type>*>(this));
        }
        parent_node = nullptr;
    }

    // size: number of nodes in subtree rooted at this node
    int size() const {
        int s = 1;
        for (Node<Simple_tree<Type>*>* ptr = children.head(); ptr != nullptr; ptr = ptr->next()) {
            Simple_tree<Type>* childPtr = ptr->retrieve();
            s += childPtr->size();
        }
        return s;
    }

    // height: longest distance (edges) to a leaf. leaf -> 0
    int height() const {
        if (is_leaf()) return 0;
        int h = 0;
        for (Node<Simple_tree<Type>*>* ptr = children.head(); ptr != nullptr; ptr = ptr->next()) {
            Simple_tree<Type>* childPtr = ptr->retrieve();
            h = max(h, 1 + childPtr->height());
        }
        return h;
    }

    // depth-first traversal (preorder)
    void depth_first_traversal() const {
        cout << retrieve() << "\t";
        for (Node<Simple_tree<Type>*>* ptr = children.head(); ptr != nullptr; ptr = ptr->next()) {
            Simple_tree<Type>* childPtr = ptr->retrieve();
            childPtr->depth_first_traversal();
        }
    }

    // breadth-first traversal (uses SimpleQueue)
    void breadth_first_traversal() {
        SimpleQueue<Simple_tree<Type>*> q;
        q.push(const_cast<Simple_tree<Type>*>(this));
        while (!q.empty()) {
            Simple_tree<Type>* p = q.pop();
            cout << p->retrieve() << "\t";
            for (Node<Simple_tree<Type>*>* ptr = p->children.head(); ptr != nullptr; ptr = ptr->next()) {
                q.push(ptr->retrieve());
            }
        }
    }

    // destructor: delete children recursively
    ~Simple_tree() {
        for (Node<Simple_tree<Type>*>* ptr = children.head(); ptr != nullptr; ptr = ptr->next()) {
            delete ptr->retrieve();
        }
    }
};

// ---------------------------
// Example usage (main)
// ---------------------------
int main() {
    // Example: build small tree
    Simple_tree<string>* root = new Simple_tree<string>("ROOT");

    // insert children
    root->insert("A");
    root->insert("B");
    root->insert("C");

    // add grandchildren to A (child 1)
    Simple_tree<string>* a = root->child(1);
    if (a) {
        a->insert("A1");
        a->insert("A2");
    }

    // add child to B (child 2)
    Simple_tree<string>* b = root->child(2);
    if (b) {
        b->insert("B1");
    }

    cout << "Root element: " << root->retrieve() << "\n";
    cout << "Size of tree: " << root->size() << "\n";
    cout << "Height of tree: " << root->height() << "\n\n";

    cout << "DFS (preorder):\n";
    root->depth_first_traversal();
    cout << "\n\n";

    cout << "BFS:\n";
    root->breadth_first_traversal();
    cout << "\n\n";

    delete root;
    return 0;
}
