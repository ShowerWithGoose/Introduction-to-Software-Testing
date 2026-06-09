#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    int deep;
    struct tree *lc,*rc;
}tree,*tree_ptr;
tree_ptr root;
int height;
tree_ptr create_node(int data_temp,int deep_temp);
tree_ptr add(tree_ptr now,int temp);
void print(tree_ptr temp);
int main()
{
    int n;
    scanf("%d",&n);
    int temp;
    scanf("%d",&temp);
    root=create_node(temp,1);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&temp);
        height=0;
        add(root,temp);
    }
    print(root);
    return 0;
}
tree_ptr create_node(int data_temp,int deep_temp)
{
    tree_ptr temp=(tree_ptr)malloc(sizeof(tree));
    temp->lc=NULL;
    temp->rc=NULL;
    temp->data=data_temp;
    temp->deep=deep_temp;
    return temp;
}
tree_ptr add(tree_ptr now,int temp)
{
    height++;
    if(now==NULL)
    {
        now=create_node(temp,height);
    }
    else if(temp<now->data)
    {
        now->lc=add(now->lc,temp);
    }
    else if(temp>=now->data)
    {
        now->rc=add(now->rc,temp);
    }
    return now;
}
void print(tree_ptr temp)
{
    int cnt;
    if(temp->lc)
    {
        print(temp->lc);
    }
    if(temp->lc==NULL&&temp->rc==NULL)
    {
        cnt=1;
    }
    else
    {
        cnt=0;
    }
    if(cnt)
    {
        printf("%d %d\n",temp->data,temp->deep);
    }
    if(temp->rc)
    {
        print(temp->rc);
    }
}


