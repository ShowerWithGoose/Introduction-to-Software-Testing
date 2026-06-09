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
#define N 10005
typedef struct skr
{
    int x;
    struct skr *l,*r;
}skr;
skr *rt=NULL;
int head[N],cnt;
int v[N];
int n;
skr * init(int x)
{
    skr *p=(skr*)malloc(sizeof(skr));
    p->x=x;
    p->l=NULL;p->r=NULL;
    return p;
}
skr * build(skr *p,int x)
{
    if(p==NULL)
    {
        p=init(x);
        return p;
    }
    if(x<p->x) p->l=build(p->l,x);
    else p->r=build(p->r,x);
    return p;
} 
void dfs(skr *p,int d)
{
    if(p->l==NULL&&p->r==NULL)
    {
        printf("%d %d\n",p->x,d);
        return ;
    }
    if(p->l)dfs(p->l,d+1);
    if(p->r)dfs(p->r,d+1);
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        v[i]=read();
        rt=build(rt,v[i]);
    }
    dfs(rt,1);
    return 0;
}


