#include<stdio.h>
#include<stdlib.h>
struct infor{int a;
             int x;
             struct infor *next;
             };
int main()
{
    struct infor buf1[500],buf2[500],*head,*p,*q,*temp;
    int n1=0,n2=0,i,ina,inx,j,outa,outx,c;
    do
    {
        scanf("%d %d",&ina,&inx);
        buf1[n1].a=ina;
        buf1[n1].x=inx;
        buf1[n1].next=NULL;
        n1++;
    }while((c=getchar())!='\n');
    do
    {
        scanf("%d %d",&ina,&inx);
        buf2[n2].a=ina;
        buf2[n2].x=inx;
        buf2[n2].next=NULL;
        n2++;
    }while((c=getchar())!='\n');
    head=NULL;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            outa=(buf2[j].a)*(buf1[i].a);
            outx=(buf2[j].x)+(buf1[i].x);
            if(head==NULL)
            {
                head=(struct infor*)malloc(sizeof(struct infor));
                head->a=outa;
                head->x=outx;
                head->next=NULL;
                continue;
            }
            if(head!=NULL)
            {
                for(q=head,p=head->next;(p!=NULL)&&outx<(p->x);q=p,p=p->next)
                    ;
                if(p==NULL)
                {
                    p=(struct infor*)malloc(sizeof(struct infor));
                    p->a=outa;
                    p->x=outx;
                    p->next=NULL;
                    q->next=p;
                    continue;
                }
                if(outx==(p->x))
                {
                    (p->a)+=outa;
                    continue;
                }
                if(outx>(p->x))
                {
                    temp=(struct infor*)malloc(sizeof(struct infor));
                    temp->a=outa;
                    temp->x=outx;
                    temp->next=p;
                    q->next=temp;
                    temp=NULL;
                    continue;
                }
            }
        }
    }
    for(p=head;p!=NULL;)
    {
        printf("%d %d ",(p->a),(p->x));
        q=p;
        p=p->next;
        free(q);
    }
    return 0;
}

