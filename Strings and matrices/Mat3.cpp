// Menu driven program for matrix
#include <iostream>
using namespace std;

class Diagonal{
private:
    int *A;
    int n;
public:
    Diagonal(int n);
    void Create();
    // int Get(int i, int j);
    // void Set(int i, int j, int k);
    void Display();
    ~Diagonal();
};

Diagonal::Diagonal(int n){
    this->n=n;
    // Depending on matrix we have to change the size of array
    A = new int[n];  
}

void Diagonal::Create(){
    int x;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x;
            if(i==j){
                A[i-1]=x;
            }
        }
    }
}

void Diagonal::Display(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cout<<A[i-1]<<" ";
            }
            else{
                cout<<'0 ';
            }
        }
        cout<<endl;
    }
}

Diagonal::~Diagonal(){
    delete []A;
}

int main(){
    return 0;
}