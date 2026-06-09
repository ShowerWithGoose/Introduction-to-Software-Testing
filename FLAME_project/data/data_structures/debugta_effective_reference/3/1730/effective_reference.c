#include<stdio.h>
#include<string.h>
int main()
{
	char num[100],put[100];
	gets(num);
	int p,zheng=0;
	for(p=1;num[p]!='.';p++)
		zheng++;
	if(num[0]!='0')
	{
		put[0]=num[0];
		put[1]='.';
		int newl=2;
		for(p=1;num[p]!='\0';p++)
		{
			if(num[p]!='.')
			put[newl++]=num[p];
		}
		put[newl]='\0';
		printf("%se%d",put,zheng);
	}
	else
	{
		zheng=0;
		for(p=2;num[p]=='0';p++)
		zheng++;
		int a=p,b=1;
		put[0]=num[p];
		if(num[p+1]!='\0')
		{
		put[1]='.';
		b=2;
		}
		for(p=a+1;num[p]!='\0';p++)
		put[b++]=num[p];
		put[b]='\0';
		printf("%se%d",put,-zheng-1);
	}
	return 0;
}

