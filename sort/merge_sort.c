/*
	归并排序,时间复杂度O(nlogn),空间复杂度O(n),稳定的排序
*/
#include <stdio.h>
#include <stdlib.h>

void merge(int* arr,int arr1_start,int arr1_end,int arr2_start,int arr2_end)
{
	int len = arr2_end - arr1_start +1;
	int* temp = (int*)malloc(len*4);
	int i = arr1_start;
	int j = arr2_start;
	int k = 0;
	while(i != arr1_end+1 && j != arr2_end+1)
	{
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i != arr1_end+1)
		temp[k++] = arr[i++];
	while(j != arr2_end+1)
		temp[k++] = arr[j++];
	for(int x=arr1_start,k=0;k<len;x++,k++)
		arr[x] = temp[k];
	free(temp);
}
void merge_sort(int* arr,int left,int right)
{
	if(left < right)
	{
		int mid = (right + left)/2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid+1,right);
		merge(arr,left,mid,mid+1,right);
	}
}

int main()
{
	int arr[] = {2,6,3,9,1,3,4,5,5,7,0,2};
	merge_sort(arr,0,sizeof(arr)/4-1);
	for(int i=0;i<sizeof(arr)/4;i++)
	{
		printf("%d,",arr[i]);	
	}
	return 0;	
}
