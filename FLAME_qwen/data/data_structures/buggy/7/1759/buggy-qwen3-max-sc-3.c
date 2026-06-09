#define MAXN 100010
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
struct Node
{
    int num,h;
}tree[MAXN*4];
void new_node(int x)
{
    int now=1,lst;
    if(!tree[1].num)
    {
        tree[1].num=x;
        tree[1].h=1;
        return ;
    }
    while(tree[now].num)
    {
        lst=now;
        if(tree[now].num>x) now=now<<1;
        else now=now<<1|1;
    }
    tree[now].num=x;
    tree[now].h=tree[lst].h+1;
    return ;
}
void print_tree(int now)
{
    //printf("%d\n",tree[now].num);
    if(!tree[now].num) return ;
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h); @@ [Using 'and' instead of '&&' may not be supported in all compilers without including <iso646.h>, but even with it, some environments might not recognize it correctly; however, the real issue is that the array-based tree can access out-of-bound indices when n is large, leading to undefined behavior. But more critically, the condition for leaf node fails when zero values are inserted because the tree uses zero to indicate empty nodes, so inserting 0 will be treated as an empty node.]
    print_tree(now<<1);
    print_tree(now<<1|1);
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        new_node(x);
    }
    print_tree(1);
    return 0;
}