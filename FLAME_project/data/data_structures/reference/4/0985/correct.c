#include<stdio.h>
#include<string.h>

int n=0;
struct string
{
	char str[505];
}s[30003];
int vis[30003];

void trans(int k)
{
	int j=0;
	char str[505];
	memset(str,0,sizeof(str));
	for(int i=0;i<strlen(s[k].str);i++)
	{
		if(s[k].str[i]>='A'&&s[k].str[i]<='Z')
			s[k].str[i]=s[k].str[i]-'A'+'a';
	}
	for(int i=0;i<strlen(s[k].str);i++)
	{
		if(s[k].str[i]>='a'&&s[k].str[i]<='z')
			str[j++]=s[k].str[i];
	}
	memset(s[k].str,0,sizeof(s[k].str));
	for(int i=0;i<j;i++)
		s[k].str[i]=str[i];
	return ;
}

int check(char x[],char y[])
{
	if(strlen(x)!=strlen(y))
		return 0;
	for(int i=0;i<strlen(x);i++)
		if(x[i]!=y[i])
			return 0;
	return 1;
}

int read(char s[])
{
	char ch;
	int m=0; 
	if(scanf("%c",&ch)!=1)
		return 0;
	while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	{
		s[m++]=ch;
		if(scanf("%c",&ch)!=1)
			return 0;
	}
	return 1;
}


int main()
{
	freopen("article.txt","r",stdin);
	while(read(s[n].str))n++;
	for(int i=0;i<n;i++)
		trans(i);
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n-1;i++)
		{
			if(strcmp(s[i].str,s[i+1].str)>0)
			{
				struct string tmp=s[i];
				s[i]=s[i+1];
				s[i+1]=tmp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(strlen(s[i].str)==0)
			vis[i]=-1;
		if(vis[i])	continue;
		vis[i]++;
		for(int j=i+1;j<n;j++)
			if(check(s[i].str,s[j].str))
			{
				vis[i]++;
				vis[j]=-1;
			}
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]>0)
			printf("%s %d\n",s[i].str,vis[i]);
	}
	return 0;
}

