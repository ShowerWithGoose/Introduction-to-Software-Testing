#include<stdio.h>
#include<string.h> 
int main()
{
	char a[1000];
	gets(a);
	if(a[0]=='0')
	{
		int b,c,d,i,j;
		for(i=1;i<=strlen(a)-1;i++)
		{
			if(a[i]=='.')
			{
				b=i;
				continue;
			}
			else if(a[i]!='0')
			{
				c=i;
				break;
			}
		}
		for(j=c;j<=strlen(a)-1;j++)
		{
			printf("%c",a[j]);
			if(strlen(a)-1-c>=1&&j==c)
			printf(".");
		}
		printf("e-%d",c-b);
	}
	else
	{
		int b,c,d,i,j;
		for(i=1;i<=strlen(a)-1;i++)
		{
			if(a[i]=='.')
			{
				b=i;
				break;
			}
		}
		for(j=0;j<=strlen(a)-1;j++)
		{
			if(a[j]!='.')
			printf("%c",a[j]);
			if(strlen(a)-1>=1&&j==0)
			printf(".");
		}
		printf("e%d",b-1);
	}
	return 0;
}



