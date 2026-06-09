#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char c[5000];
	scanf("%s",c);
	int i,j;
	for(i=0;c[i]!='\0';i++)
	{
		if(c[i]=='-')
		{
			if(c[i-1]>='0' && c[i-1]<='9' && c[i+1]>='0' && c[i+1]<='9')
			{
				for(j=c[i-1]+1;j<=c[i+1]-1;j++)
				{
					printf("%c",j);
				}
				continue;
			}
			if(c[i-1]>='A' && c[i-1]<='Z' && c[i+1]>='A' && c[i+1]<='Z')
			{
				for(j=c[i-1]+1;j<=c[i+1]-1;j++)
				{
					printf("%c",j);
				}
				continue;
			}
			if(c[i-1]>='a' && c[i-1]<='z' && c[i+1]>='a' && c[i+1]<='z')
			{
				for(j=c[i-1]+1;j<=c[i+1]-1;j++)
				{
					printf("%c",j);
				}
				continue;
			}
			printf("%c",c[i]);
		}
		else
		{
			printf("%c",c[i]);
		}
	}
	return 0;
}


