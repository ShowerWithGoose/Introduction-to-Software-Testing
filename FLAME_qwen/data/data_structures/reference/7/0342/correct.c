/*
 * @Author:
 * @Date: 2022-04-28 20:15:57
 * @LastEditors:
 * @LastEditTime: 2022-04-28 20:28:29
 * @FilePath: bst.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 100010

typedef struct Node
{
    int key;
    struct Node *ls, *rs;
}Node;
Node *root=NULL;

Node *new_node(int x)
{
    Node *ret = (Node *)malloc(sizeof(Node));
    ret->key = x;
    ret->ls = NULL;
    ret->rs = NULL;
    return ret;
}

void add(Node **u, int x)
{
    if(*u == NULL)
    {
        *u = new_node(x);
        return;
    } 
    if(x < (*u)->key)
        add((&(*u)->ls), x);
    else
        add(&((*u)->rs), x);
    return;
}

void dfs(Node *u, int deep)
{
    if(u == NULL) return;
    if(u->ls == NULL && u->rs == NULL)
    {
        printf("%d %d\n",u->key,deep);
        return;
    }
    dfs(u->ls,deep+1);
    dfs(u->rs,deep+1);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1,x;i<=n;++i)
    {
        scanf("%d",&x);
        add(&root,x);
    }
    dfs(root,1);
    return 0;
}
