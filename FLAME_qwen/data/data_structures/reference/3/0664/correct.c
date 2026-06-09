#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int i,j,count=0,flag,flag2=0;
	gets(a);
	if(a[0]=='0')
	{
		for(i=2;i<=strlen(a);i++)
		{
			if(a[i]=='0')
			count++;
			if(a[i]!='0'&&a[i+1]!='\0')
			{
				printf("%c.",a[i]);
				for(j=i+1;j<=strlen(a)-1;j++)
				printf("%c",a[j]);
				break;
			}
			if(a[i]!='0'&&a[i+1]=='\0')
			{
			printf("%c",a[i]);
			break;
			}
		}
	printf("e-%d",count+1);
	}
	else if(a[0]!='0')
	{
		if(strlen(a)==1)
		{
		printf("%ce0",a[0]);
		return 0;
		}
		printf("%c.",a[0]);
		for(i=1;i<=strlen(a);i++)
		{
			if('0'<=a[i]&&a[i]<='9')
		{
				printf("%c",a[i]);
				count++;
		}
		if(a[i]=='.')
		{
		flag=count;
		flag2=1;
		}
		if(a[i]=='\0'&&flag2==0)
		{
		flag=count;
		break;
		}
	}
	printf("e%d",flag);
	}
	return 0;
}

