#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct tree{
    int data;
    int deep;
    struct tree *lchild,*rchild;
}tree,*tree_ptr;
tree_ptr root;
int h;
tree_ptr create_node(int data_temp,int deep_temp)
{
    tree_ptr temp=(tree_ptr)malloc(sizeof(tree));
    temp->lchild=NULL;
    temp->rchild=NULL;
    temp->data=data_temp;
    temp->deep=deep_temp;
    return temp;
}
tree_ptr insert(tree_ptr nroot,int temp)
{
    h++;
    if(nroot==NULL)
	{
        nroot=create_node(temp,h);
    }
    else if(temp<nroot->data)
	{
        nroot->lchild=insert(nroot->lchild,temp);
    }
    else if(temp>=nroot->data)
	{
        nroot->rchild=insert(nroot->rchild,temp);
    }
    return nroot;
}
void print(tree_ptr temp)
{
    if(temp->lchild)
	{
        print(temp->lchild);
    }
    if(is_leaf(temp))
        printf("%d %d\n",temp->data,temp->deep);
    if(temp->rchild){
        print(temp->rchild);
    }
}
int is_leaf(tree_ptr temp)
{
    if(temp->lchild==NULL&&temp->rchild==NULL)
	     return 1;
    else
        return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int temp,i;
    scanf("%d",&temp);
    root=create_node(temp,1);
    for(i=1;i<n;i++){
        scanf("%d",&temp);
        h=0;
        insert(root,temp);
    }
    print(root);
    return 0;
}



