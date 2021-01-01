// Moving all negative elements to one side
#include <iostream>
#include <cstdlib>
using namespace std;

void Sort(int A[], int n){
	// Using pivot
    int i=0,j=0;
    int pivot=0;
    for(j=0;j<5;j++){
        if(A[j]<pivot){
            swap(A[i],A[j]);
            i++;
        }
    }
}

int main()
{
    int a[5]={3,-2,8,-4,6};
    Sort(a,5);
    for(int i=0;i<5;i++)    
        cout<<a[i]<<" ";
    return 0;
}
