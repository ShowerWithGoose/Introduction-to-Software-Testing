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
    memset(cnt,sizeof(int),1); // @@ The arguments for memset are in the wrong order. It should be memset(ptr, value, size). Here it is passing sizeof(int) as the value and 1 as the size, which fails to initialize the array correctly and may lead to undefined behavior or incorrect logic downstream. Additionally, cnt is not initialized to 1 for each element, which is required for counting segments.
    int res=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",l[i].p1.x,l[i].p1.y,l[i].p2.x,l[i].p2.y); // @@ scanf requires pointers to the variables where input will be stored. Missing '&' operators before l[i].p1.x, etc., causes a segmentation fault (Runtime Error) because it interprets the integer values as memory addresses.
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
    printf("%d",res);
    return 0;
}