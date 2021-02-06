// Paranthesis matching
#include <iostream>
using namespace std;

class Node{
public:
    char data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){top=0;}
    void push(char x);
    char pop();
    void Display();
    int isBaln(char *exp);
};

void Stack::push(char x){
    Node *t = new Node;
    if(t==0) cout<<"Stack is Full"<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

char Stack::pop(){
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

int Stack::isBaln(char *exp){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(')
            push(exp[i]);
        else if(exp[i]==')'){
            if(top==0) return 0;
            pop();
        }
    }
    if(top==0) return 1;
    else return 0;
}

int main(){
    char *exp="((a+b)*(c+d))";
    Stack st;
    cout<<st.isBaln(exp);
    return 0;
}
