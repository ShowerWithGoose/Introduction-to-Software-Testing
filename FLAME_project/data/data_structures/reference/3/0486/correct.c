#include<stdio.h>
#include<string.h>
int main()
{
	char a[200];
	int i,dian,len,n,m;
	
	gets(a);
	len=strlen(a);
	
	for(i=0;;i++)
	{
		if(a[i]=='.')
		{
			dian=i;
			break;
		}
	}
	
	if(a[0]=='0')
	{
		for(i=2;;i++)
		{
			if(a[i]!='0')
			{
				n=i;
				break;
			}
		}
		
		printf("%c",a[n]);
		if(len==(n+1))
		{
			printf("e");
			printf("-%d",n-1);
		}
		else
		{
			printf(".");
			for(i=(n+1);i<len;i++)
			{
				printf("%c",a[i]);
			}
			printf("e");
			printf("-%d",n-1);
		}
	}
	else
	{
		printf("%c",a[0]);
		printf(".");
		for(i=1;i<len;i++)
		{
			if(a[i]!='.')
			{
				printf("%c",a[i]);
			}
		}
		printf("e");
		printf("%d",dian-1);
	}
}








