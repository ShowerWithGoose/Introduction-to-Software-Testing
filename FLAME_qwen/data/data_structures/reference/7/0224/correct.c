#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int depth;
    struct node *left, *right;
}BTNode,*BTNodeptr;
BTNodeptr build(BTNodeptr root,int temp,int len); 
void print(BTNodeptr root);
int main()
{
    BTNodeptr root=NULL;
    int n,temp,i,len;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d", &temp);
        len=0;
        root=build(root,temp,len);
    }
    print(root);
    return 0;
}
BTNodeptr build(BTNodeptr t,int temp,int len)
{
    len++;
    if (t==NULL)
    {
        t=(BTNodeptr)malloc(sizeof(BTNode));
        t->data=temp;
        t->left=t->right=NULL;
        t->depth=len;
    }
    else if (temp<t->data)
        t->left=build(t->left,temp,len);
    else if (temp>=t->data)
        t->right=build(t->right,temp, len);
    return t;
}
void print(BTNodeptr t)
{
    if (t)
    {
        if(t->left==NULL&&t->right==NULL)
        {
            printf("%d %d\n", t->data,t->depth);
        }
        print(t->left);
        print(t->right);
    }
}





