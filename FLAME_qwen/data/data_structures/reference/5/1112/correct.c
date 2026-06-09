#include <stdio.h>
#include <stdlib.h>
typedef struct multi
{
    long long coe;
    long long index;
    struct multi*link;
}mul;
mul *list1=NULL,*list2=NULL,*listc=NULL,*llink;
mul* create(long long n,long long m,mul* ptr)
{
    mul* p;
    p=(mul*)malloc(sizeof(mul));
    p->coe=n;
    p->index=m;
    p->link=NULL;
    if(ptr==NULL)
    return p;
    ptr->link=p;
    return p;
}
mul* compute(mul *ptr1,mul *ptr2)
{
    mul *optr,*p,*k,*q=ptr2;
    long long coec,indexc;
    optr=(mul*)malloc(sizeof(mul));
    optr->coe=0;
    optr->index=ptr1->index+ptr2->index;
    optr->link=NULL;
    while(1)
    {
        while(1)
        {
            coec=ptr1->coe*ptr2->coe;
            indexc=ptr1->index+ptr2->index;
            for(k=optr;;k=k->link)
            {
                if(k->index==indexc)
                {
                    k->coe+=coec;
                    break;
                }
                if(indexc>optr->index)
                {
                    p=(mul*)malloc(sizeof(mul));
                    p->coe=coec;
                    p->index=indexc;
                    p->link=optr;
                    optr=p;
                    break;
                }
                if(k->link==NULL&&indexc<k->index)
                {
                    p=(mul*)malloc(sizeof(mul));
                    p->coe=coec;
                    p->index=indexc;
                    k->link=p;
                    p->link=NULL;
                    break;
                }
                if(indexc<k->index&&indexc>k->link->index)
                {
                    p=(mul*)malloc(sizeof(mul));
                    p->coe=coec;
                    p->index=indexc;
                    p->link=k->link;
                    k->link=p;
                    break;
                }
                
            }
            if(ptr2->link==NULL)
            break;
            ptr2=ptr2->link;
        }
        if(ptr1->link==NULL)
        break;
        ptr1=ptr1->link;
        ptr2=q;
    }
    return optr;
}
int main()
{
    long long a,b;
    char c,d;
    while(1)
    {
        scanf("%lld%c%lld%c",&a,&c,&b,&d);
        if(list1==NULL)
        {
            llink=list1=create(a,b,list1);
        }
        else
        llink=create(a,b,llink);
        if(d=='\n')
        break;
    }
    while(1)
    {
        scanf("%lld%c%lld%c",&a,&c,&b,&d);
        if(list2==NULL)
        {
            llink=list2=create(a,b,list2);
        }
        else
        llink=create(a,b,llink);
        if(d=='\n')
        break;
    }
    listc=compute(list1,list2);
    for(llink=listc;;llink=llink->link)
    {
        if(llink->coe!=0)
        printf("%lld %lld ",llink->coe,llink->index);
        if(llink->link==NULL)
        break;
    }
    return 0;
}



