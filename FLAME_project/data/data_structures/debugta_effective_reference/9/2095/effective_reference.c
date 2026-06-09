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
int n;
struct point
{
    int x,y;
};
struct line
{
    struct point st,b;
};
int n;
struct line st[105];
int head[105];
int pd(struct point i,struct point j)
{
    if(i.x!=j.x) return 0;
    if(i.y!=j.y) return 0;
    return 1;
}
int ans;
int X,Y;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        st[i].st.x=read();
        st[i].st.y=read();
        st[i].b.x=read();
        st[i].b.y=read();
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(pd(st[i].b,st[j].st))head[i]=j;
        }
    for(int i=1;i<=n;i++)
    {
        int now=1,x=i;
        while(head[x]!=0)
        {
            now++;
            x=head[x];
        }
        if(now>ans)
        {
            ans=now;
            X=st[i].st.x;
            Y=st[i].st.y;
        }
    }
    printf("%d %d %d\n",ans,X,Y);
	return 0;
}

