#define MAXN 110
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>
int max(int a,int b)
{
    return a>b?a:b;
}
int n;
struct Node
{
    int stx,sty,edx,edy;
}l[MAXN]={};
int cmp(const void *a,const void *b)
{
    return ((struct Node *)a)->stx-((struct Node *)b)->stx;
}
int ans=0,px=0,py=0;
int dfs(int now)
{
    //printf("%d : %d %d\n",now,l[now].stx,l[now].sty);
    int ret=0;
    for(int i=1;i<=n;i++)
    {
        if(l[i].stx==l[now].edx && l[i].sty==l[now].edy) // @@ [Missing y-coordinate check when matching endpoints; only x is compared, which may connect segments that don't actually share the same endpoint]
        {
            ret=max(ret,dfs(i)+1);
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&l[i].stx,&l[i].sty,&l[i].edx,&l[i].edy);
    }
    //qsort(l+1,n,sizeof(struct Node),cmp); // @@ [Sorting is commented out, causing DFS to potentially miss optimal paths due to unsorted input; without sorting by start x, the DFS may not correctly chain segments in increasing x order]
    for(int i=1;i<=n;i++)
    {
        int cnt=dfs(i)+1;
        if(ans<cnt)
        {
            ans=cnt;
            px=l[i].stx;
            py=l[i].sty;
        }
    }
    printf("%d %d %d\n",ans,px,py);
    return 0;
}