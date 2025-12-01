#include<iostream>
using namespace std;
class Node {
private:
	int data;
	Node* next;
public:
	Node(int d) {
		data = d;
		next = nullptr;
	}
	int retrieve() {
		return data;
	}
	friend class Queue;
};
class Queue {
private:
	Node* tail;
	Node* head;
public:
	Queue() {
		tail = head = nullptr;
	}
	bool empty() {
		return head == nullptr;
	}
	int peek() {
		return head->retrieve();
	}
	void PopFront() {
		if (empty()) {
			cout << "Empty Queue...";
			return;
		}
		Node* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;

		if (head == nullptr) {
			tail = nullptr;
		}
	}
	void PushEnd(int d) {
		Node* n = new Node(d);
		if (empty()) {
			head = tail = n;
			return;
		}

		if (tail->next == nullptr) {
			tail->next = n;
			tail = n;
		}
	}
	void	display() {
		if (empty()) {
			cout << endl << "Queue Empty";
			return;
		}

		Node* temp;
		for (temp = head;temp != nullptr;temp = temp->next) {
			cout << temp->retrieve() << " ->";
		}cout << " Null " << endl;

	}
};
int main() {
	Queue q;
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
	cout << "Top Element is: " << q.peek();
	q.PopFront();
	q.display();
	return 0;
}