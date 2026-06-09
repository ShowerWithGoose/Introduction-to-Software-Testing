#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
struct node

{
    struct node *left;
    int data;
    int height;
    struct node *right;
};
struct node *root;
int flag=1;
struct node *add(struct node *knot,int num,int len)
{
    len++;
    if(knot==NULL)
    {
        knot=(struct node *)malloc(sizeof(struct node));
        knot->data=num;
        knot->left=NULL;
        knot->right=NULL;
        if(flag==1)
        {
            root=knot;
            flag=0;
        }
        knot->height=len;
    }
    else if(num<knot->data)
    {
        knot->left=add(knot->left,num,len);
    }
    else if(num>=knot->data)
    {
        knot->right=add(knot->right,num,len);
    }
    return knot;
}
void output(struct node *root)
{
    if(root!=NULL)
    {
        if((root->left==NULL)&&(root->right==NULL))
        {
            printf("%d %d\n",root->data,root->height);
        }
        output(root->left);
        output(root->right);
    }
}
int main()
{
    struct node *knot=NULL;
    int n,i,len=0,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num);
        knot=add(knot,num,len);
    }
    output(root);
    return 0;
}

