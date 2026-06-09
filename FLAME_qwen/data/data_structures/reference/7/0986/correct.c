#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
    int data;
    int h;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
void perorder(BTNodeptr m)
{
    if(m!=NULL)
    {
        if(m->left==NULL&&m->right==NULL)
        {
            printf("%d %d\n",m->data,m->h);
        }
        perorder(m->left);
        perorder(m->right);
    }
}
void insertBST(int item)
{
    BTNodeptr p,q;
    p=(BTNodeptr)malloc(sizeof(BTNode));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        p->h=1;
        root=p;
    }
    else
    {
        q=root;
        while(1)
        {
            if(item<q->data)
            {
                if(q->left==NULL)
                {
                    p->h=q->h+1;
                    q->left=p;
                    break;
                }
                else
                {
                    q=q->left;
                }
            }
            else if(item>=q->data)
            {
                if(q->right==NULL)
                {
                    p->h=q->h+1;
                    q->right=p;
                    break;
                }
                else
                {
                    q=q->right;
                }
            }
        }
    }
    
} 
int main()
{
    int i,n,item;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        insertBST(item);
    }
    perorder(root);
    return 0;
}
