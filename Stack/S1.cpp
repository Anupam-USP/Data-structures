// Using array
#include <iostream>
using namespace std;

struct stack{
    int size, top;
    int *s;
};

void create(stack *st){
    cout<<"Enter size: ";
    cin>>st->size;
    st->top=-1;
    st->s=new int[st->size*sizeof(int)];

}

void push(stack *st, int x){
    if(st->top > st->size-1) 
        cout<<"Stack overflow"<<endl;
    else{
        st->top++;
        st->s[st->top]=x;
    }
}

void Display(stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.s[i]<<" -> ";
    }
    cout<<endl;
}

int pop(stack *st){
    int x=-1;
    if(st->top==-1)
        cout<<"Stack underflow";
    else{
        x=st->s[st->top];
        st->top--;   
    }
    return x;
}

int peek(stack *st, int pos){
    int x=-1;
    if(st->top-pos+1<0)
        cout<<"Invalid position"<<endl;
    else{
        x=st->s[st->top-pos+1];
    }
    return x;
}

int stacktop(stack *st){
    if(st->top==-1)
        return -1;
    else{
        return st->s[st->top];
    }
}

int isEmpty(stack *st){
    if(st->top==-1) return 1;
    else return 0;
}

int isFull(stack *st){
    if(st->top==st->size-1) return 1;
    else return 0;
}

int main(){
    stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    Display(st);
    return 0;
}