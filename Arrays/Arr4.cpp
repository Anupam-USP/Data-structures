// Reversing an array
#include <iostream>
using namespace std;

struct Array{
	int A[10];
	int size, length;
};

void Display(Array arr){
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}

int Reverse(Array *arr){
	int *B=new int[int(arr->length)];
	int i,j;
	for(i=arr->length-1,j=0; i>=0; i--,j++){
		B[j]=arr->A[i];
	}
	for(int i=0;i<arr->length;i++){
		arr->A[i]=B[i];
	}
}

int main(){
	Array arr={{2,3,4,5,6,7},10,6};
	Display(arr);
	cout<<endl;
	Reverse(&arr);
	Display(arr);
	return 0;
}