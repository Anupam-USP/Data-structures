// Min and max in array
#include <iostream>
using namespace std;
struct Array{
	int A[10];
	int size, length;
};

void minmax(Array arr){
	int min=arr.A[0];
	int max=arr.A[0];
	for(int i=0;i<arr.length;i++){
		if(arr.A[i]<min){
			min=arr.A[i];
		}
		else if(arr.A[i]>max){
			max=arr.A[i];
		}
	}
	cout<<min<<max;
}

int main(){
	Array arr = {{2,5,8,3,6},10,5};
	cout<<minmax(arr);
	return 0;
}
