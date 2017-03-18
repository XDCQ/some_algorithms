/*
	快速排序，时间复杂度O(n*logn),不稳定排序
	存在非递归的优化版本，和多层while嵌套的原始版本
*/
#include <stdio.h>

void quick_sort(int* arr,int left,int right)
{
	if(left >= right)
		return;
	int border = left;
	for(int i = left;i<right;i++)
	{
		if(arr[i]<arr[right])
		{
			int temp = arr[i];
			arr[i] = arr[border];
			arr[border] = temp;
			border++;
		}
	}
	int temp = arr[right];
	arr[right] = arr[border];
	arr[border] = temp;

	quick_sort(arr,left,border-1);
	quick_sort(arr,border+1,right);
}

int main()
{
	int arr[] = {2,6,3,9,1,3,4,5,5,7,0,2};
	quick_sort(arr,0,sizeof(arr)/4-1);
	for(int i=0;i<sizeof(arr)/4;i++)
	{
		printf("%d,",arr[i]);	
	}
	return 0;	
}
