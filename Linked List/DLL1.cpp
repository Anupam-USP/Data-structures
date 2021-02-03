// Insert, delete, Reverse
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev, *next;
}*first=0;

void create(int A[], int n){
    Node *t, *last;
    first = new Node;
    first->data=A[0];
    first->next = first->prev = 0;
    last = first;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data = A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(Node *p){
    while(p){
        cout<<p->data<<" -> ";
        p=p->next;
    }
    cout<<endl;
}

int Length(Node *p){
    int len = 0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void Insert(Node *p,int idx, int x){
    Node *t = new Node;
    if(idx<0 || idx > Length(p))
        cout<<"Enter valid length";
    else if(idx==0){
        t->data=x;
        t->next = first;
        first->prev=t;
        t->prev=0;
        first=t;
    }
    else{
        t->data=x;
        for(int i=0;i<idx-1;i++) p=p->next;
        t->next=p->next;
        p->next=t;
        t->prev=p;
        if(p->next) p->next->prev=t;
    }
}

int Delete(Node *p, int idx){
    int x;
    if(idx<0 || idx>Length(p)) return -1;
    else if(idx==1){
        first = first->next;
        x = p->data;
        delete p;
        if(first) first->prev=0;
    }
    else{
        for(int i=0;i<idx-1;i++) p=p->next;
        p->prev->next=p->next;
        if(p->next) p->next->prev=p->prev;
        x=p->data;
        delete p;
    }
    return x;
}

void Reverse(Node *p){
    Node *temp;
    while(p){
        temp = p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=0 && p->next==0) first=p;
    }
}

int main(){
    int A[] = {10,20,30,40,50};
    create(A,5);
    cout<<"Length is: "<<Length(first)<<endl;
    Insert(first,3,25);
    Delete(first,2);
    Reverse(first);
    Display(first);
    return 0;
}