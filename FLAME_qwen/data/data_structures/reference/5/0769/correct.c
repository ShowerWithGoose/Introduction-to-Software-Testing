#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct polinomial
{
    int a;
    int index;
    struct polinomial *next;
}*node;
node head1,head2,p,q,m,ptr,head;
int main()
{
    int number,variable;
    while(1)
    {
        scanf("%d%d",&number,&variable);
        p=(node)malloc(sizeof(struct polinomial));
        p->a=number;
        p->index=variable;
        p->next=NULL;
        if(head1==NULL)
        head1=q=p;
        else
        {
            q->next=p;
            q=q->next;
        }
        if(getchar()=='\n')
        break;
    }
    while(1)
    {
        scanf("%d%d",&number,&variable);
        p=(node)malloc(sizeof(struct polinomial));
        p->a=number;
        p->index=variable;
        p->next=NULL;
        if(head2==NULL)
        head2=q=p;
        else
        {
            q->next=p;
            q=q->next;
        }
        if(getchar()=='\n')
        break;
    }
    for(p=head1;p!=NULL;p=p->next)
    {
        for(q=head2,ptr=head;q!=NULL;q=q->next)
        {
            m=(node)malloc(sizeof(struct polinomial));
            m->a=p->a*q->a;
            m->index=p->index+q->index;
            m->next=NULL;
            if(head==NULL)
            head=ptr=m;
            else if(m->index>head->index)
            {
                m->next=head;
                head=ptr=m;
            }
            else 
            {
            for(;;ptr=ptr->next)
            {
                if(ptr->index==m->index)
                {
                    ptr->a+=m->a;
                    break;
                }
                else if((ptr->next==NULL)||(ptr->next->index<m->index))
                {
                    m->next=ptr->next;
                    ptr->next=m;
                    ptr=m;
                    break;
                }
            }
            }   
        }
    }
    for(m=head;m!=NULL;m=m->next)
    printf("%d %d ",m->a,m->index);
    return 0;
}
