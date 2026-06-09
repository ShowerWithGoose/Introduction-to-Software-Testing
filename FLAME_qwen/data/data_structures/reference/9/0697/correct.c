#include<stdio.h>
#include<string.h>
typedef struct 
{
    int x1,y1,x2,y2;
    #define x1(x) l[x].x1
    #define x2(x) l[x].x2
    #define y1(x) l[x].y1
    #define y2(x) l[x].y2
}LINE;
LINE l[205],tem;
int n,f[205];

int max(int a,int b){return a>b?a:b;}
int cal(LINE a,LINE b)
{
    if(a.x1<b.x1)return 1;
    return -1;
}
int pd(LINE a,LINE b){return (a.x2==b.x1&&a.y2==b.y1);}
signed main()
{
    // freopen("data.in","r",stdin);

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d%d%d%d",&x1(i),&y1(i),&x2(i),&y2(i));


    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        if(cal(l[i],l[j])==-1)
            tem=l[i],l[i]=l[j],l[j]=tem;

    // for(int i=1;i<=n;i++)printf("%d %d\n",x1(i),y1(i));

    for(int i=1;i<=n;i++)f[i]=1;
    for(int i=n;i;i--)
        for(int j=i+1;j<=n;j++)
        if(pd(l[i],l[j]))
            f[i]=max(f[i],f[j]+1);
    
    int maxn=0,maxx;
    for(int i=1;i<=n;i++)
    if(f[i]>maxn)
        maxn=f[i],maxx=i;
    
    printf("%d %d %d\n",maxn,x1(maxx),y1(maxx));
}
