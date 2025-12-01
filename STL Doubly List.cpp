#include <iostream>
#include <list>
using namespace std;

class DoublyLst {
private:
    list<int> f;   // std::list = doubly linked list

public:
//empty
    bool empty() { return f.empty(); }

//size
    int size() {
        return f.size();  // list has direct size()
    }


//display
    void display() {
        if (f.empty()) {
            cout << "List is empty!\n";
            return;
        }
        for (int x : f) cout << x << " ";
        cout << endl;
    }

//push front
    void push_front(int val) {
        f.push_front(val);
    }

//push back
    void push_back(int val) {
        f.push_back(val);
    }
//pop front
    void pop_front() {
        if (!f.empty())
            f.pop_front();
        else
            cout << "List is empty!\n";
    }
//pop Back
    void pop_back() {
        if (!f.empty())
            f.pop_back();
        else
            cout << "List is empty!\n";
    }

//Misddle Insertions
    void InsertAtMid(int val) {
        int n = size();
        int mid = n / 2;

        auto it = f.begin();
        for (int i = 0; i < mid; i++) it++;  // move to middle

        f.insert(it, val); // insert BEFORE mid (same effect as your forward_list)
    }

//Erase First Instance
    void EraseFirst(int val) {
        for (auto it = f.begin(); it != f.end(); it++) {
            if (*it == val) {
                f.erase(it);
                return;
            }
        }
    }
};

int main() {
    DoublyLst dl;

    dl.push_front(2);
    dl.push_back(8);
    dl.InsertAtMid(34);
    dl.push_back(24);

    cout << "After insertion: ";
    dl.display();   // 2 34 8 24

    dl.pop_front();
    dl.pop_back();

    cout << "After pop front & back: ";
    dl.display();   // 34 8

    dl.EraseFirst(8);
    cout << "After erasing 8: ";
    dl.display();   // 34

    cout << "Size: " << dl.size() << endl;  // 1

    return 0;
}
