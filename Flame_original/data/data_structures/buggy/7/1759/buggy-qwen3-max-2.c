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
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h); @@ [The use of 'and' is invalid in standard C without including <iso646.h> properly or using &&; however, <iso646.h> is included, so this may compile in some environments but is non-portable and could cause compilation errors in strict C compilers that don't recognize 'and' as a keyword even with the header. Additionally, the condition checks for zero values to determine absence of children, but zero is a valid input value per problem statement, leading to logical errors where nodes with value 0 are treated as non-existent.]
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