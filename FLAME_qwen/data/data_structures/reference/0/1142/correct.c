#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define ll long long 
#define ull unsigned long long
int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
char st[10000005];
int n;
int main()
{
	scanf("%s",st);
	n=strlen(st);
	for(int i=0;i<n;i++)
	{
		if(st[i]=='-')
		{
			if((st[i-1]>='A'&&st[i-1]<='Z')&&(st[i+1]>='A'&&st[i+1]<='Z')&&st[i+1]>st[i-1])
			{
				for(int j=st[i-1]+1;j<st[i+1];j++)
					printf("%c",j);
			}
			else if((st[i-1]>='a'&&st[i-1]<='z')&&(st[i+1]>='a'&&st[i+1]<='z')&&st[i+1]>st[i-1])
			{
				for(int j=st[i-1]+1;j<st[i+1];j++)
					printf("%c",j);
				
			}
			else if((st[i-1]>='0'&&st[i-1]<='9')&&(st[i+1]>='0'&&st[i+1]<='9')&&st[i+1]>st[i-1])
			{
				for(int j=st[i-1]+1;j<st[i+1];j++)
					printf("%c",j);
			}
			else
			{
				printf("-");
			}
		}
		else
		{
			printf("%c",st[i]);
		}
	}
	return 0;
}

