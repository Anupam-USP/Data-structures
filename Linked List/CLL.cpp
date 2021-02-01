// Display, insert, delete
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};

class CircularLL{
private:
    Node *head;
public:
    CircularLL(){head=0;}
    CircularLL(int A[], int n);
    ~CircularLL();

    void Display();
    // void RDisplay(Node *p);
    void Insert(int idx, int n);
    int Delete(int idx);
};

CircularLL::CircularLL(int A[], int n){
    int i;
    Node *t,*last;
    head = new Node;
    head->data=A[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

CircularLL::~CircularLL(){
    Node *p=head;
    do{
        head=head->next;
        delete p;
        p=head;
    }while(p!=head);
}

void CircularLL::Display(){
    Node *p=head;
    do{
        cout<<p->data<<" -> ";
        p=p->next;
    }while(p!=head);
}

/*void CircularLL::RDisplay(Node *p){
    if(p==0) p=head;
    else{
        static int flag=0;
        if(p!=head || flag == 0){
            flag=1;
            cout<<p->data<<" ";
            RDisplay(p->next);
        }
        flag=0;
    }
}*/

void CircularLL::Insert(int idx, int x){
    Node *p = head;
    Node *t;

    if(idx==0){
        t = new Node;
        t->data = x;
        if(head==0){
            head = t;
            head->next = head;
        }
        else{
            while (p->next!=0){
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        t = new Node;
        t->data = x;
        for(int i=1;i<idx-1;i++) p=p->next;
        t->next = p->next;
        p->next = t;
    }
}

int CircularLL::Delete(int idx){
    Node *p = head;
    Node *q;
    int x;
    if(idx==1){
        while(p->next!=head) p=p->next;
        x=head->data;
        if(p==head){
            delete head;
            head=0;
        }
        else{
            p->next=head->next;
            delete head;
            head=p->next;
        }
    }
    else{
        for(int i=0;i<idx-2;i++) p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

int main(){
    int A[]={2,4,7,12,17};
    CircularLL c(A,5);
    c.Insert(3,8);
    c.Display();
    cout<<endl;
    c.Delete(4);
    c.Display();
    return 0;
}