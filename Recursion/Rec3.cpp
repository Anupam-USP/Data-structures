// Factorial
#include <iostream>
using namespace  std;

int func(int n){
	if (n>0){
		return func(n-1)*n;
	}
	else if(n==0){
		return 1;
	}
	else{
		cout<<"Enter positive integer";
		return 0;
	}
}

int main(){
	int n;
	cin>>n;
	cout<<func(n)<<endl;
	return 0;
}