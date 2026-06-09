#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[10005],b[10005];
	int i,j,k,m,n,len,e=0,fu=1;
	gets(a);
	len=strlen(a);
	if(a[0]=='0'&&len==3)
	{
		printf("%ce-1",a[2]);
	}
	else if(a[0]=='0')
	{
		for(i=2;i<len;i++)
		{
			if(a[i]!='0')
			{
				printf("%c.",a[i]);
				for(j=1;j<len-i;j++)	printf("%c",a[i+j]);
				printf("e-%d",i-1);
				break;
			}
		}
	}
	else if(a[0]!='0'&&a[1]=='.')
	{
		printf("%se0",a);
	}
	else
	{
		printf("%c.",a[0]);
		for(i=1;;i++)
		{
			if(a[i]!='.')	e++;
			else break;
		}
		for(i=1;i<len;i++)
		{
			if(a[i]!='.')	printf("%c",a[i]);
			else continue;
		}
		printf("e%d",e);
	}
	return 0;
}

