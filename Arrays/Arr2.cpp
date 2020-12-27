// Binary Search
#include <iostream>
using namespace std;

struct Array{
	int A[10];
	int size, length;
};

int Binary(Array arr,int key){
	int l, mid, h;
	l=0;
	h=arr.length-1;
	while(l<=h){
		mid = (l+h)/2;
		if(key==arr.A[mid]){
			return mid;
		}
		else if(key<arr.A[mid]){
			h=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return -1;
}

int RecBinary(int arr[],int l,int h,int key){
	int mid;
	if(l<=h){
		mid=(l+h)/2;
		if (key==arr[mid]){
			return mid;
		}
		else if(key<arr[mid]){
			return RecBinary(arr,l,mid-1,key);
		}
		else{
			return RecBinary(arr,mid+1,h,key);
		}
	}
	return -1;
}

int main(){
	Array arr={{1,2,3,4,5,6,7,8},10,7};
	cout<<RecBinary(arr.A,0,arr.length,5)<<endl;
	return 0;
}