#include<stdio.h> 
#include<string.h>
void delete1(char a,char b)
{
	if(a>='a'&&a<='z'&&b>='a'&&b<='z'&&a<b)
	{
		for(char c=a+1;c<b;c++)
		{
			printf("%c",c);
		}
	}
	else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&a<b)
		{
			for(char c=a+1;c<b;c++)
			{
				printf("%c",c);
			}
		}
	else if(a>='0'&&a<='9'&&b>='0'&&b<='9'&&a<b)
		{
			for(char c=a+1;c<b;c++)
			{
				printf("%c",c);
			}
		}
	else 
	{
		printf("-");
		return;
	}
}
int main()
{
	char a[10000];
	while(gets(a)!=NULL)
	{
		int t=strlen(a);
		for(int i=0;i<t;i++)
		{
			if(a[i]=='-')
			{
				delete1(a[i-1],a[i+1]);
			}
			else
			{
			printf("%c",a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}

