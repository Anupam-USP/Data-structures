// Finding single & multiple missing element
#include <iostream>
using namespace std;

struct Array{
	int A[10];
	int size, length;
};

int Single(Array arr){
	int diff = arr.A[0]-0;
	for(int i=0;i<=arr.length;i++){
		if(arr.A[i]-i!=diff){
			return i+diff;
		}
	}
}

void Multi(Array arr){
	int diff = arr.A[0]-0;
	for(int i=0;i<=arr.length;i++){
		if(arr.A[i]-i!=diff){
			while(diff<arr.A[i]-i){
				cout<<i+diff<<" ";
				diff++;
			}
		}
	}
}

void Multi2(Array arr){

}

int main(){
	Array arr={{2,3,4,5,6,7,9},10,7};
	Array arr2 = {{2,4,7,8,9,10},10,6};
	cout<<Single(arr)<<endl;
	Multi(arr2);
	cout<<endl;
	Multi2(arr2);
	return 0;
}