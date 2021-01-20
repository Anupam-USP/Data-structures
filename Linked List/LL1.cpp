// Display a Linked list
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

void DispRec(Node *p){
    if(p!=0){
        cout<<" -> "<<p->data;
        DispRec(p->next);
    }
}

int main(){
    int A[] = {2,6,8,10,14};
    Create(A,5);
    Display(first);
    cout<<endl;
    DispRec(first);
    return 0;
}