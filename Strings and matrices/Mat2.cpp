// Lower triangular matrix
#include <iostream>
using namespace std;

class LowerT{
private:
	int n;
	int *A;
public:
	LowerT(){
		n=2;
		A = new int[n*(n+1)/2];
	}
	LowerT(int n){
		this->n = n;
		A = new int[n*(n+1)/2];
	}

	void Set(int i,int j, int x);
	int Get(int i, int j);
	void Display();

	~LowerT(){
		delete []A;
	}
};

void LowerT::Set(int i, int j,int x){
	if(i>=j){
		A[i*(i-1)/2+j-1]=x;
	}
}

int LowerT::Get(int i,int j){
	if(i>=j){
		return A[i*(i-1)/2+j-1];
	}
	return 0;
}

void LowerT::Display(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>=j)
				cout<<A[i*(i-1)/2+j-1]<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cout<<"Enter the dimension in \"n form\": "<<endl;
	cin>>n;
	
	LowerT lm(n);
	int x;

	cout<<"Enter elements: "<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>x;
			lm.Set(i,j,x);
		}
	}
	lm.Get(3,2);
	lm.Display();
	return 0;
}