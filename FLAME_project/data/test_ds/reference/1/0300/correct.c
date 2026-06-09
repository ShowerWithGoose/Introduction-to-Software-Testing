#include <string.h>
#include <stdio.h>
#include <math.h>
int main()
{
	char a[10000];
	gets(a);
	int i=0,j=0,k=0,m=1;
	i=strlen(a);
	for(k=0;k<i;k++)
	{
		if(a[k]=='-')
		{
			j=a[k+1]-a[k-1];
			if(a[k-1]>='a'&&a[k+1]<='z')
			{
				for(m=1;m<j;m++)
				{
					printf("%c",a[k-1]+m);
				}
			}
			else if(a[k-1]>='A'&&a[k+1]<='Z')
			{
				for(m=1;m<j;m++)
				{
					printf("%c",a[k-1]+m);
				}
			}
			else if(a[k-1]>='0'&&a[k+1]<='9')
			{
				for(m=1;m<j;m++)
				{
					printf("%c",a[k-1]+m);
				}
			}
			else
				printf("%c",'-');	
		}
		else
		{
			printf("%c",a[k]);
		}
	}
	return 0;
	
}

