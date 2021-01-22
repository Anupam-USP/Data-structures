// Search, insert and delete
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=0;

void Create(int A[],int n){
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next=0;
    last = first;

    for(int i=1;i<n;i++){
        t = new Node;
        t->data = A[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}

void Display(Node *p){
    while(p!=0){
        cout<<p->data<<" -> ";
        p=p->next;
    }
}

int count(Node *p){
    int c=0;
    while (p){
        c++;
        p=p->next;
    }
    return c;
}

Node *LSearch(Node *p, int key){
    while(p){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return 0;
}

Node *LSearch1(Node *p, int key){
    // With move to front
    Node *q;
    while(p){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return 0;
}

void Insert(Node *p, int idx, int x){
    if(idx<0 || idx>count(p))
        return;
    else{
        Node *t;
        t=new Node;
        t->data=x;
        if(idx==0){
            t->next=first;
            first=t;
        }
        else{
            for(int i=0;i<idx-1;i++){
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
        }
    }
}

int main(){
    Node *temp;
    int A[] = {2,6,8,10,14};
    Create(A,5);
    Display(first);
    cout<<endl;
    // temp=LSearch(first,8);
    // if(temp){
    //     cout<<"Key found "<<temp->data<<endl;}
    // else
    //     cout<<"Key not found"<<endl;
    Insert(first,2,54);
    Display(first);
    return 0;
}