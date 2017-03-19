/*
	strstr()的kmp版本，时间复杂度O(n+m)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* get_next(char* str)
{
	int* next = (int*)malloc(strlen(str)*4);
	int i = 1,id = 0;
	next[0] = 0;
	while(i < strlen(str))
	{
		if(str[i] == str[next[id]])
		{
			next[i] = next[id]+1;
			i++;
			id = i-1;
			continue;
		}

		if(next[id] == 0)
		{
			next[i] = 0;
			i++;
			id = i-1;
			continue;
		}

		id = next[id] - 1;
	}
	return next;
}

char* strstr__(char* src,char* str)
{
	int* next = get_next(src);
	int i=0,j=0;
	while(i < strlen(src))
	{
		if(src[i] == str[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j==0 || next[j-1] == 0)
			{
				j=0;
				if(src[i] != str[j])
					i++;
			}
			else
				j = next[j-1];
		}
		if(str[j] == 0)
			return &src[i - strlen(str)];
	}
	return NULL;
}

int main()
{
	char* src = "wjkciwbiucvqwjvbciuwbviubiqwevlbwvbisbvbaskjcvbnjke";
	char* str = "qwevl";
	// int* next = get_next(src);
	// for(int i=0;i<strlen(src);i++)
	// 	printf("%d\n",next[i]);
	char* result = strstr__(src,str);
	if(result != NULL)
		printf("%s\n",result);
	else
		printf("NO\n");
	return 0;	
}
