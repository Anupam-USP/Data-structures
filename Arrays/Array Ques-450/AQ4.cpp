// DNF algo to sort 0,1,2
#include <iostream>
#include <cstdlib>
using namespace std;

int DNF(int a[], int n){
    int low=0,mid=0;
    int high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a[mid],a[high]);
            // mid++;
            high--;
        }
    }
}

int main(){
	int a[5]={0,2,1,2,0};
	DNF(a,5);
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}