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
    if(!tree[1].num) // @@ This condition treats a node with value 0 as empty; if the root value is 0, the tree will not be initialized correctly.
    {
        tree[1].num=x;
        tree[1].h=1;
        return ;
    }
    while(tree[now].num) // @@ The loop stops when encountering a node with value 0, mistakenly treating it as an empty slot rather than an actual node.
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
    if(!tree[now].num) return ; // @@ Skips nodes with value 0, causing leaf 0 to be omitted from output.
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h); // @@ Same sentinel issue: children with value 0 would be considered empty.
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