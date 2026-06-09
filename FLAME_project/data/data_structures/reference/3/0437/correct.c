#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int e,i,k,m=150;
	char a[150];
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!='0'&&a[i]!='.')
		{
			k=i;
			break;
		}
	}
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='.')
		{
			m=i;
		}
	}
	if(m==150)
	{
		m=strlen(a);
	}
	e=m-k;
	if(e>=0) 
	{
		e--; 
	}
	printf("%c",a[k]);
	if(a[k+1]=='\0')
	{
		printf("e%d\n",e);
	}
	else
	{
		printf(".");
		for(i=k+1;i<strlen(a);i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			{
				printf("%c",a[i]);
			}
		}
		printf("e%d\n",e);
	}	
}

