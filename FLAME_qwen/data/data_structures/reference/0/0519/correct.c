#include<stdio.h>
#include<string.h>
char a[10000];
char b;
int main()
{
	gets(a);
	int x;
	x=strlen(a);
	int i=0;
	for(i=0;i<x;i++)
	{
		if(a[i]=='-')
		{
			if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>a[i-1]&&a[i+1]<='z')
			{
				
					for(b=a[i-1]+1;b<a[i+1];b++)
					printf("%c",b);
				
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>a[i-1]&&a[i+1]<='Z')
			{
					for(b=a[i-1]+1;b<a[i+1];b++)
					printf("%c",b);	
				
			}
			else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>a[i-1]&&a[i+1]<='9')
			{
					for(b=a[i-1]+1;b<a[i+1];b++)
					printf("%c",b);
			}
			else printf("%c",a[i]);
		}
		else printf("%c",a[i]);
	}
	return 0;
 } 

