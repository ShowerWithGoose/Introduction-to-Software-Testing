#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	gets(a);
	int q=1,p;
	int m=0;
	if(a[0]=='0')
	{
		for(int i=2;a[i]=='0';i++)
		{
			q=i;
		}
		if(a[q+2]=='\0')
		{
			printf("%ce-%d",a[q+1],q);
		}
		else
		{
			printf("%c.",a[q+1]);
			for(int i=q+2;a[i]!='\0';i++)
			{
				printf("%c",a[i]);
			}
			printf("e-%d",q);
		}
		return 0;
	}//只有小数
	if(a[0]!=0)
	{
		for(int i=0;a[i]!='.'&&a[i]!='\0';i++)
		{
			p=i+1;
			q=i;
		}
		for(int i=0;a[i]!='\0';i++)
		{
			if(a[i]=='.')
			m++;
		}
		if(m==0)
		{
			printf("%c.",a[0]);
			for(int i=1;a[i]!='\0';i++)
			{
				printf("%c",a[i]);
			}
			printf("e%d",q);
			return 0;
		}
		else
		{
			printf("%c.",a[0]);
			for(int i=1;a[i]!='.';i++)
			{
				printf("%c",a[i]);
			}
			for(int i=p+1;a[i]!='\0';i++)
			{
				printf("%c",a[i]);
			}
			printf("e%d",q);
			return 0;
		}
	} 
}

