#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char c[9000000];

int main()
{
	int i,flag=0;
	char a,cfl; 
	gets(c);
	for(i=0;i<strlen(c);i++)
	{
		cfl=c[i];
		if(flag==1)
		{
			flag=0;
			if((a<c[i])&&((a>='0'&&a<='9'&&c[i]>='0'&&c[i]<='9')||(a>='A'&&a<='Z'&&c[i]>='A'&&c[i]<='Z')||(a>='a'&&a<='z'&&c[i]>='a'&&c[i]<='z')))			
			{
				int t;
				for(t=a+1;t<=c[i];t++)
				{
					printf("%c",t);
				}
			}
			else
			{
				printf("-%c",c[i]);
			}
			a=c[i];
		}
		else
		{
			if(c[i]!='-')
			{
				a=c[i];
				printf("%c",a);
			}
			else
			{
				flag=1;
			}
		}
	}
	if(cfl=='-')
	{
		printf("-");
	}
}

