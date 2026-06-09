#include <stdio.h>
#include <stdlib.h>
typedef struct muti{
     long long an;
     long long n;
     struct muti* link;
}*mu,m;
mu add(mu,long long,long long,mu);
int main()
{
    mu p,q,r,a=NULL,b=NULL,c,last;
    long long coef,exp;
    do{
        scanf("%lld%lld",&coef,&exp);
        p=(mu)malloc(sizeof(m));
        p->an=coef;
        p->n=exp;
        p->link=NULL;
        if(a==NULL)
            a=p;
        else
            q->link=p;
        q=p;
    }while(getchar()!='\n');
    do{
        scanf("%lld%lld",&coef,&exp);
        p=(mu)malloc(sizeof(m));
        p->an=coef;
        p->n=exp;
        p->link=NULL;
        if(b==NULL)
            b=p;
        else
            r->link=p;
        r=p;
    }while(getchar()!='\n');
    c=(mu)malloc(sizeof(m));
    last=c;
    for(q=a;q!=NULL;q=q->link){
        for(r=b;r!=NULL;r=r->link){
            coef=q->an*r->an;
            exp=q->n+r->n;
            last=add(c,coef,exp,last);
        }
    }
    last->link=NULL;
    q=c;
    c=c->link;
    free(q);
    for(p=c;p!=NULL;p=p->link)
        printf("%lld %lld ",p->an,p->n);
    return 0;
}
mu add(mu c,long long coef,long long exp,mu last)
{
    mu i,k;
    if(c==last){
        k=(mu)malloc(sizeof(m));
        k->an=coef;
        k->n=exp;
        last->link=k;
        return k;
    }
    else{
        i=c->link;
        while(i!=last){
            if(exp==i->n){
                i->an+=coef;
                return last;
            }
            else if((exp<i->n)&&(exp>i->link->n)){
                k=(mu)malloc(sizeof(m));
                k->an=coef;
                k->n=exp;
                k->link=i->link;
                i->link=k;
                return last;
            }
            else if(exp<=i->link->n)
                i=i->link;
        }
        if(exp==i->n){
                i->an+=coef;
                return i;}
        else if(exp<i->n){
            k=(mu)malloc(sizeof(m));
            k->an=coef;
            k->n=exp;
            i->link=k;
            return k;
        }
    }
}

