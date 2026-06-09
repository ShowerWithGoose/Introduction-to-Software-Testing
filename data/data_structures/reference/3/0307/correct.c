#include <stdio.h>
#include <string.h>
int main()
{
	char a[200];
	gets(a);
	int i,j;
	if(a[0]=='0')
	{
		for(i=2;a[i]=='0';i++);
		printf("%c",a[i]);
		if(a[i+1]=='\0')
		printf("e-%d",i-1);
		else
		{
			printf(".");
			for(j=i+1;a[j]!='\0';j++)
			printf("%c",a[j]);
			printf("e-%d",i-1);
		}
	}
	else	
	{
		printf("%c",a[0]);
		if(a[1]!='\0')
		{
			printf(".");
			for(i=1;a[i]!='\0';i++)
			{
				if(a[i]!='.')
				printf("%c",a[i]);
				else
				j=i;
			}
			printf("e%d",j-1);
		}
		else
		printf("e0");
	}
	return 0;
} 

