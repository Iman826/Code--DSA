#include<iostream>
using namespace std;

//Insertion At Front
void InsertAtBeginning(int* arr, int a) {
	cout << "Original array: "<<endl;
	for (int i = 0;i < 5;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	int n = 5;

	for (int i = 0;i <= 4;i++) {
		arr[n] = arr[n - 1];
		n--;
	}
	arr[0] = 9;
	int head = arr[0];
	int tail = arr[4];
	cout << "Insertion At Beginning:\nhead: " << head << endl;
	cout << "tail: " << tail << endl;
	for (int i = 0;i < 5;i++) {
		cout << arr[i] << " ";
	}cout << endl << endl;

}
//Insertion At End
void InsertAtEnd(int* arr, int a) {
	for (int j = 4;j >= 0;j--) {
		arr[4] = a;

	}cout << endl;

	int head = arr[0];
	int tail = arr[4];
	cout << "Insertion At End :\nhead: " << head << endl;
	cout << "tail: " << tail << endl;
	for (int i = 0;i < 5;i++) {
		cout << arr[i] << " ";
	}cout << endl << endl;
}
//Insertion At Mid
void InsertAtMid(int* arr, int a, int i) {
	int n = 5;
	for (int j = 0;j <= i;j++) {
		arr[n] = arr[n - 1];
		n--;
	}arr[2] = a;
	int head = arr[0];
	int tail = arr[4];
	cout << "Insertion At Mid :\nhead: " << head << endl;
	cout << "tail: " << tail << endl;
	for (int k = 0;k < 5;k++) {
		cout << arr[k] << " ";
	}cout << endl << endl;
}
//Deletion At Front
void DeleteAtBeginning(int* arr) {
	for (int i = 0;i < 5;i++) {
		arr[i] = arr[i + 1];
	}
	int head = arr[0];
	int tail = arr[4];
	cout << "Deletion at Beginning :\nhead: " << head << endl;
	cout << "tail: " << tail << endl;
	for (int k = 0;k < 5;k++) {
		cout << arr[k] << " ";
	}cout << endl << endl;
}//Deletion At End
void DeletionAtEnd(int arr[]) {
	arr[4] = 0;
	
	int head = arr[0];
	int tail = arr[4];
	cout << "Deletion at End :\nhead: " << head << endl;
	cout << "tail: " << tail << endl;
	for (int k = 0;k < 5;k++) {
		cout << arr[k] << " ";
	}cout << endl << endl;
}//Deletion At Mid
void DeletionAtMid(int arr[], int n) {
	for (int i = 0; i < 5; i++) {
		arr[n] = arr[n + 1];
		n++;
	}
	arr[4] = 0;
	int head = arr[0];
	int tail = arr[4];
	cout << "Deletion at Mid :\nhead: " << head << endl;
	cout << "tail: " << tail << endl;
	for (int k = 0;k < 5;k++) {
		cout << arr[k] << " ";
	}cout << endl << endl;

}
int main() {

	int arr[5] = { 10,12,13,14,15 };
	//Insertion
	InsertAtBeginning(arr, 9);
	InsertAtEnd(arr, 18);
	InsertAtMid(arr, 15, 2);
	//Deletion At Front
	DeleteAtBeginning(arr);
	//Deletion At End
	DeletionAtEnd(arr);
	//Deletion At Mid
	DeletionAtMid(arr, 1);
	return 0;
}