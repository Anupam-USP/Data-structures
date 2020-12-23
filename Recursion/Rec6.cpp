// Taylor series in Hornet's rule
#include <iostream>
using namespace std;

double e(int x, int n){
	// Iterative
	double s=1;
	for(;n>0;n--){
		s=1+(x*s/n);
	}
	return s;
}

double e1(int x, int n){
	// Recursive
	static double s=1;
	if(n==0){
		return s;
	}
	s=1+(x*s/n);
	return e1(x,n-1);
}

int main(){
	cout<<e(1,10)<<endl;
	cout<<e1(1,10);
	return 0;
}