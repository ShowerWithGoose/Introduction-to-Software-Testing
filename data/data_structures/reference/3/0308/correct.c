#include<stdio.h>
#include<string.h>
int main()
{
	char a[2000000];
	gets(a);
	int i,n,k;
	n=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!='.')
			n++;
		else
			break;
	}
	if(n>1)
	{
		printf("%c.",a[0]);
		for(i=1;i<n;i++)
			printf("%c",a[i]);
		for(i=n+1;i<strlen(a);i++)
			printf("%c",a[i]);
		printf("e%d",n-1);
	}
	if(n==1)
	{
		if(a[0]=='0')
		{
			k=0;
			for(i=2;i<strlen(a);i++)
			{
				if(a[i]=='0')
					k++;
				else
					break;
			}
			printf("%c",a[k+2]);
			if(a[k+3]!='\0')
			{
				printf(".");
				for(i=k+3;i<strlen(a);i++)
					printf("%c",a[i]);
			}
			printf("e-%d",k+1);
		}
		else
		{
			for(i=0;i<strlen(a);i++)
				printf("%c",a[i]);
			printf("e0");
		}
	}
	return 0;
}

