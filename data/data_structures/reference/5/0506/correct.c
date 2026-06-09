#include <stdio.h>
#include <stdlib.h>

typedef struct multi
{
    int coef;//系数
    int index;//指数
    struct multi *next;
}multi;

multi *initmulti();
int cmp(const void *p1,const void *p2);

int main()
{
    multi *head1=initmulti(),*head2=initmulti();
    multi *p1=head1->next,*p2=head2->next;
    //multi *head=x_multi(head1,head2),*p=head->next;
    //while(p!=NULL)
    //    printf("%d %d",p->coef,p->index);
    multi result[1000]={0,0,NULL};
    int n=0,i,mulcoef,mulind;//n-1为指数个数
    while(p1!=NULL)
    {
        p2=head2->next;
        //printf("%d\n",p1->coef);
        while(p2!=NULL)
        {
            mulcoef=(p1->coef)*(p2->coef);
            mulind=(p1->index)+(p2->index);   //这里应该用加的。。。
            for(i=0;i<n && mulind!=result[i].index;i++);
            result[i].index=mulind;result[i].coef+=mulcoef;
            n=(n>i?n:i+1);   //差点忘了n的计数作用！
            p2=p2->next;
        }
        p1=p1->next;
    }
    qsort(result,n-1,sizeof(result[0]),cmp);
    for(int i=0;i<n;i++)
    {
        printf("%d %d ",result[i].coef,result[i].index);
    }
    return 0;
}

multi *initmulti()
{
    multi *head=(multi *)malloc(sizeof(multi)),*p=head;
    head->next=NULL;
    char c;

    while(1)
    {
        //printf("begin\n");
        multi *a=(multi *)malloc(sizeof(multi));
        scanf("%d%d",&(a->coef),&(a->index));
        p->next=a;p=a;p->next=NULL;
        //printf("%d\n",p->coef);
        if((c=getchar())=='\n')return head;

    }
}

int cmp(const void *p1,const void *p2)
{
    return ((*(multi *)p1).index<(*(multi *)p2).index) ?1:-1;
}

