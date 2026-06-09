#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char a[10005];
	gets(a);
	int i,j,k,m,n,len;
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]>='a'&&a[i]<='z'&&a[i+1]=='-'&&a[i+2]>='a'&&a[i+2]<='z')
		{
			m=a[i+2]-a[i];
			if(m<=0)
			{
				printf("%c",a[i]);
				continue;
			}
			else
			{
				printf("%c",a[i]);
				for(int x=1;x<=m-1;x++)	printf("%c",a[i]+x);
				i++;
			}
		}
		else if(a[i]>='A'&&a[i]<='Z'&&a[i+1]=='-'&&a[i+2]>='A'&&a[i+2]<='Z')
		{
			m=a[i+2]-a[i];
			if(m<=0)
			{
				printf("%c",a[i]);
				continue;
			}
			else
			{
				printf("%c",a[i]);
				for(int x=1;x<=m-1;x++)	printf("%c",a[i]+x);
				i++;
			}
		}
		else if(a[i]>='0'&&a[i]<='9'&&a[i+1]=='-'&&a[i+2]>='0'&&a[i+2]<='9')
		{
			m=a[i+2]-a[i];
			if(m<=0)
			{
				printf("%c",a[i]);
				continue;
			}
			else
			{
				printf("%c",a[i]);
				for(int x=1;x<=m-1;x++)	printf("%c",a[i]+x);
				i++;
			}
		}
		else printf("%c",a[i]);
	}
	return 0;
}

