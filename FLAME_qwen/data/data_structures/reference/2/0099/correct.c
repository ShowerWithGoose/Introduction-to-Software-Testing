#include<stdio.h>
#include<string.h>
char str[100010],c[100010],d[100010],ch;
int a[100010],b[100010];
int work(int st,int ed)
{
	int i,ans=0;
	for(i=st;i<=ed;i++)
		{
			ans*=10;
			ans=ans+str[i]-'0';
		}return ans;
}
int w(int st,int ed)
{
	//printf("%d %d\n",st,ed);
	int i,ans=a[st];
	for(i=st;i<ed;i++)
		{
			if(c[i]=='/')ans=ans/a[i+1];
			if(c[i]=='*')ans=ans*a[i+1];
			//printf("%d %d\n",ans,a[i+1]);
		}
	return ans;
}
int pd(char ch){if(ch=='+'||ch=='-'||ch=='/'||ch=='*'||ch=='=')return 1;return 0;}
int main()
{
	int o=0,o2=0,o3=0,i,j,ans=0;
	while(1)
		{
			scanf("%c",&ch);
			if(isspace(ch))continue;
			str[++o]=ch;
			if(ch=='=')break;
		}int last=1;
	for(i=1;i<=o;i++)
		if(pd(str[i]))a[++o2]=work(last,i-1),last=i+1,c[o2]=str[i];
	last=1;
	for(i=1;i<=o2;i++)
		{
			if(c[i]=='-'||c[i]=='+'||c[i]=='=')b[++o3]=w(last,i),last=i+1,d[o3]=c[i];
		}
	ans=b[1];
	for(i=1;i<=o3;i++)
		{
			//printf("%d%c",b[i],d[i]);
			if(d[i]=='+')ans+=b[i+1];
			if(d[i]=='-')ans-=b[i+1];
			if(d[i]=='=')printf("%d",ans);
		}
}

