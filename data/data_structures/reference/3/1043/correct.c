#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long

int main()
{
	char a[10086];
	int i,j,k,t,m;
	gets(a);
	k=strlen(a);
	if(a[1]!='.')
	{
		for(i=0;i<k;i++)
		{
			if(a[i]=='.')
			{
				t=i-1;
				for(j=i;j<k;j++)
				{
					a[j]=a[j+1];
				}
			}
		}
		printf("%c.",a[0]);
		for(j=1;j<(k-1);j++)
		{
			printf("%c",a[j]);
		}
		printf("e%d",t);
	}	
	else if(a[0]!='0')
	{
		for(i=0;i<k;i++)
		{
			printf("%c",a[i]);
		}
		printf("e0");
	}
	else if(a[1]=='.'&&a[2]!='0')
	{
		printf("%c",a[2]);
		if(k>3)
		{
			printf(".");
		}
		for(i=3;i<k;i++)
		{
			printf("%c",a[i]);
		}
		printf("e-1");
	}
	else
	{
		for(i=0;i<k;i++)
		{
		
			if(a[i]=='0'&&a[i+1]>'0'&&a[i+1]<='9')
			{
				m=i;
				printf("%c.",a[i+1]);break;
			}
		
		}
			for(j=m+2;j<k;j++)
					{
						printf("%c",a[j]);
					}
					printf("e-%d",m);
	}
    return 0;
}

