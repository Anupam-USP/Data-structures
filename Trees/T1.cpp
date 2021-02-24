#include <iostream>
#include "Queuecpp.h"
using namespace std;

class Tree{
public:
    Node *root;
    Tree(){root=0;}
    void CreateTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    void Inorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
};

void Tree::CreateTree(){
    Node *p, *t;
    int x;
    Queue q(100);
    
    cout<<"Enter root value: ";
    cin>>x;
    root = new Node;
    root->data=x;
    root->lchild=root->rchild=0;
    q.Enqueue(root);

    while(!q.isEmpty()){
        p=q.Dequeue();
        cout<<"Enter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=0;
            p->lchild=t;
            q.Enqueue(t);
        }

        cout<<"Enter right child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=0;
            p->rchild=t;
            q.Enqueue(t);
        }

        
    }
}

void Tree::Preorder(Node *p){
    if(p){
        cout<<p->data<<" -> ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" -> ";
        Inorder(p->rchild);
    }
}

void Tree::Levelorder(Node *p){
    Queue q(100);
    cout<<root->data;
    q.Enqueue(root);
    while(!q.isEmpty()){
        root=q.Dequeue();
        if(root->lchild){
            cout<<root->lchild->data<<" -> ";
            q.Enqueue(root->lchild);
        }
        if(root->rchild){
            cout<<root->rchild->data<<" -> ";
            q.Enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *root){
    int x=0,y=0;
    if(root==0) return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y) return x+1;
    else return y+1;
}

int main(){
    Tree t;
    t.CreateTree();
    t.Preorder(t.root);
    return 0;
}
