#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s[5005];
char a[5005];
int main()
{
	scanf("%s",s);
	int k=0,d=1,u=0,flag=0,fl=0;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='.')
		{
			flag=1;
			continue;
		}
		if(flag==0)
		{
			if(k!=0||s[i]!='0')
				a[k++]=s[i];
		}
		else
		{
			if(s[i]!='0')
			{
				fl=1,a[k+u]=s[i];
				u++;
			}
			else if(fl==0&&s[i]=='0')
				d++;
			else if(fl=1)
			{
				a[k+u]=s[i];
				u++;
			}
		}
	}
//	printf("%d %d %d\n",k,d,u);
	if(k==0)
	{
		if(u==1)
			printf("%c",a[k]);
		else
		{
			printf("%c.",a[k]);
			for(int i=k+1;i<k+u;i++)
				printf("%c",a[i]);
		}
		printf("e-%d",d);
	}
	else if(k==1)
	{
		printf("%se0",s);
	}
	else
	{
		printf("%c.",a[0]);
		for(int i=1;i<k;i++)
			printf("%c",a[i]);
		for(int i=0;i<d-1;i++)
			printf("0");
		for(int i=k;i<k+u;i++)
			printf("%c",a[i]);
		printf("e%d",k-1);
	}
	return 0;
}

