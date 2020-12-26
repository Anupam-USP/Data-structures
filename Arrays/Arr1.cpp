//  Linear Search in array
#include <iostream>
using namespace std;

struct Array{
	int A[10];
	int size, length;
};

void Display(Array arr){
	cout<<"Elements are: ";
	for(int i=0;i<arr.length;i++){
		cout<<arr.A[i]<<" ";
	}
}

void swap(int *x, int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

int Linear(Array *arr,int key){
	for(int i=0;i<arr->length;i++){
		if(key==arr->A[i]){
			// Transposition
			// For move to head replace i-1 with 0
			swap(&arr->A[i],&arr->A[i-1]);
			return i;
		}
	}
	return -1;
}

int main(){
	Array arr={{2,3,4,5,6},10,5};
	Display(arr);
	cout<<endl<<"Element found at: "<<Linear(&arr,5)<<endl;
	Display(arr);
	return 0;
}