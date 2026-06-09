#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,point;
	char a[10005];
	gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='.')
		point=i;
	}
	//point-1
	if(a[0]=='0'&&a[1]=='.')
	{
		for(i=2;i<=strlen(a);i++)
			if(a[i]!='0')
			{
				point=i;
				break;
			}
		if(point==strlen(a)-1)
		{
			printf("%ce-%d",a[strlen(a)-1],strlen(a)-2);
		}
		if(point!=strlen(a)-1)
		{
			for(i=point;i<strlen(a);i++)
			{
				if(i==point+1) printf(".");
				printf("%c",a[i]);
			}
			printf("e-%d",point-1);
		}
	}
	else
	{
		for(i=0;i<strlen(a);i++)
		{
			if(i==1) printf(".");
			if(i==point) continue;
			printf("%c",a[i]);
		}
		printf("e%d",point-1);
	}
}

