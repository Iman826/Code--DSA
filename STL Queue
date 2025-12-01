#include<iostream>
#include<queue>  
using namespace std;

class Queue {
private:
    queue<int> q;

public:
 // enqueue
    void push(int d){ 
        q.push(d);
    }

 // dequeue
    void pop(){           
        if(!q.empty()){
            q.pop();
        }
    }
//empty
    bool empty(){
        return q.empty();
    }

//front
    int front(){         
        if(!empty()){
            return q.front();
        }
        else{
            return -1;
        }
    }

//size
    int size(){
        return q.size();
    }


//display
    void display(){
        if(q.empty()){
            cout << "Empty Queue";
            return;
        }

        queue<int> temp = q;
        while(!temp.empty()){
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    q.display();   // shows: 3 4 5

    cout << "Size = " << q.size() << endl;
    cout << "Front = " << q.front() << endl;

    return 0;
}
