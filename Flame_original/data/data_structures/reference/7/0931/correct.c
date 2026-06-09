#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node{
    int item;
    struct node*ly;
    struct node*lr;
};
struct node *head;
void gz(int t)
{
    struct node *p,*a;
    a=head;
   p=(struct node*) malloc(sizeof( struct node));
   p->item=t;
   p->ly=NULL;
   p->lr=NULL;
   while (a!=NULL)
   {
       if (t<a->item) {
           if (a->ly==NULL)
           {
               a->ly=p;
               break;
           }
           else a=a->ly;
       }
       else {
           if (a->lr==NULL)
           {
               a->lr=p;
               break;
           }
           else a=a->lr;
       }
   }
}
void sc(struct node *p,int h)
{
    if (p->ly==NULL&&p->lr==NULL)
{
        printf("%d %d\n",p->item,h);
        return;
}
    if (p->ly!=NULL) sc(p->ly,h+1);
    if (p->lr!=NULL) sc(p->lr,h+1);
}
int main() {
    int n,i,t;
    scanf("%d",&n);
    scanf("%d",&t);
    head=(struct node*) malloc(sizeof(struct node));
    head->item=t;
    head->ly=NULL;
    head->lr=NULL;
    for (i=2;i<=n;i++)
    {
        scanf("%d",&t);
        gz(t);
    }
    sc(head,1);
    return 0;
}


