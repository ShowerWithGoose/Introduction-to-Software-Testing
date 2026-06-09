#include<stdio.h>
#include<string.h>
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char st[110000],cc[110000];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	gets(st+1);
	int len=strlen(st+1);
	int i,clen=0;
	for(i=1;i<=len;i++)
	{
		if(st[i]==' ') continue;
		cc[++clen]=st[i];
	}
	int ans=0,f=1,d=0;i=1;
	while(1)
	{
		int x=0;char ch=cc[i++];
		while(ch>='0'&&ch<='9')
		{
			x=x*10+ch-'0';
			ch=cc[i++];
		}
		if(ch=='-'||ch=='+'||ch=='=')
		{
			if(f==-1||f==1) ans+=x*f;
			else if(f==2) ans+=d*x;
			else if(f==-2) ans+=d/x;
			if(ch=='-') f=-1;
			if(ch=='+') f=1;
			if(ch=='=') break;
		}
		else
		{
			if(f==-1) d=-x;
			if(f==1) d=x;
			if(f==2) d*=x;
			if(f==-2) d=d/x;
			if(ch=='*') f=2;
			if(ch=='/') f=-2; 
		}
	}
	printf("%d\n",ans);
	return 0;
}


