#include <stdio.h>
#include <string.h>
int main()
{
	int l1,l2,m,h,u;
	char a[100],b[100],c;
	scanf("%s",a);
    h=strlen(a);
	for(int i=1;i<=h;i++)
	{
		if(a[i]=='.')
		{
			m=i;
			break;
		}
	}
	l1=m;
	l2=h-m-1;
	if(l1>1)
	{
		printf("%c.",a[0]);
		for(int i=1;i<=l1-1;i++)
		{
			printf("%c",a[i]);
		}
		for(int i=l1+1;i<h;i++)
		{
			printf("%c",a[i]);
		}
		printf("e%d",l1-1);
	}
	else if(l1==1&&a[0]>'0')
	{
		printf("%c.",a[0]);
		for(int i=2;i<h;i++)
		{
			printf("%c",a[i]);
		}
		printf("e0");
	}
	else
	{
		for(int i=2;i<h;i++)
		{
			if(a[i]>'0')
			{
				u=i;
				break;
			}	
		}
		printf("%c",a[u]);
		if(u+1<h)
		{
			printf(".");
		}
		for(int i=u+1;i<h;i++)
		{
			printf("%c",a[i]);
		}
		printf("e-%d",u-1);
	}
	return 0;
} 

