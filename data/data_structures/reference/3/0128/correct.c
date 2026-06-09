#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets(a);
	int n=strlen(a);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		if(a[i]=='.')
		{
			j=i;
			break;
		}
	}
	if(a[0]=='0')
	{
		for(i=0;i<n;i++)
		{
			if(a[i]!='0'&&a[i]!='.')
			{
				k=i;
				break;
			}
		}
		if(k+1==n)
		{
			printf("%ce-%d",a[k],k-1);
		}
		else if(k+1<n)
		{
			printf("%c",a[k]);
			printf(".");
			for(i=k+1;i<n;i++)
			{
				printf("%c",a[i]);
			}
			printf("e");
			printf("-%d",k-1);
		}
	}
	else
	{
		printf("%c.",a[0]);
		for(i=1;i<n;i++)
		{
			if(a[i]=='.')
			{
				i++;
			}
			printf("%c",a[i]);			
		}
		printf("e");
		printf("%d",j-1);
	}
	return 0;
}

