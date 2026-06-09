#include<stdio.h>
int main()
{
	char c[105];
	int n;
	gets(c);
	if(c[0]=='0')
	{
		for(int i=0;c[i]=='0'||c[i]=='.';i++)
		{
			n=i;
		}
		n=n+1;
		if(c[n+1]=='\0')
			printf("%ce-%d",c[n],n-1);
		else
		{
			printf("%c.",c[n]);
			for(int i=n+1;c[i]!='\0';i++)
				printf("%c",c[i]);
			printf("e-%d",n-1);
		}
	}
	else
	{
		for(int i=0;c[i]!='.';i++)
		{
			n=i;
		}
		printf("%c.",c[0]);
		for(int i=1;i<=n;i++)
			printf("%c",c[i]);
		for(int i=n+2;c[i]!='\0';i++)
			printf("%c",c[i]);
		printf("e%d",n);
	}
	return 0;
} 

