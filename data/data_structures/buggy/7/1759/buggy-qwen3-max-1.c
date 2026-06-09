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
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h); @@ [The use of 'and' is from <iso646.h>, but some compilers may not support it without proper flags; however, the real issue is that this condition fails when one child is zero-initialized but the other isn't, leading to incorrect leaf detection. Also, the array-based tree assumes perfect binary tree indexing, which can skip nodes and misidentify leaves.]
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