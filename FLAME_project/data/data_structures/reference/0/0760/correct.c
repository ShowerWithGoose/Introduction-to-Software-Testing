#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000];
	int b,i,k;
	gets(a);
	b=strlen(a);
	for(i=0;i<b;i=i+1)
	{
		if(a[i]==45)
		{
			if(a[i-1]>=48&&a[i-1]<=57&&a[i+1]>=48&&a[i+1]<=57)
			{
				if(a[i-1]<a[i+1])
				{
					for(k=a[i-1]+1;k<a[i+1];k=k+1)
					printf("%c",k);
				}
				else printf("%c",45);
			}
			else if(a[i-1]>=65&&a[i-1]<=90&&a[i+1]>=65&&a[i+1]<=90)
			{
				if(a[i-1]<a[i+1])
				{
					for(k=a[i-1]+1;k<a[i+1];k=k+1)
					printf("%c",k);
				}
				else printf("%c",45);
			}
			else if(a[i-1]>=97&&a[i-1]<=122&&a[i+1]>=97&&a[i+1]<=122)
			{
				if(a[i-1]<a[i+1])
				{
					for(k=a[i-1]+1;k<a[i+1];k=k+1)
					printf("%c",k);
				}
				else printf("%c",45);
			}
			else
			printf("%c",45);
		}
		else
		printf("%c",a[i]);
	}
	return 0;
}



