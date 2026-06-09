#include<stdio.h>
#include<string.h>

char a[105] ;
int main(void)
{
	int m = 0 ,n = 0;
	gets(a);
	int len = strlen(a);
	int i , j;
	for(i = 0; i < len ; i++)
	{
		if(a[i] == '.')
		{
			m = i;
			break;
		}
	}
	for(i = 0; i < len; i++)
	{
		if(a[i] != '0' && a[i] != '.')
		{
			n = i;
			break;
		}
	}
	if(n == len - 1)
	{
		printf("%ce%d\n",a[n],m - n);
	}
	else if(m < n)
	{
		printf("%c.",a[n]);
		for(i = n + 1; i < len; i++)
		{
			printf("%c",a[i]); 
		}
		printf("e%d",m - n);
	}
    else if(m == 1 && n == 0)
    {
    	printf("%se0",a);
    	
	}
	else
	{
		printf("%c.",a[n]);
		for(i = n + 1; i < m; i++)
		{
			printf("%c",a[i]);
		}
		for(i = m + 1; i < len; i++)
		{
			printf("%c",a[i]); 
		}
		printf("e%d",m - n -1);
	}
	return 0;
}



