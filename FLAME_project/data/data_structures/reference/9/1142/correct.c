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
    struct point a,b;
};
int n;
struct line a[105];
int nxt[105];
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
        a[i].a.x=read();
        a[i].a.y=read();
        a[i].b.x=read();
        a[i].b.y=read();
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(pd(a[i].b,a[j].a))nxt[i]=j;
        }
    for(int i=1;i<=n;i++)
    {
        int num=1,x=i;
        while(nxt[x]!=0)
        {
            num++;
            x=nxt[x];
        }
        if(num>ans)
        {
            ans=num;
            X=a[i].a.x;
            Y=a[i].a.y;
        }
    }
    printf("%d %d %d\n",ans,X,Y);
	return 0;
}

