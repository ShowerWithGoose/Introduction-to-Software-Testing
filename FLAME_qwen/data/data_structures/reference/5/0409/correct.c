#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coe;
    int pow;
    struct node *link;
};
typedef struct node Node;
typedef struct node *Nodeptr;
Nodeptr list,p,r,q,list1,p1,q1,r1;
int i,j,a,b;
char c;
int main()
{

    p=list=NULL;
    while(1)
    {
        scanf("%d%d%c",&a,&b,&c);
        r=(Nodeptr)malloc(sizeof(Node));
        r->coe=a;
        r->pow=b;
        r->link=NULL;
        if(list==NULL)
            list=p=r;
        else
        {
            p->link=r;
            p=p->link;
        }
        if(c=='\n')
            break;
    }//将第一个多项式读入链表
    p1=list1=NULL;
    while(1)
    {
        scanf("%d%d%c",&a,&b,&c);
        //r=(Nodeptr)malloc(sizeof(Node));
        //r->coe=a;
        //r->pow=b;
        //r->link=NULL;
        for(p=list;p!=NULL;p=p->link)
        {
            r1=(Nodeptr)malloc(sizeof(Node));
            r1->coe=a*(p->coe);
            r1->pow=b+(p->pow);
            r1->link=NULL;
            if(list1==NULL)
                list1=r1;
            else
            {
                for(p1=list1;p1!=NULL;p1=p1->link)
                {
                    //if(r1->pow>p1->pow)
                    //{
                        //if(p1==list1)
                        //{
                            //r1->link=list1;
                            //list1=r1;
                        //}
                        //else
                        //{
                            //r1->link=p1;
                            //q1->link=r1;
                            //break;
                        //}

                    //}
                    if(p1->link!=NULL&&r1->pow<p1->pow&&r1->pow>(p1->link)->pow)
                    {
                        r1->link=p1->link;
                        p1->link=r1;
                        break;
                    }
                    else if(p1->link==NULL&&r1->pow<p1->pow)
                    {
                        p1->link=r1;
                        break;
                    }
                    else if(r1->pow==p1->pow)
                        {
                            p1->coe+=r1->coe;
                            break;
                        }
                }
            }
        }
        if(c=='\n')
            break;
    }
    for(p=list1;p!=NULL;p=p->link)
        printf("%d %d ",p->coe,p->pow);
    return 0;


}

