#include<iostream>
using namespace std;
class Queue {
private:
    int arr[5];
    int front;
    int rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }
    bool Empty() {
        return rear < front;
    }
    bool full() {
        return rear == 4;
    }
    void PushEnd(int d) {
        if (full()) {
            cout << "Full hai ";
            return;
        }
        rear++;
        arr[rear] = d;

    }
    int PopFront() {
        if (Empty()) {
            cout << "Empty hai";
            return -1;
        }
        int value = arr[front];
        front++;
        return value;
    }
    void display() {
        if (full()) {
            cout << "Queue full";
        }
        for (int i = front;i <= rear;i++) {
            cout << arr[i];
        }
    }

};
int main() {
    Queue q;
    q.PushEnd(23);
    q.display();
    q.PopFront();
    q.PopFront();
    return 0;
}