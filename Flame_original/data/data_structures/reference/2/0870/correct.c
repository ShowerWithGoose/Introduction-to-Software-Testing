#include<stdio.h>
#include<string.h>
#include<ctype.h>
int ans=0;
int jiahao[30][2]={0};
//int chenhao[30][2]={0};
int shuzi[40]={0};
char s[100]={0};
char ss[100];
void count(int x)
{
	int h,j=shuzi[jiahao[x][1]+1];
	int fuhao=0;
	for(h=jiahao[x][1]+1;s[h]!='+'&&s[h]!='-'&&s[h]!='='&&s[h]!='\0';h++)
	{
		if(s[h]=='*')fuhao=1;
		if(s[h]=='/')fuhao=-1;
		if(isdigit(s[h])&&shuzi[h]!=-1)
		{
			if(fuhao==1)j*=shuzi[h];
			if(fuhao==-1)j/=shuzi[h];
			while(isdigit(s[h]))h++;h--;
		}
		
	}
	if(jiahao[x][0]==1)ans+=j;
	if(jiahao[x][0]==-1)ans-=j;
	
}
int main()
{
	int i,j=0,k=0,m=0,n=0;
	for(i=0;i<=39;i++)
	{
		shuzi[i]=-1;
	}
	gets(ss);
	int pig=0;int lek=strlen(ss);
	for(i=0;i<lek;i++)
	{
		if(ss[i]!=' ')s[pig++]=ss[i];
	}
	int len=strlen(s);
	for(i=0;i<len-1;i++)
	{
		if(s[i]=='+'){jiahao[j][1]=i;jiahao[j][0]=1;j++;}
		if(s[i]=='-'){jiahao[j][1]=i;jiahao[j][0]=-1;j++;}
		//if(s[i]=='*'){chenhao[m][1]=i;chenhao[m][0]=1;m++;}
	//	if(s[i]=='/'){chenhao[m][1]=i;chenhao[m][0]=-1;m++;}
		if(isdigit(s[i]))
		{
			int sum=0;int qq=i;
			for(;isdigit(s[i]);i++)
			{
				sum=10*sum+(s[i]-'0');
			}
			shuzi[qq]=sum;
			
			i--;
		}
	}
	int sta=shuzi[0];
	for(i=0;s[i]!='+'&&s[i]!='-'&&s[i]!='\0';i++)
	{
		if(s[i]=='*'&&shuzi[i+1]!=-1)sta*=shuzi[i+1];
		if(s[i]=='/'&&shuzi[i+1]!=-1)sta/=shuzi[i+1];
	}
	ans+=sta;
	for(i=0;i<j;i++)
	{
		count(i);
	}
	printf("%d",ans);
}

