
#ifndef Queuecpp_h
#define Queuecpp_h
using namespace std;

class Node{
public:
    int data;
    Node *lchild, *rchild;
};

class Queue{
private:
    int size, front, rear;
    Node **Q;
public:
    Queue(){
        front = rear = -1;
        size=10;
        Q=new Node*[size];
    }

    Queue(int size){
        front = rear = -1;
        this->size = size;
        Q=new Node*[this->size];
    }

    void Enqueue(Node *x);
    Node* Dequeue();
    void Display();
    int isEmpty(){return front==rear;}
};

void Queue::Enqueue(Node *x){
    if(rear==size-1) cout<<"Queue full"<<endl;
    else{
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::Dequeue(){
    Node *x=nullptr;
    if(front==rear) cout<<"Queue empty"<<endl;
    else{
        x=Q[front+1];
        front++;
    }
    return x;
}

void Queue::Display(){
    for(int i=front+1;i<=rear;i++)
        cout<<Q[i]<<" -> ";
    cout<<endl;
}

#endif