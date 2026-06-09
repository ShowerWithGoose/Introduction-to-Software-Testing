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
    if(!tree[1].num) // @@ [Error: Using num==0 as empty indicator; 0 is a valid input value, so root may be incorrectly treated as empty]
    {
        tree[1].num=x;
        tree[1].h=1;
        return ;
    }
    while(tree[now].num) // @@ [Error: This condition treats a node with value 0 as empty, causing traversal to stop early or overwrite nodes]
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
    if(!tree[now].num) return ; // @@ [Error: This check treats a node with value 0 as empty, so the leaf with value 0 is never printed]
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h);
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