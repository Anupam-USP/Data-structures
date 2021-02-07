// Circular Queue implementation
#include <iostream>
using namespace std;

class CQueue{
private:
    int size, front, rear;
    int *Q;
public:
    CQueue(){
        front = rear = 0;
        size=10;
        Q=new int[size];
    }

    CQueue(int size){
        front = rear = 0;
        this->size = size;
        Q=new int[this->size];
    }

    void Enqueue(int x);
    int Dequeue();
    void Display();
};

void Queue::Enqueue(int x){
    if(((rear+1)%size)==front) cout<<"Queue full"<<endl;
    else{
        rear=(rear+1)%size;
        Q[rear]=x;
    }
}

int Queue::Dequeue(){
    int x=-1;
    if(front==rear) cout<<"Queue empty"<<endl;
    else{
        front=(front+1)%size;
        x=Q[front];
    }
    return x;
}

void Queue::Display(){
    int i=front+1;
    do{
        cout<<Q[i]<<" -> ";
    }while(i!=(rear+1)%size);
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