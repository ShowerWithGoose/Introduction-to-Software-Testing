#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
    int data;
    struct node *left,*right;
    int depth;
};
struct node *insertBTS(struct node *p,int item,int depth);
int i=1;
void inorder(struct node *p)
{
    
        if((p->left==NULL)&&(p->right==NULL)) // @@ [Missing NULL check for p at the beginning of the function. If p is NULL (e.g., when n=0), accessing p->left will cause a segmentation fault.]
        {
        printf("%d %d\n",p->data,p->depth);
        return;
    }
    if(p->left)
        inorder(p->left);
            if(p->right)
        inorder(p->right);

}
int main()
{
    int n,item;
    struct node *root=NULL;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&item);
        root=insertBTS(root,item,1);
    }
    inorder(root);
    return 0;
}
struct node *insertBTS(struct node *p,int item,int depth)
{
    if(p==NULL){
    
    p=(struct node *)malloc(sizeof(struct node));
    p->data=item;
    p->depth=depth;
    p->left=p->right=NULL;
}
else if(item<p->data)
p->left =insertBTS(p->left,item,depth+1);
else if(item>p->data) // @@ [The condition should be item>=p->data or simply else, because the problem states that the right child's value should be greater than or equal to the root's value. This misses handling duplicate values.]
p->right =insertBTS(p->right,item,depth+1);
return p;
}