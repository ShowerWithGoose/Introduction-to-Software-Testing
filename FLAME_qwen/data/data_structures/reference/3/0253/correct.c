#include<stdio.h>
#include<string.h>
int main()
{
	char a[105];
	int l,f=1,x;
	scanf("%s",a);
	l=strlen(a);
	if(a[0]=='0') f=-1;
	for(int i=0;i<l;i++)
	if(a[i]=='.') x=i;
	if(f==1)
	{
		printf("%c.",a[0]);
		for(int i=1;i<l;i++)
		{
			if(a[i]=='.') continue;
			else printf("%c",a[i]);
		}
		printf("e%d",x-1);
		return 0;
	}
	else
	{
		for(int i=x+1;i<l;i++)
		if(a[i]!='0'){f=i;break;}
		if(f==l-1)
		{
			printf("%ce%d",a[f],x-f);
			return 0;
		}
		printf("%c.",a[f]);
		for(int i=f+1;i<l;i++)
		printf("%c",a[i]);
		printf("e%d",x-f);
		return 0;
	}
}

