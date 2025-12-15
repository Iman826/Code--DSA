#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
class BinaryNode{
  private:
  T data;
  BinaryNode<T>* left;
  BinaryNode<T>* right;
  public:
  BinaryNode(T d){
    data=d;
    left=nullptr;
    right=nullptr;
  }
  void setLeft(BinaryNode<T>* l){
    left=l;}
  void setRight(BinaryNode<T>* r){
    right=r;}
  T value() const{
    return data;
  }
  BinaryNode<T>* RetrieveLeft(){
    return left;
  }
  BinaryNode<T>* RetrieveRight(){
    return right;
  }
  bool isLeaf() const {
    return (left==nullptr)&&(right==nullptr);
  }
 
  int size(){
    int L=(left!=nullptr)? RetrieveLeft()->size():0;
    int R=(right!=nullptr)? RetrieveRight()->size():0;
    return 1+L+R;
    
  }
  int Height(){
    //Leaf Height Starts From zero 
    if(isLeaf()){return 0;}
    int L=(left!=nullptr)? RetrieveLeft()->Height():0;
    int R=(right!=nullptr)? RetrieveRight()->Height():0;
    return 1+max(L,R);
    
  }
  void clear(BinaryNode<T>* parent){
    if (left != nullptr) left->clear(this);
    if (right!= nullptr) right->clear(this);
    if(parent){
    if(parent->left==this){
        parent->left=nullptr;
    }
     else if(parent->right==this){
     
       parent->right=nullptr;
    }
        
    }
        delete this;
    
    }
    void Inorder(){
        if(this==nullptr){return;}
        left->Inorder();
        cout<<this->data<<" ";
        right->Inorder();
    }
    void PreOrder(){
        //Root left Right
        if(this==nullptr){return;}
        cout<<this->data<<" ";
        left->PreOrder();
        
        right->PreOrder();
    }
    void PostOrder(){
        //left right root
        if(this==nullptr){return;}
        left->PostOrder();
        right->PostOrder();
         cout<<this->data<<" ";
    }
};
int main(){
  BinaryNode<string>* A=new BinaryNode<string>("A");
  BinaryNode<string>* B=new BinaryNode<string>("B");
  BinaryNode<string>* C=new BinaryNode<string>("C");
  BinaryNode<string>* D=new BinaryNode<string>("D");
  A->setLeft(B);
  A->setRight(C);
  C->setRight(D);
  cout<<"Size: "<<A->size()<<endl;
  cout<<"Height: "<<A->Height()<<endl;
//   B->clear(A);
  cout<<"Size: "<<A->size()<<endl;
  cout<<"Height: "<<A->Height()<<endl;
  cout<<"In order: ";
  A->Inorder();
    cout<<endl;
  cout<<"Pre order: ";
  A->PreOrder();
  cout<<endl;
   cout<<"Post order: ";
   A->PostOrder();
   cout<<endl;
  return 0;
}
