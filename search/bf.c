/*
strstr()函数的暴力查找版本，时间复杂度O(n^2)
*/
#include <stdio.h>

char* strstr(char* src,char* str)
{
	while(*src != 0)
	{
		char* temp_src = src;
		char* temp_str = str;
		while(*temp_src++ == *temp_str++)
		{
			if(*temp_str == 0)
				return src;
		}
		src++;
	}
	return NULL;
}

int main()
{
	char* src = "abcdefg";
	char* str = "ab";
	char* result = strstr(src,str);
	if(result != NULL)
		printf("%s\n",result);
	else
		printf("NO\n");
	return 0;	
}
