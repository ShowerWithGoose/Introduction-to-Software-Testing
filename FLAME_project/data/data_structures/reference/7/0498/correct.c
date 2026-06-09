#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define maxline 1024
typedef struct node{
    int data;
    struct node *link;
    struct node *left;
    struct node *right;
}lnode,*linklist;
linklist create(int n);
int length(linklist list);
linklist tree_in(linklist root,int data);
int main()
{
    linklist root=NULL;
    int key[100];
    int n;
    scanf("%d",&n);
    int data,i=0;
    while(i<n)
    {
        scanf("%d",&key[i]);
        i++;
    }
    i=0;
    while(i<n)
    {
        data=key[i];
        root=tree_in(root,data);
        i++;
    }
    tree_scan(root,0);
    return 0;
}
linklist create(int n)
{
    linklist p,r,list=NULL;
    int a;
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        p=(linklist)malloc(sizeof(lnode));
        p->data=a;
        p->link=NULL;
        if(list==NULL)
        {
            list=p;
        }
        else
        {
            r->link=p;
        }
        r=p;
    }
    return(list);
}
int length(linklist list)
{
    int n=0;
    linklist p=list;
    while(p!=NULL)
    {
        n++;
        p=p->link;
    }
    return n;
}
linklist tree_in(linklist root,int data)
{
    linklist s;
    s=(linklist)malloc(sizeof(lnode));
    s->data=data;
    s->left=NULL;
    s->right=NULL;
    if(root==NULL)
    {
        root=s;
    }
    else
    {
        if(s->data>=root->data)
        {
            root->right=tree_in(root->right,s->data);
        }
        else
        {
            root->left=tree_in(root->left,s->data);
        }
    }
    return root;
}
void tree_scan(linklist root,int i)
{
    if(root==NULL)
    {
        return;
    }
    i++;
    tree_scan(root->left,i);
    if(root->left==NULL&&root->right==NULL)
    {
        printf("%d %d\n",root->data,i);
    }
    tree_scan(root->right,i);
}
int tree_search(linklist root,int data)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        if(root->data<=data)
        {
            return tree_search(root->right,data);
        }
        else
        {
            return tree_search(root->left,data);
        }
    }
    return 0;
}
//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）

