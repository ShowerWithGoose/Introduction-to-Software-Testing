#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	int i,j;
	gets(a);
	printf("%c",a[0]);
	for(i=1;i<=strlen(a)-2;i++)
	{
		if(a[i]!='-')
		{
			printf("%c",a[i]);
			continue;
		}
		else
		{
			if(97<=a[i-1]&&a[i-1]<=122&&97<=a[i+1]&&a[i+1]<=122)
			{
				if((a[i+1]-a[i-1])>0)
				{
					for(j=1;j<=a[i+1]-a[i-1]-1;j++)
					{
						printf("%c",a[i-1]+j);
					}
				}
				else printf("%c",a[i]);
			}
			else if(65<=a[i-1]&&a[i-1]<=90&&65<=a[i+1]&&a[i+1]<=90)
			{
				if((a[i+1]-a[i-1])>0)
				{
					for(j=1;j<=a[i+1]-a[i-1]-1;j++)
					{
						printf("%c",a[i-1]+j);
					}
				}
				else printf("%c",a[i]);
			}
			else if(48<=a[i-1]&&a[i-1]<=57&&48<=a[i+1]&&a[i+1]<=57)
			{
				if((a[i+1]-a[i-1])>0)
				{
					for(j=1;j<=a[i+1]-a[i-1]-1;j++)
					{
						printf("%c",a[i-1]+j);
					}
				}
				else printf("%c",a[i]);
			}
			
			else printf("%c",a[i]);
		}
	}
	printf("%c",a[strlen(a)-1]);
	return 0;
 } 

