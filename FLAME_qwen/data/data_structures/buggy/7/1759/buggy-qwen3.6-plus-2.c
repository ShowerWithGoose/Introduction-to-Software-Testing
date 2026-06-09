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
    if(!tree[now<<1].num and !tree[now<<1|1].num) printf("%d %d\n",tree[now].num,tree[now].h); // @@ [The 'and' operator is not a standard C operator. Although <iso646.h> provides it as a macro, it may cause compilation errors on some compilers or strict standards. It should be replaced with '&&'.]
    print_tree(now<<1);
    print_tree(now<<1|1);
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++) // @@ [Declaring variables inside the for-loop initialization is a C99 feature. Compiling with C89/C90 standards will cause an error. Declare 'i' and 'x' before the loop.]
    {
        scanf("%d",&x);
        new_node(x);
    }
    print_tree(1);
    return 0;
}