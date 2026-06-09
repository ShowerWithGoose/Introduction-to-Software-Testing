#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *left,*right;
    int depth;
};
struct node* insert(struct node *p,int item,int layer)
{
    if(p==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node *));
        p->data=item;
        p->depth=layer;
        p->left=p->right=NULL;
    }
    else if(item<p->data){
        layer++;
        p->left=insert(p->left,item,layer);
    }
    else{
        layer++;
        p->right=insert(p->right,item,layer);
    }
    return p;
}
void postorder(struct node *t)
{
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        if(t->left==NULL && t->right==NULL)
        {
            printf("%d %d\n",t->data,t->depth);
        }
    }
}
int main()
{
    int n,i,item,layer;
    scanf("%d",&n);
    struct node *root=NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        layer=1;
        root=insert(root,item,layer);
    }
    postorder(root);
    return 0;
}

