#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int x,int y)
{
    return x>y?x:y;
}
typedef struct
{
    int x;
    int y;
}point;
typedef struct 
{
    point p1;
    point p2;
}line;
line l[50];
int cnt[50];
int equal(point x1,point x2)
{
    if(x1.x==x2.x&&x1.y==x2.y) return 1;
    else return 0;
}
int main()
{
    memset(cnt,sizeof(int),1); // @@ memset is used incorrectly; it sets bytes, not int values. Should use a loop to initialize cnt[i]=1.
    int res=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",l[i].p1.x,l[i].p1.y,l[i].p2.x,l[i].p2.y); // @@ Missing address-of operator & before each variable; should be &l[i].p1.x, etc.
    }
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        if(equal(l[j].p1,l[i].p2))
        {
            l[j].p1.x=l[i].p1.x;
            l[j].p1.y=l[i].p1.y;
            l[i].p2.x=l[j].p2.x;
            l[i].p2.y=l[j].p2.y;
            cnt[i]=cnt[i]+cnt[j];
            cnt[j]=cnt[i];
            res=max(res,cnt[i]);
        }
        else if(equal(l[j].p2,l[i].p1))
        {
            l[i].p1.x=l[j].p1.x;
            l[i].p1.y=l[j].p1.y;
            l[j].p2.x=l[i].p2.x;
            l[j].p2.y=l[i].p2.y;
            cnt[i]=cnt[i]+cnt[j];
            cnt[j]=cnt[i];
            res=max(res,cnt[i]);
        }
    }
    printf("%d",res); // @@ Output format missing the starting point coordinates; should print max, starting x, and starting y.
    return 0;
}