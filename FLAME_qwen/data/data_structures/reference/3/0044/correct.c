#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	gets(a);
	int i=0,j=0;
	if(a[1]=='.'&&a[0]=='0')
	{
		for(i=0;i<strlen(a);i++)
		{
			j=i;
			if(a[i]!='0'&&a[i]!='.')
			{
				
				break;
			}
		}
		

		if(j==(strlen(a)-1)) 
		{

			printf("%c",a[j]);
			printf("e");
			printf("-");
			printf("%d",j-1);
		}
		else if(j<(strlen(a)-1))
		{
			printf("%c",a[j]);
			printf(".");
			for(i=j+1;i<strlen(a);i++)
			{
				printf("%c",a[i]);
			}
			printf("e");
			printf("-");
			printf("%d",j-1);
		}
	}
	else if(a[1]=='.'&&a[0]!='0')
	{
		printf("%s",a);
		printf("e");
		printf("0");
	}
	else if(a[1]!='.')
	{
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='.')
			{
				j=i;
				break;
			}
		}
		if(j==0)
		{
			printf("%s",a);
			printf("e");
			printf("0");
		}
		if(j!=0)
		{
			printf("%c",a[0]);
			printf(".");
			for(i=1;i<j;i++)
			{
				printf("%c",a[i]);
			}
			for(i=(j+1);i<strlen(a);i++)
			{
				printf("%c",a[i]);
			}
			printf("e");
			printf("%d",j-1);
		}
	}
}

