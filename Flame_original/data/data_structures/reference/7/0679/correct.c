#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct node
{
    int num;
    struct node* left;
    struct node* right;
}list;
list *head=NULL,*last=NULL;
int tem;
list * insert(list *q);
void outp(list *u,int lv);
int main()
{
    int n=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&tem);
        head=insert(head);
    }
    outp(head,1);
    return 0;
}
list* insert(list *q)
{
    if(q==NULL)
        {
            q=(list*)malloc(sizeof(list));
            q->num=tem;
            q->left=NULL;
            q->right=NULL;
            
        }
    else
    {
        if(tem<q->num)
        {
            q->left=insert(q->left);
        }
        else
        {
            q->right=insert(q->right);
        }
    }
    return q;
}

void outp(list *u,int lv)
{
    if(u!=NULL){
        outp(u->left,lv+1);
        outp(u->right,lv+1);
        if(u->left==NULL&&u->right==NULL)
        printf("%d %d\n",u->num,lv);
    }   
}
