#include<iostream> 
using namespace std; 

int findPivotPosition(int arr[],int start,int end)
{
	// base case
	if(start >= end)
		return -1;

	// mid = start + (end-start)/2; to reduce integer range problem
	int mid = (start+end)/2;

	// Next element smaller in sorted rotated array means it is largest
	if(mid<end && arr[mid]>arr[mid+1])
		return mid;
	if(start<mid && arr[mid-1]>arr[mid+1])
		return mid-1;

	// First element is greater than current element
	// So the largest element is before current
	if(arr[start]>arr[mid])
		return findPivotPosition(arr,start,mid-1);

	// All other cases
	return findPivotPosition(arr,mid+1,end);
}

int findPivotPosition1(int arr[],int start,int end)
{
	// Traversing the array arr
	for(int i=1;i<=end;i++)
	{
		// Condition for pivot
		if(arr[i-1]>arr[i])
			return i-1;
	}
	
	// Pivot not found
	return -1;
}

int main()
{ 
	#ifndef ONLINE_JUDGE 
		freopen("inp.txt", "r", stdin); 
		freopen("err.txt", "w", stderr); 
		freopen("out.txt", "w", stdout); 
	#endif 

	// Find pivot position in the array below
	int arr[] = {7, 11, 22, 1, 3};
	cout << findPivotPosition(arr,0,(sizeof(arr)/sizeof(int))-1) << endl;
	return 0;
} 