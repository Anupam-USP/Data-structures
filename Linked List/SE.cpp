// Middle node
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*first=0;

void create(int A[], int n){
    Node *t, *last;
    first = new Node;
    first->data=A[0];
    first->next=0;
    last = first;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=0;
        last->next=t;
        last=t;
    }
}

int length(Node *p){
    int cnt=0;
    while(p){
        cnt++;
        p=p->next;
    }
    return cnt;
}

int Mid(Node *p){
    Node *q=p;
    while(q){
        q=q->next;
        if(q) q=q->next;
        if(q) p=p->next;
    }
    cout<<"Mid element: "<<p->data<<endl;
}

int main(){
    int A[]={10,20,30,40,50,60,70};
    create(A,7);
    Mid(first);
    return 0;
}