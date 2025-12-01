#include <iostream>
#include <forward_list>
#include <algorithm>
using namespace std;

class SinglyLst {
private:
    forward_list<int> f;

public:
//empty
    bool empty() { return f.empty(); }


//size
    int size() {
        int count = 0;
        for (int x : f) count++;
        return count;
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
        if (f.empty()) {
            f.push_front(val);
            return;
        }
        auto it = f.begin();
        while (next(it) != f.end()) it++;
        f.insert_after(it, val);
    }


//pop front
    void pop_front() {
        if (!f.empty())
            f.pop_front();
        else
            cout << "List is empty!\n";
    }

//pop back
    void pop_back() {
        if (f.empty()) {
            cout << "List is empty!\n";
            return;
        }
        auto it = f.before_begin();
        auto curr = f.begin();
        auto next_it = next(curr);

        if (next_it == f.end()) { // only one element
            f.pop_front();
            return;
        }

        while (next(next_it) != f.end()) {
            it = curr;
            curr = next_it;
            next_it = next(next_it);
        }
        f.erase_after(curr);
    }


//Middle Insertion
    void InsertAtMid(int val) {
        int n = size();
        int mid = n / 2;
        auto it = f.before_begin();
        for (int i = 0; i < mid; i++) it = next(it);
        f.insert_after(it, val);
    }


//Erase 
    void EraseFirst(int val) {
        auto it = f.before_begin();
        for (auto curr = f.begin(); curr != f.end(); curr++) {
            if (*curr == val) {
                f.erase_after(it);
                return;
            }
            it = curr;
        }
    }
};

int main() {
    SinglyLst sl;

    sl.push_front(2);
    sl.push_back(8);
    sl.InsertAtMid(34);
    sl.push_back(24);

    cout << "After insertion: ";
    sl.display();  // 2 34 8 24

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
