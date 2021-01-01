// Finding pair so a+b=k
#include <iostream>
using namespace std;

struct Array{
	int A[10];
	int size, length;
};

void FidPair(Array arr, int k){
	for(int i=0;i<arr.length-1;i++){
		for(int j=i+1;j<arr.length;j++){
			if(arr.A[i]+arr.A[j]==k){
				cout<<arr.A[i]<<"+"<<arr.A[j]<<"="<<k<<endl;
			}
		}
	}
}

int main(){
	int k;
	cin>>k;
	Array arr = {{2,4,6,9,5,8,5},10,7};
	FidPair(arr,k);
	return 0;
}