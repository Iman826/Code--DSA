#include <iostream>
using namespace std;
template<typename T>
class Node{
    private:
    T data;
    Node* next;
    public:
    Node(T d){
    data=d;
    next=nullptr;
    }
    int retrieve(){
     return data;
    }
};
int main() {
    Node<int>n(23);
    cout<<n.retrieve();
    return 0;
}
