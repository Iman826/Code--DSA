#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
class BinarySearchNode{
  private:
  T data;
  BinarySearchNode<T>* left;
  BinarySearchNode<T>* right;
  public:
  BinarySearchNode(T d,BinarySearchNode<T>* l=nullptr, BinarySearchNode<T>* r=nullptr){
    data=d;
    left=l;
    right=r;
  }
  T retrieve(){
    return data;
  }
  void setData(T d){
    data=d;
  }
   BinarySearchNode<T>* Left(){
     return left;
   }
   BinarySearchNode<T>* Right(){
     return right;
   }
   void setleft(BinarySearchNode<T>* l){
     left=l;
   }
   void setright(BinarySearchNode<T>* r){
     right=r;}
    int size(){
      if(left==nullptr && right==nullptr){
        return 1;
      }
     int leftSize=(left!=nullptr)? left->size():0;
     int rightSize=(right!=nullptr)? right->size():0;
     return 1+leftSize+rightSize;
    }
    bool empty(){
    return this==nullptr;}
    bool isleaf(){
      return left==nullptr&& right==nullptr;
    }
    int Height(){
      if(left==nullptr && right==nullptr){
        return 0;
      }
      int leftHeight=(left!=nullptr)? left->Height():0;
      int RightHeight=(right!=nullptr)? right->Height():0;
      return 1+ max(leftHeight,RightHeight);
    }
   bool Insert(T d,BinarySearchNode<T>*& ptr){ //reference so that not only the local copy is changed but the original data
     if(ptr==nullptr){
       ptr=new BinarySearchNode<T> (d); //jis ne call kiya hai us ki apni koi value assign nahi thi wo ker di 
       return true;
     }
     else{
       if(d<ptr->data){
        return Insert(d,ptr->left);
       }
       else if(d>ptr->data){
          return Insert(d,ptr->right);
       }
       else{
         return false; //duplicates ke liye kuch bhi nahi kerna 
       }
     }
   }
   bool find(T d){
     if(d==data){
       return true;
     }
     else if(d<data)
     {
       if(left!=nullptr){
         return left->find(d);}
         else{
           return false;
         }
     }
     else{
       if(right!=nullptr){
      return right->find(d);}
       else{
         return false;
       }
     }
     
   }
   T front() const{     //read only hai 
     if(left==nullptr){ // mazeed koi left exist nahi kerta tu left ki value mil jayegi
       return data;     // current node ka data return 
     }
     else{
     return  left->front(); //abhi left ka left exist kerta hai tu us ko call ker do
   }}
   T back() const{
     if(right==nullptr){
       return data;// current node ka data return 
     }
     else{
       return right->back();}
   }
   bool erase(T &obj,BinarySearchNode<T>*& ptr) {
    if (ptr == nullptr) return false;

    if (obj < data)
        return left->erase(obj, left);
    else if (obj > data)
        return right->erase(obj, right);
    else {
        if (is_leaf()) {
            delete this;
            ptr = nullptr;
        } else if (left && right) {
            data = right->front();
            right->erase(data, right);
        } else {
           BinarySearchNode<T>* child =
                (left) ? left : right;
            delete this;
            ptr = child;
        }
        return true;
    }
    }
};

int main(){
  BinarySearchNode<int>* Tree1=new BinarySearchNode<int>(20);

  Tree1->Insert(30,Tree1);
  Tree1->Insert(10,Tree1);
  Tree1->Insert(40,Tree1);
  Tree1->find(30);
  cout<<"MAXIMUM VALUE: "<<Tree1->back();
  cout<<endl;
  cout<<"MINIMUM VALUE: "<<Tree1->front();
  Tree1->erase(30);
  return 0;
}
