// Check sorted, remove duplis, reverse
#include <iostream>
#include <limits.h>
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

int isSorted(Node *p){
    int x = INT_MIN;
    while(p){
        if(p->data<x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;
}

void RemDups(Node *p){
    Node *q = p->next;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
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

void Reverse1(Node *p){
    int i=0;
    int *A;
    A=new int[count(p)];
    Node *q=p;
    while(q){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q){
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void Rev2(Node *p){
    Node *q=0,*r=0;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int main(){
    Node *temp;
    int A[] = {2,6,8,10,14};
    Create(A,5);
    Display(first);
    // RemDups(first);
    cout<<endl;
    Reverse1(first);
    Display(first);
    cout<<endl;
    Rev2(first);
    Display(first);
    // cout<<isSorted(first);
    return 0;
}