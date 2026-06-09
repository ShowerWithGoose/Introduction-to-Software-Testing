#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <ctype.h>
int main()
{
	char a[1000];int i;int j;int sign=0;
	scanf("%s",a);
	int len=strlen(a);
	for(i=0;i<len;i++)
	{
		if(a[i]>='a'&&a[i]<='z'&&a[i+1]!='\0'&&a[i+2]!='\0')
		{
			if(a[i+1]=='-'&&a[i+2]>='a'&&a[i+2]<='z'&&a[i]<a[i+2])
			{
				for(j=a[i];j<a[i+2];j++)
				{
					printf("%c",j);
				}sign=1;
			}else 
			{
				printf("%c",a[i]);
			}
			
			
		}
		else if(a[i]>='0'&&a[i]<='9'&&a[i+1]!='\0'&&a[i+2]!='\0')
		{
			if(a[i+1]=='-'&&a[i+2]>='0'&&a[i+2]<='9'&&a[i]<a[i+2])
			{
				for(j=a[i];j<a[i+2];j++)
				{
					printf("%c",j);
				}sign=1;
			}else 
			printf("%c",a[i]);
		}
		else if(a[i]>='A'&&a[i]<='Z'&&a[i+1]!='\0'&&a[i+2]!='\0')
		{
			if(a[i+1]=='-'&&a[i+2]>='A'&&a[i+2]<='Z'&&a[i]<a[i+2])
			{
				for(j=a[i];j<a[i+2];j++)
				{
					printf("%c",j);
				}sign=1;
			}else 
			printf("%c",a[i]);
		}else if(a[i]=='-'&&sign==1)
		{sign=0;
			continue;
			
		}else
		{
			printf("%c",a[i]);
		}
	}
	return 0;
}

