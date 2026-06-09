#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int d;
    int lc,rc,dep;
}node;
node tree[50];
int n,i,t;
void in(int x)
{
    if(tree[i].d<tree[x].d)
    {
        if(tree[x].lc==0)
        {
            tree[x].lc=i;
            tree[i].dep=tree[x].dep+1;
        }
        else
        in(tree[x].lc);
    }
    else
    {
        if(tree[x].rc==0)
        {
            tree[x].rc=i;
            tree[i].dep=tree[x].dep+1;
        }
        else
        in(tree[x].rc);
    }
}
void find(int x)
{
    if(tree[x].lc==0&&tree[x].rc==0)
    printf("%d %d\n",tree[x].d,tree[x].dep);
    else
    {
        if(tree[x].lc!=0)
        find(tree[x].lc);
        if(tree[x].rc!=0)
        find(tree[x].rc);
    }
}
signed main()
{
    scanf("%d",&n);
    scanf("%d",&tree[0].d);
    tree[0].dep=1;
    for(i=1;i<n;i++)
    {
        scanf("%d",&tree[i].d);
        in(0);
    }
    find(0);
    return 0;
}
