#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200
char s[MAX];
char num[MAX];
int cnt;
int main()
{
	int met_spot=0,met_notzero=0;
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]=='.')
		{
			met_spot=1;
		}
		if(!met_spot&&s[i]!='0')met_notzero=1;
	}
	met_spot=0;
	if(met_notzero)
	{
		cnt=-1;
		for(int i=0;i<=len-1;i++)
		{
			if(s[i]=='.')met_spot=1;
			else
			{
				if(!met_spot)cnt++;
			}
		}
		printf("%c",s[0]);
		printf(".");
		for(int i=1;i<=len-1;i++)
		{
			if(s[i]!='.')printf("%c",s[i]);
		}
		printf("e");
		printf("%d",cnt);
	}
	else
	{
		cnt=0;
		int flg=0,print_spot=0,num=0;
		for(int i=0;i<=len-1;i++)
		{
			if(s[i]=='0'&&!flg)cnt++;
			if(s[i]!='0'&&s[i]!='.')
			{
				flg=1;num++;
			}
		}
		if(num>1)print_spot=1;
		flg=0;
		int ddd=0;
		if(!print_spot)
		{
			for(int i=0;i<=len-1;i++)
			{
				if(s[i]!='0'&&s[i]!='.')printf("%c",s[i]);
			}
			printf("e-");
			printf("%d",cnt);
		}
		else
		{
			for(int i=0;i<=len-1;i++)
			{
				if(s[i]!='0'&&s[i]!='.')
				{
					flg=1;
					printf("%c",s[i]);
					if(!ddd)printf(".");
					ddd=1;
				}
				else if(s[i]=='0')
				{
					if(flg)printf("%c",s[i]);
				}
			}
			printf("e-");
			printf("%d",cnt);
		}
	}	
	return 0;
}

