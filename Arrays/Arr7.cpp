// Finding duplicates
#include <iostream>
using namespace std;

struct Array{
	int A[10];
	int size, length;
};

int FindDupli(Array arr){
	//  In sorted array
	int lastDupli = 0;
	for(int i=0;i<arr.length;i++){
		if(arr.A[i]!=arr.A[i+1] && arr.A[i]!=lastDupli){
			cout<<arr.A[i];
			lastDupli=arr.A[i];
		}
	}
}

void Dupli(Array arr){
	for (int i = 0; i < arr.length-1; i++){
		int cnt = 1;
		if(arr.A[i]!=-1){
			for (int j = i+1; j < arr.length; j++){
				if (arr.A[i]==arr.A[j]){
					cnt++;
					arr.A[j]=-1;
				}
			}	
			if (cnt>1){
				cout<<arr.A[i]<<" "<<cnt<<endl;
			}
		}
	}
}

int main(){
	Array arr = {{2,3,3,4,5,6,6,6,7},10,9};
	FindDupli(arr);
	cout<<"Unsorted way"<<endl;
	Dupli(arr);
	return 0;
}