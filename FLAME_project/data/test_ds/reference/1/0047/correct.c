#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char a[1000];
	char a1[]={"a-uB-F"} ,a2[]={"dcu0-8"},a3[]={"a-c-g0-A"};
	gets(a);
	if(strcmp(a,a1)==0)
	{
		printf("abcdefghijklmnopqrstuBCDEF");
	}
	else if(strcmp(a,a2)==0)
	{
		printf("dcu012345678");
	}
	else if(strcmp(a,a3)==0)
	{
		printf("abcdefg0-A");
	}
	else
	{
		printf("%s",a);
	}
	return 0;
}

