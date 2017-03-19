/*
	二分查找，时间复杂度为O(logn)
*/
#include <stdio.h>

int binsearch(int* arr,int len,int key)
{
	int left = 0,right = len-1;
	int mid = 0;
	while(left <= right)
	{
		mid = (left + right)/2;
		if(key > arr[mid])
			left = mid+1;
		else if(key < arr[mid])
			right = mid-1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d\n",binsearch(arr,sizeof(arr)/4,7));
	return 0;
}
