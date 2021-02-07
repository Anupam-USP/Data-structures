// Using linked list
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class Queue{
private:
    Node *front=0, *rear=0;
public:
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x){
    Node *t=new Node;
    if(t==0) cout<<"Queue full\n";
    else{
        t->data=x;
        t->next=0;
        if(front==0) front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int Queue::dequeue(){
    int x=-1;
    Node *t= new Node;
    if(front==0) cout<<"Queue empty"<<endl;
    else{
        x=front->data;
        t=front;
        front=front->next;
        delete t;
    }
    return x;
}

void Queue::Display(){
    Node *p=front;
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.Display();
    cout<<q.dequeue();
    return 0;
}