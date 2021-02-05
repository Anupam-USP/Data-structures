// Using linked list
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top=0;}
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x){
    Node *t = new Node;
    if(t==0) cout<<"Stack is Full"<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack::pop(){
    int x=-1;
    if(top==0) cout<<"Stack is empty"<<endl;
    else{
        x=top->data;
        Node *temp = top;
        top=top->next;
        delete temp;
    }
    return x;
}

void Stack::Display(){
    Node *p=top;
    while (p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();
    cout<<st.pop()<<endl;
    st.Display();
    return 0;
}