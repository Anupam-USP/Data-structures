// Concatenate, Merge, Loop check
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=0,*second=0,*third=0;

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

void Create2(int A[],int n){
    Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next=0;
    last = second;

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

void Concat(Node *p, Node *q){
    third = p;
    while(p->next)
        p=p->next;
    p->next=q;
}

void Merge(Node *p, Node *q){
    Node *last;
    if(p->data < q->data){
        third = last = p;
        p=p->next;
        last->next=0;
    }
    if(p->data > q->data){
        third = last = q;
        q=q->next;
        last->next=0;
    }
    while(p && q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=0;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=0;
        }
    }
    if(p) last->next=p;
    else last->next=q;
}

int isLoop(Node *f){
    Node *p, *q;
    p=q=f;
    do{
        p = p->next;
        q = q->next;
        q = q?q->next:q;
    }while(p && q && p!=q);

    return p==q?true:false;
}

int main(){
    Node *t1,*t2;
    int A[] = {2,6,8,10,14};
    Create(A,5);

    // int B[] = {1,5,9,13,18};
    // Create2(B,5);
    // // Concat(first,second);
    // Merge(first,second);
    // Display(third);

    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next=t1;
    cout<<isLoop(first);

    return 0;
}