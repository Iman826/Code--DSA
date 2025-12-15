#include<iostream>
using namespace std;
template<typename T>
class Node{
  private:
  T data;
  Node<T>* next;
  public:
  Node(T d,Node<T>*n=nullptr){data=d;
  next=n;}
  T retrieve(){
    return data;
  }
  T& retrieveReference(){
    return data;
  }
  Node<T>* retrieveNext(){
    return next;
  }
  void setNext(Node<T>* n){
    this->next=n;
  }
 template<typename U> friend class List;
  template<typename U> friend class Tree;
  template<typename U> friend class Queue;
  
};

template<typename T>
class List{
  private:
  Node<T>* head;
  public:
  List(Node<T>*h=nullptr){
    head=h;
  }
  bool empty(){
    return head==nullptr;
  }
  void display(){
    for(Node<T>* temp=head;temp!=nullptr;temp=temp->next){
      cout<<temp->retrieve()<<" -> ";
    }cout<<" Null"<<endl;
  }
  void push_back(T d){
      Node<T>*  newNode=new Node<T>(d);
  if(head==nullptr){
    head=newNode;
    return;
  }
  Node<T>* p;
  for( p=head;p->next!=nullptr;p=p->next){
  }
  p->next=newNode;
  
  }
  void push_Front(T d){
  Node<T>*  newNode=new Node<T>(d);
  if(head==nullptr){
    head=newNode;
    return;
  }
  newNode->next=head;
  head=newNode;
  }
  void Erase(T d) {

    // Case 1: Delete as long as head contains d
    while(head!=nullptr&& head->retrieve()==d){
      Node<T>* temp=head;
      head=head->next;
      temp->next=nullptr;
      delete temp;
      }
    // If list empty after removing head occurrences
    if (head == nullptr)
        return;
    // Case 2: Delete from remaining list (middle + last)
    Node<T>* prev = head;
    Node<T>* curr = head->next;
    for(curr;curr!=nullptr;){
     if(curr->retrieve()==d){
      prev->next=curr->next;
      curr->next=nullptr;
      delete curr;
      curr=prev->next;}
      else{
      prev=curr;
      curr=curr->next;}
      }}
     Node<T>* Head() { return head; }
    template<typename Y> friend class Queue;
};template<typename T>
class Queue {
private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

public:
    bool empty() { return head == nullptr; }

    void push(T d) {
        Node<T>* n = new Node<T>(d);
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    void pop() {
        if (!head) return;
        Node<T>* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
    }

    T& front() {
        return head->data;
    }
};

template<typename T>
class Tree{
  private:
  T data;
  Tree<T>* parent;
  List<Tree<T>*>*children;//list of tree type children
  public:
  Tree(T d,Tree<T>* p=nullptr){
    data=d;
    parent=p;
    children= new List<Tree<T>*>();}
   
  void AddChild(T value){
   Tree<T>* newNode=new Tree<T>(value,this);//janam diya aur ungli pakra di parent ki
   //parent ki children wali list mein daal do 
   children->push_back(newNode);  }
   void display(){
     cout<<this->data;
     for(Node<Tree<T>*>* temp=children->Head();temp!=nullptr;temp=temp->next){
      cout<<temp->retrieve()->data<<" ";
   }
   cout<<endl;}
  bool is_root() const { return parent == nullptr; }
  bool is_leaf() const { return children->Head() == nullptr; }
   int degree() const {
    int d = 0;
    for(Node<Tree<T>*>* p = children->Head(); p != nullptr; p = p->retrieveNext()) d++;
    return d;
}
int height() const {
    if(children->Head() == nullptr) return 0; // leaf node
    int h = 0;
    for(Node<Tree<T>*>* p = children->Head(); p != nullptr; p = p->retrieveNext()){
        h = max(h, 1 + p->retrieve()->height());
    }
    return h;
}

   int size(){
     int s=1;
     for(Node<Tree<T>*>*p=children->Head();p!=nullptr;p=p->retrieveNext()){
       s+=p->retrieve()->size();
       }
       return s;
   }
   void Detach(){
   if(parent==nullptr){return;}
   
    parent->children->Erase(this);
    this->parent=nullptr;
    
   }
   void attach(Tree<T>* subtree){
     if(subtree==nullptr){return;}
    if(subtree->parent!=nullptr){
      subtree->Detach();
    }
    
     subtree->parent=this;
     this->children->push_Front(subtree);
   }
  void DFS(){
  cout<<this->data<<" ";
  for(Node<Tree<T>*>*p=children->Head();p!=nullptr;p=p->retrieveNext()){
       p->retrieve()->DFS();
       }
  }
  void BFS(){
      Queue<Tree<T>*> q;
      q.push(this);
      while(!q.empty()){
         Tree<T>*Parent =q.front();
         cout<<Parent->data<<" ";
         q.pop();
         for(Node<Tree<T>*>*p=Parent->children->Head();p!=nullptr;p=p->retrieveNext()){
         q.push(p->retrieve());
       }
      }
  }
  ~Tree(){
       delete children;
  }
};
int main() {
Tree<string> T("Iman");
Tree<string> T1("Fatima");
T.display();
T.AddChild("I");
T.AddChild("MANI");
T1.AddChild("Pretty");
T1.AddChild("Lady");
T.display();
T.attach(&T1);
cout<<"size:"<<T.size()<<endl;
cout<<"Height:"<<T.height()<<endl;
T.display();
T.DFS();
cout<<endl;
T.BFS();

  return 0;
}
