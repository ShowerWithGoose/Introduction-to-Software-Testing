#include <stdio.h>
#include <string.h>
int main()
{
	char ex[100]="";
	gets(ex);
	int i,j;
	char k;
	for(i=1;i<=strlen(ex);i++)
	{
		printf("%c",ex[i-1]);
		if(ex[i]=='-')
		{
			if(ex[i-1]>=48&&ex[i-1]<=57&&ex[i+1]>=48&&ex[i+1]<=57&&ex[i-1]<ex[i+1])
			{
				for(k=ex[i-1]+1;k<ex[i+1];k++)
					printf("%c",k);
				i=i+1;
			}
			else if(ex[i-1]>=65&&ex[i-1]<=90&&ex[i+1]>=65&&ex[i+1]<=90&&ex[i-1]<ex[i+1])
			{
				for(k=ex[i-1]+1;k<ex[i+1];k++)
					printf("%c",k);
				i=i+1;
			}
			else if(ex[i-1]>=97&&ex[i-1]<=122&&ex[i+1]>=97&&ex[i+1]<=122&&ex[i-1]<ex[i+1])
			{
				for(k=ex[i-1]+1;k<ex[i+1];k++)
					printf("%c",k);
				i=i+1;
			}
			else
			{
				printf("%c",ex[i]);
				i=i+1;
			}
		}
	}
	return 0;
}



