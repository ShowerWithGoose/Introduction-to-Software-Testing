#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coe;
    int pow;
    struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
int main()
{
    int i,n,a,b;
    char c;
    Nodeptr list1=NULL,list2=NULL,list3=NULL,p,q,p1,p2,p3,r;
    while(c!='\n')
    {
        q=(Nodeptr)malloc(sizeof(Node));
        scanf("%d%d%c",&a,&b,&c);
        q->coe=a;
        q->pow=b;
        q->link=NULL;
        if(list1==NULL)
            list1=p=q;
        else
            p->link=q;
        p=q;
    }
    c='\0';
    while(c!='\n')
    {
        scanf("%d%d%c",&a,&b,&c);
        p1=list1;
        while(p1!=NULL)
        {
            q=(Nodeptr)malloc(sizeof(Node));
            q->coe=a*p1->coe;
            q->pow=b+p1->pow;
            q->link=NULL;
            for(r=p=list2;p!=NULL&&p->pow>q->pow;r=p,p=p->link)
            {}
            if(p==list2)
            {
                q->link=list2;
                list2=q;
            }
            else if(p==NULL)
            {
                r->link=q;
            }
            else if(p->pow==q->pow)
            {
                p->coe+=q->coe;
            }
            else if(p->pow<q->pow)
            {
                q->link=p;
                r->link=q;
            }
            p1=p1->link;
        }
    }
    for(p=list2;p!=NULL;p=p->link)
        printf("%d %d ",p->coe,p->pow);
}



