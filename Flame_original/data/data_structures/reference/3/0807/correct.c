#include <stdio.h>
#include <string.h>
char a[150];
int main()
{
	int i,j,n,l;
	gets(a);
	l=strlen(a);
	if(a[0]=='0')
	{
		for(i=2;a[i]=='0';i++)
		{
			;
		}
		n=i-1;
		for(j=i;j<l;j++)
		{
			printf("%c",a[j]);
			if(j==i&&j!=l-1)
			printf(".");
		}
		printf("e-%d",n);
	}
	else
	{
		for(i=1;a[i]!='.';i++)
		{
			;
		}
	    n=i-1;
	    for(j=0;j<l;j++)
	    {
	    	if(j!=i)
	    	printf("%c",a[j]);
		if(j==0)
		printf(".");
		}
		printf("e%d",n);
	}
} 

