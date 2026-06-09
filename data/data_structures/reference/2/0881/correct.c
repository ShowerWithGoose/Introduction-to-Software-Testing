#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int stacknum[10000];
int num[10000];
char stackchar[10000];
char lastchar[10000];
int main()
{
	char s;
	scanf("%c",&s);
	int i,j;
	i = j = 0;
	while(s!='=')
	{
		if(s<='9'&&s>='0')
		{
			int sum = 0;
			while(s>='0'&&s<='9')
			{
				sum = sum*10+s-'0';
				scanf("%c",&s);
			}
			stacknum[i++]=sum;
			continue;
		}
		else if(s!=' ')
		stackchar[j++] = s;
		scanf("%c",&s);
	}
	int lennum = i;
	int lenchar = j;
	i = j = 0;
	int t;
	for(t = 0; t < lenchar; t++)
	{
		while(stackchar[t]=='*'||stackchar[t]=='/')
		{
			if(stackchar[t]=='*')
			stacknum[t+1] *= stacknum[t];
			else
			stacknum[t+1] = stacknum[t]/stacknum[t+1];
			t++;
		}
	num[i]=stacknum[t];
	lastchar[i++] = stackchar[t];
	}
	num[i] = stacknum[t];
	for(t = 0; t <= i - 1; t++)
	{
		if(lastchar[t]=='+')
		num[t+1]+=num[t];
		else num[t+1] = num[t]-num[t+1];
	}
	printf("%d",num[t]);
}
