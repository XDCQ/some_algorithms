/*
	选择排序，时间复杂度O(n^2),不稳定排序
	每次选出最小的数，将其放到数组无序部分的的第一个位置
*/
#include <stdio.h>

int find_min_index(int* arr,int start,int end)
{
	int min = start;
	for(int i=start+1;i<=end;i++)
	{
		if(arr[i] < arr[min])
			min = i;
	}
	return min;
}

void select_sort(int* arr,int len)
{
	for(int i=0;i<len-1;i++)
	{
		int min = find_min_index(arr,i,len-1);
		if(min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

int main()
{
	int arr[] = {2,6,3,9,1,3,4,5,5,7,0,2};
	select_sort(arr,sizeof(arr)/4);
	for(int i=0;i<sizeof(arr)/4;i++)
	{
		printf("%d,",arr[i]);	
	}
	return 0;	
}

