//  Power of a number
#include <iostream>
using namespace std;

int pow(int m, int n){
	if(n==0){
		return 1;
	}
	return pow(m,n-1)*m
}

int pow1(int m, int n){
 	if (n==0){
 		return 1;
 	}
 	else if(n%2==0){
 		return pow1(m*m,n/2);
 	}
 	else{
 		return m*pow1(m*m,(n-1)/2);
 	}
 }

 int main(){
 	int m,n;
 	cin>>m>>n;
 	cout<<pow1(m,n)<<endl;
 	return 0;
 }