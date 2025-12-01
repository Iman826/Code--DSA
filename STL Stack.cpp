#include<iostream>
#include<stack>  
using namespace std;
class Stack{
  private:
  stack<int> s;
  public:
//push
  void push(int d){
    s.push(d);
  }
//pop
  void pop(){
    if(!s.empty()){
      s.pop();
    }}

//empty
  bool empty(){
    return s.empty();
  }

//front
  int top(){
    if(!empty()){
      return s.top();
    }
    else{
      return -1;
    }
  }   

//size
  int size(){
    return s.size();
  }

//display
  void display(){
    if(s.empty()){
      cout<<"Empty Stack";
    }
    stack<int>temp=s;
    while(!temp.empty()){
      cout<<temp.top();
      temp.pop();
    }
    cout << endl;
  }
};
int main() {
  Stack q;
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.pop();
  q.display();
  q.size();
  q.top();
  return 0;
}
