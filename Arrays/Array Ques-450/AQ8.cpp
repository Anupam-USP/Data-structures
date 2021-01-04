// Kadane's Algo
#include <iostream>
#include <climits>
using namespace std;

int Sum(int []a, int n){
	int sum = 0;
	int max1 = INT_MIN;
	for(auto i: a){
		sum+=a;
		max1 = max(sum,max1);
		if(sum<0) aum=0;
	}

	return max1
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<Sum(a[],n);
	return 0;
}