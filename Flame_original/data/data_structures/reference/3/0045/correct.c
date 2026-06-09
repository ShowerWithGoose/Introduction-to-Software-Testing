#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char a[200];

int main()
{
	int i,flag,ans=0,n=0,ansf=0,td=0;
	gets(a);
	if(a[0]=='0')
	{
		flag=-1;
	}
	else
	{
		flag=1;
	}
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='.')
		{
			ans=i;
		}
		else if(a[i]=='0')
		{
			if(td==0)
				ansf++;
			else 
			{
				printf("0");
			}
		}
		else if(a[i]!='0'&&a[i]!='.')
		{
			td=1;
			printf("%c",a[i]);
			n++;
			if(n==1&&i!=strlen(a)-1)
			{
				printf(".");
			}
		}
	}
	if(flag==-1)
	{
		printf("e-%d",ansf);
	}
	else 
	{
		printf("e%d",ans-1);
	}
}



