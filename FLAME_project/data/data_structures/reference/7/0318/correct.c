#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node treenode,*treeptr;
treeptr insert(treeptr p,int value);
void preorder(treeptr r,treeptr t);
int count=0,flag=0;
int main()
{
    int n,i,value;
    scanf("%d",&n);
    treeptr root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        root=insert(root,value);
    }
    treeptr r=root;
    preorder(r,root);
    return 0;
}
treeptr insert(treeptr p,int value)
{
    if(p==NULL)
    {
        p=(treeptr)malloc(sizeof(treenode));
        p->data=value;
        p->left=p->right=NULL;
    } 
    else if(value<p->data)
        p->left=insert(p->left,value);
    else if(value>=p->data)
       p->right=insert(p->right,value);
    return p;
}
void preorder(treeptr r,treeptr t)
{
    if(t!=NULL)
    {
        flag=0;
        r=t;
        count++;
        preorder(r,t->left);
        preorder(r,t->right);
        count--;
    }
    else 
    {
        flag++;
        if(flag==2)
        {
            printf("%d %d\n",r->data,count);
        }
    }
}
