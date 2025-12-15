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
  void clear(){
    if (leftNode != nullptr) leftNode->clear();
        if (rightNode != nullptr) rightNode->clear();
        if (parentNode) {
            if (parentNode->getLeft() == this) { 
                parentNode->setLeft(nullptr);
            }
            else if (parentNode->getRight() == this) {
                parentNode->setRight(nullptr);
            }
        }
        delete this;
    }
};
int main(){
  BinaryNode<string>* A=new BinaryNode<string>("A");
  BinaryNode<string>* B=new BinaryNode<string>("B");
  BinaryNode<string>* C=new BinaryNode<string>("C");
  A->setLeft(B);
  A->setRight(C);
  cout<<A->size();
  cout<<A->Height();
  B->clear();
  return 0;
}
