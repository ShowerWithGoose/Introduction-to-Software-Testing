#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[10005];
	int dot=0,first,i,j,t=1,none=0;
	gets(a);
	for (i=0;i<strlen(a);i++)
	{
		if (a[i]=='.') dot=i;
		if (a[i]>='1'&&a[i]<='9'&&t)
		{
			first=i;
			t=0;
		}
	}
	if (a[0]=='-') printf("-");
	if (dot==0)
	{
		for (i=first+1;i<strlen(a);i++)
		{
			if (a[i]>='1'&&a[i]<='9')
			{
				none=i;
			}
		}
		if (none==0)
		{
			printf("%ce%d",a[first],strlen(a)-1-first);
		}
		else
		{
			printf("%c.",a[first]);
			for (j=first+1;j<=none;j++)
			{
				printf("%c",a[j]);
			}
			printf("e%d",strlen(a)-1-first);
		}
	}
	else
	{
		for (i=first+1;i<strlen(a);i++)
		{
			if (a[i]>='1'&&a[i]<='9')
			{
				none=i;
			}
		}
		printf("%c",a[first]);
		if (none!=0) printf(".");
		for (j=first+1;j<=none;j++)
		{
			if (a[j]!='.')
			{
				printf("%c",a[j]);
			}
		}
		printf("e%d",(dot-first)>=0?dot-first-1:dot-first);
	}
	return 0;
}


