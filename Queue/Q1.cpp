// Queue implementation
#include <iostream>
using namespace std;

class Queue{
private:
    int size, front, rear;
    int *Q;
public:
    Queue(){
        front = rear = -1;
        size=10;
        Q=new int[size];
    }

    Queue(int size){
        front = rear = -1;
        this->size = size;
        Q=new int[this->size];
    }

    void Enqueue(int x);
    int Dequeue();
    void Display();
};

void Queue::Enqueue(int x){
    if(rear==size-1) cout<<"Queue full"<<endl;
    else{
        rear++;
        Q[rear]=x;
    }
}

int Queue::Dequeue(){
    int x=-1;
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

int main(){
    Queue q(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Display();
    cout<<q.Dequeue()<<endl;
    q.Display();
    return 0;
}