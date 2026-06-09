#include <stdio.h>
#include <stdlib.h>
//利用链表存储多项式的系数和指数
typedef struct node{
    int coe;//系数 
    int exp;//指数 
    struct node *next;
}multi;
int main()
{
    multi *r,*p,*q,*q0,*head;
    head=NULL;
    int c,e,flag=0,i=0,a[100],b[100];
    char ch;
    do{
        i++;
        scanf("%d%d%c",&c,&e,&ch);
        r=(multi*)malloc(sizeof(multi));
        if(head==NULL) head=p=r; 
        else
        {
            p->next=r;
            p=p->next; 
        }
        a[i]=p->coe=c;
        b[i]=p->exp=e;
    }
    while(ch!='\n');
    int n=i;
    p=p->next=NULL;   //尾部处理 
    do{
        scanf("%d%d%c",&c,&e,&ch);
        r=(multi*)malloc(sizeof(multi));
        r->coe=c,r->exp=e;
        //第一次
        if(flag==0)
        {
            for(p=head;p!=NULL;p=p->next)
            {
                p->coe*=r->coe;
                p->exp+=r->exp;                              
            }                                               
        }
        else
        {
            for(p=head,i=1;i<=n;p=p->next,i++)
            {
                r->coe*=a[i];
                r->exp+=b[i];
                q=head;
                //插入 
                while(q->exp>r->exp&&q->next!=NULL)                        
                {
                    q0=q;
                    q=q->next;
                }
                if(q->exp==r->exp)
                {
                    q->coe+=r->coe;    
                }
                else
                {
                    if(q->next!=NULL)
                    {
                        r->next=q0->next;
                        q0->next=r;
                    }
                    else
                    {
                        if(q->exp>r->exp)
						{
							r->next=NULL;
                            q->next=r;
						}
						else
						{
							r->next=q0->next;
                            q0->next=r;
						}
                    }
                }
                //重置
                r=(multi*)malloc(sizeof(multi));
                r->coe=c,r->exp=e;                      
            } 

        }
        flag=1;
    }
    while(ch!='\n');

    for(p=head;p!=NULL;p=p->next)
    {
        printf("%d %d ",p->coe,p->exp);
    }
     
    return 0;
} 

