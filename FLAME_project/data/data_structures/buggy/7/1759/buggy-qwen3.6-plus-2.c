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
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h);
    print_tree(now<<1); // @@ The traversal order is incorrect. It should traverse the left subtree, then check/print current node (if leaf), then traverse right subtree to ensure left-to-right output of leaves. Currently, it checks the current node before traversing children, which is fine for identifying leaves, but the recursive calls are placed after the check. However, the standard in-order traversal for "left-to-right" usually implies visiting left child, then node, then right child. For leaves specifically, an in-order traversal (Left, Node, Right) ensures that leaves are printed in ascending order of their position in the BST. The current implementation does Pre-order (Node, Left, Right) relative to the leaf check? No, it checks if current is leaf, then goes left, then right. This is effectively a Pre-order traversal for the printing action. In a BST, left-to-right leaf order corresponds to In-Order traversal. We should traverse left, then check/print if leaf, then traverse right.
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