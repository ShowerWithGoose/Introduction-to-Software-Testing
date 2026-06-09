#include <stdio.h>
#include <string.h>
int main()
{
	char a[10000];
	int l;
	gets(a);
	l = strlen(a);
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='-')
		{
			if('a'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='z')
			{
				for(int u=1;u<a[i+1]-a[i-1];u++)
				{
					printf("%c",a[i-1]+u);
				}
			}
			else if('A'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='Z')
			{
				for(int u=1;u<a[i+1]-a[i-1];u++)
				{
					printf("%c",a[i-1]+u);
				}
			}
			else if('0'<=a[i-1]&&a[i-1]<a[i+1]&&a[i+1]<='9')
			{
				for(int u=1;u<a[i+1]-a[i-1];u++)
				{
					printf("%c",a[i-1]+u);
				}
			}
			else printf("%c",a[i]);
			
		}
		else printf("%c",a[i]);
	}
	
}

