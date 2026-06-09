#include <stdio.h>
#include <math.h>
#include <string.h> 

int main()
{
	char a[100];
	gets(a);
	int i=0,j=0,b=0;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]=='.')
			break;
	}
	if(a[0]=='0' || (a[0]=='-' && a[1]=='0'))
	{
		for(j=i+1;a[j]=='0';j++)
		{
		}
		b=j-i;
		if(a[0]=='-') printf("-");
		printf("%c",a[j]);
		if(a[j+1]!='\0') 
			printf(".");
		for(j+=1;a[j]!='\0';j++)
		{
			printf("%c",a[j]);
		}
		printf("e-%d",b);
	}
	else 
	{
		if(a[0]=='-')
		{
			printf("-%c.",a[1]);
			for(j=2;a[j]!='\0';j++)
			{
				if(a[j]!='.')
					printf("%c",a[j]);
			}
			printf("e%d",i-2);
		}
		else 
		{
			printf("%c.",a[0]);
			for(j=1;a[j]!='\0';j++)
			{
				if(a[j]!='.')
					printf("%c",a[j]);
			}
			printf("e%d",i-1);
		} 
	}
	return 0;
}

