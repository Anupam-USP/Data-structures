// Count, sum & max
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

int count(Node *p){
    int c=0;
    while (p){
        c++;
        p=p->next;
    }
    return c;
}

int add(Node *p){
    int sum=0;
    while (p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int max(Node *p){
    int m=INT_MIN;
    while(p){
        if(m<p->data){
            m=p->data;
        }
        p=p->next;
    }
    return m;
}

int main(){
    int A[] = {2,6,8,10,14};
    Create(A,5);
    Display(first);
    cout<<endl;
    cout<<"Number of nodes are: "<<count(first)<<endl;
    cout<<"Sum of nodes are: "<<add(first)<<endl;
    cout<<"Value of max node is: "<<max(first);
    return 0;
}