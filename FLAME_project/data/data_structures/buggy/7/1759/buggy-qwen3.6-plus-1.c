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
    print_tree(now<<1); // @@ The traversal order is incorrect. To output leaf nodes from left to right, the recursive call for the left child must happen before checking/printing the current node or traversing the right child if we were doing in-order, but specifically for "left-to-right" leaf output in a BST, an in-order traversal (Left, Root, Right) ensures nodes are visited in sorted order. However, the current code checks if the *current* node is a leaf and prints it, then recurses left, then right. This is Pre-order. In a BST, Pre-order does not guarantee left-to-right spatial order of leaves if the tree structure varies, but more importantly, the standard "left to right" usually implies In-Order traversal for BSTs to get sorted values, or simply that we visit left subtree fully before right. The current code prints the current node if it's a leaf BEFORE recursing into children. Wait, if it's a leaf, it has no children, so recursion does nothing. The issue is the order of processing relative to siblings. Actually, the main issue is likely that `print_tree` visits Root, then Left, then Right. For a BST, Left-To-Right leaf order corresponds to In-Order traversal (Left, Root, Right). The current implementation is Pre-Order (Root, Left, Right). While Pre-Order visits left before right, it processes the root before the left subtree. If the root is a leaf (single node), it prints it. If not, it goes left. The critical error is usually that students confuse traversal orders. Let's look at the expected output: 0, 136, 157... These are sorted. In-order traversal of a BST yields sorted values. The current code is Pre-order. It should be In-order: recurse left, process current, recurse right.
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