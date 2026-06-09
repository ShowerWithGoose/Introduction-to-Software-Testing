#define MAXN 100010
#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
struct Node
{
    int num,h;
}tree[MAXN*4]; // @@ Array size is insufficient for a general BST using heap indexing; a skewed tree will cause out-of-bounds access.
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
        if(tree[now].num>x) now=now<<1; // @@ Heap indexing `now<<1` assumes a complete binary tree, which is incorrect for BST and leads to index overflow.
        else now=now<<1|1; // @@ Heap indexing `now<<1|1` assumes a complete binary tree, which is incorrect for BST and leads to index overflow.
    }
    tree[now].num=x;
    tree[now].h=tree[lst].h+1;
    return ;
}
void print_tree(int now)
{
    //printf("%d\n",tree[now].num);
    if(!tree[now].num) return ;
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h); // @@ Accessing children via heap indexing may exceed array bounds; `and` macro may cause compilation issues in strict C environments.
    print_tree(now<<1); // @@ Recursive call with heap index may exceed array bounds.
    print_tree(now<<1|1); // @@ Recursive call with heap index may exceed array bounds.
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++) // @@ Variable declaration inside `for` loop is not supported in C89/C90 standards, which may cause compilation errors.
    {
        scanf("%d",&x);
        new_node(x);
    }
    print_tree(1);
    return 0;
}