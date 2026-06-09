#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    int a;
    int x;
    struct node *link;
};
int main()
{
    struct node *list1=NULL,*list2=NULL,*p=NULL,*q=NULL;
    char c;
    do
    {
        q=(struct node*)malloc(sizeof(struct node));
        scanf("%d %d%c",&(q->a),&(q->x),&c);
        q->link=NULL;
        if(list1==NULL)
        {
            list1=p=q;
        }
        else
        {
            p->link=q;
        }
        p=q;
    }while(c!='\n');
    
    do
    {        
        q=(struct node*)malloc(sizeof(struct node));
        scanf("%d %d%c",&(q->a),&(q->x),&c);
        q->link=NULL;    
        if(list2==NULL)
        {
            list2=p=q;
        }
        else
        {
            p->link=q;
        }
        p=q;
    }while(c!='\n');
    struct node *result=NULL;
    struct node *t1,*t2;
    for(t1=list1;t1!=NULL;t1=t1->link)
    {
        for(t2=list2;t2!=NULL;t2=t2->link)
        {
            
        }
    } // @@ [The multiplication logic is missing: the product terms are not computed or stored in the result list.]
    while(list1!=NULL)
    {
        p=list1;
        list1=list1->link;
        free(p);
    }
    while(list2!=NULL)
    {
        p=list2;
        list2=list2->link;
        free(p);
    }
    return 0;
}