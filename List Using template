// Online C++ compiler to run C++ program online
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
    T retrieve(){
     return data;
    }
    template<typename U>friend class List;
};
template<typename T>
class List{
    private:
    Node<T>* head ;
   
    public:
    List(){
        head=nullptr;
    }
    bool Empty(){
        return head==nullptr;
    }
    void push_front(T d){
        Node<T>* n=new Node(d);
        if(head==nullptr){
            head=n;
            return;
        }
        n->next=head;
        head=n;
       
        
    }
    void push_back(T d){
    Node<T>*n=new Node(d);
    if(Empty()){
        head=n;
        return;
    }
    Node<T>*temp;
    for(temp=head;temp->next!=nullptr;temp=temp->next){
        
    }temp->next=n;
    
    }
    void pop_back(){
        if(Empty()){
            cout<<"Khali hai List";
            return;
        }
        Node<T>*temp;
        for(temp=head;temp->next->next!=nullptr;temp=temp->next){
            
        }
        delete temp->next;
        temp->next=nullptr;
        
        
    }
    void pop_front(){
        if(Empty()){
            cout<<"Khali hai List";
            return;
        }
        Node<T>*temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
    }
   void Erase(T d) {
    if (head == nullptr) {
        cout << "Empty List";
        return;
    }

    // ---- Case 1: head node contains d ----
    if (head->data == d) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // ---- Case 2: search for d in rest of list ----
    Node<T>* curr = head;
    Node<T>* prev = nullptr;

    while (curr != nullptr && curr->data != d) {
        prev = curr;
        curr = curr->next;
    }

    // ---- Case 3: value not found ----
    if (curr == nullptr) {
        cout << "Value not found";
        return;
    }

    // ---- Case 4: match found => delete ----
    prev->next = curr->next;
    delete curr;
}
    void display(){
       Node<T>* temp=head;
       while(temp!=nullptr){
           
        cout<<temp->retrieve()<<" ";
           temp=temp->next;
       }
    }
     
};
int main() {
   List<int> L;
   L.Empty();
  
   L.push_back(2);
   L.push_back(3);
   L.push_back(5);
    L.push_back(3);
    L.push_back(3);
     L.push_back(3);
     L.push_back(3);
    L.display();
    cout<<endl;
   L.pop_back();
   L.pop_front();
    L.display();
    cout<<endl;
   L.Erase(3);
   L.display();
    return 0;
}
