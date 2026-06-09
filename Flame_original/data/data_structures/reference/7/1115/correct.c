#include<stdio.h>
#include<stdlib.h>

struct tree{
    int data;
    struct tree* left,*right;
    int flag;
    int high;
}*p,*q,*m,*list=NULL;

void insert(struct tree* p)
{
    m=list;
    while(1)
    {
        
       if((m->data)>(p->data))
       {
           if(m->left==NULL) 
           {
               m->left=p;
               m->flag=1;
               p->high=m->high+1;
               break;
           }else
           {
               m=m->left;
           }
       }else{
           if(m->right==NULL)
           {
               m->right=p;
               m->flag=1;
               p->high=m->high+1;
               break;
           }else{
               m=m->right;
           }
       }
        
    }
}
void visit(struct tree *p)
{
    if(p==NULL) return;
    if(p->flag==0)
    {
        printf("%d %d\n",p->data,p->high);
    }
    return;
}
void perorder(struct tree* p)
{
    visit(p);
    if(p->left!=NULL) perorder(p->left);
    if(p->right!=NULL) perorder(p->right);
}


int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        p=(struct tree*)malloc(sizeof(struct tree));
        p->data=a;
        p->left=NULL;
        p->right=NULL;
        p->flag=0;
        if(list==NULL)
        {
            list=q=p;
            list->high=1;
        }else{
            insert(p);
        }
    }
    perorder(list);
}
