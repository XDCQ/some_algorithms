/*
	冒泡排序，时间复杂度O(n^2),稳定的排序
*/
#include <stdio.h>

void Bubble_sort(int* arr,int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j<len-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
			}
		}
	}
}

int main()
{
	int arr[] = {2,6,3,9,1,3,4,5,5,7,0,2};
	//printf("%d\n",sizeof(arr)/4);
	Bubble_sort(arr,sizeof(arr)/4);
	for(int i=0;i<sizeof(arr)/4;i++)
	{
		printf("%d,",arr[i]);	
	}
	putchar('\n');
	return 0;	
}
