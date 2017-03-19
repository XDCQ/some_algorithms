/*
	插入排序，时间复杂度O(n^2)，稳定排序
	将无序部分的第一个数插入有序部分
	PS:有序部分从后向前找，直到找到比它小的值为止
*/
#include <stdio.h>

void insert_sort(int* arr,int len)
{
	for(int i=1;i<len;i++)
	{
		int n = arr[i],j=0;
		for(j=i-1;j>=0&&arr[j]>n;j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] = n;
	}
}

int main()
{
	int arr[] = {2,6,3,9,1,3,4,5,5,7,0,2};
	insert_sort(arr,sizeof(arr)/4);
	for(int i=0;i<sizeof(arr)/4;i++)
	{
		printf("%d,",arr[i]);	
	}
	return 0;	
}

