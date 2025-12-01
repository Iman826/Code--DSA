#include<iostream>
using namespace std;
class Stack {
private:
	int arr[5];
	int top;
public:
	Stack() {
		top = -1;
	}
	//Empty funtion
	bool isEmpty() {
		return top == -1;
	}
	//Full 
	bool isFull() {
		return top == 4;
	}
	//pop function
	void pop() {
		if (isEmpty()) {
			cout << "Stack Underflow";
			return;
		}
		top--;
	}
	//push function
	void push(int d) {
		if (isFull()) {
			cout << "Stack OverFlow";
			return;

		}
		arr[++top] = d;
	}
	//peek Fucntion
	int Peek() {
		if (isEmpty()) {
			throw underflow_error("Stack Empty");
		}
		return arr[top];
	}
	//Display
	void Display() {
		if (isEmpty()) {
			cout << "Stack Empty";
			return;
		}
		for (int i = top;i >= 0;i--) {
			cout << arr[i] << endl;

		}cout << endl;
	}
};
int main() {
	Stack k;
	try {
		k.push(23);
		k.push(12);
		k.Display();
		k.pop();
		k.Display();
	}
	catch (exception &e) {
		cout << e.what()<<endl;
	}
	return 0;
}