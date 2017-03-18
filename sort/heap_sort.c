/*
	堆排序，时间复杂度O(n*logn),不稳定排序
	此处使用的是大堆
*/
#include <stdio.h>

void heap_adjust(int* arr,int node,int len)
{
	while(2*node+1<len)
	{
		int max = 2*node+1;
		if(2*node+2<len && (arr[2*node+1] < arr[2*node+2]))
			max = 2*node+2;
		if(arr[node] < arr[max])
		{
			int temp = arr[node];
			arr[node] = arr[max];
			arr[max] = temp;
		}
		else
			break;
		node = max;
	}
}

void heap_sort(int* arr,int len)
{
	for(int i=len/2-1;i>=0;i--)
		heap_adjust(arr,i,len);
	for(int i=len-1;i>0;i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heap_adjust(arr,0,i);
	}
}

int main()
{
	int arr[] = {2,6,3,9,1,3,4,5,5,7,0,2};
	heap_sort(arr,sizeof(arr)/4);
	for(int i=0;i<sizeof(arr)/4;i++)
	{
		printf("%d,",arr[i]);	
	}
	return 0;	
}
