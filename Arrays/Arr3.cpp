// Get() Set() Max() on array
#include <iostream>
using namespace std;

struct Array{
	int A[10];
	int size, length;
};

int Get(Array arr, int idx){
	if(idx>=0 && idx<arr.length){
		return arr.A[idx];
	}
	return -1;
}

void Set(Array *arr, int idx, int n){
	cout<<"Replacing "<<Get(*arr,idx)<<" with "<<n<<endl;
	if(idx>=0 && idx<arr->length){
		arr->A[idx]=n;
	}
}

int Max(Array arr){
	int max=arr.A[0];
	for(int i=1;i<arr.length;i++){
		if (arr.A[i]>max)
			max=arr.A[i];
	}
	return max;
}
// Min() and Sum() functions will also follow Max() func

int main(){
	Array arr={{2,3,4,5,6,7},10,6};
	cout<<"2nd idx: "<<Get(arr,3)<<endl;
	cout<<"9th idx: "<<Get(arr,9)<<endl;
	Set(&arr,3,56);
	cout<<"2nd idx after replacing: "<<Get(arr,3)<<endl;
	cout<<"Max element is: "<<Max(arr);
	return 0;
}