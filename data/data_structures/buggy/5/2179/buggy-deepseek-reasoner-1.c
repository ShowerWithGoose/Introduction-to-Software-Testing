#include <string.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct a{
        long long xi;
        long long zhi;
        struct a*next;
    };
typedef struct a*aap;
typedef struct a aa;
aap f(aap head,long long xi,long long zhi){
    aap r=NULL;
    r=(aap)malloc(sizeof(aa));
    r->xi=xi;r->zhi=zhi;
    r->next=NULL;
    if(head==NULL){
        return r;
    }
    aap p=NULL;
    aap q=NULL;
    for(p=head;p!=NULL&&p->zhi>zhi;q=p,p=p->next);
    if(p==head){ // @@ Logic error: after inserting at head, control falls through, causing duplicate or NULL pointer dereference.
        r->next=p;
        head=r;
    } // @@ Logic error: missing return or else to avoid subsequent incorrect merge or crash.
    if(p!=NULL&&p->zhi==zhi){ // @@ Logic error: merge check should be done before any insertion, not after potential head insertion.
        p->xi+=xi;
    }
    else{
        q->next=r; // @@ Logic error: q may be NULL when p==head, leading to segmentation fault.
        r->next=p;
    }
    return head;
}
int main(){
    long long xi,zhi,t=9999999999;
    aap x1=NULL,x2=NULL;
    while(1){
        scanf("%lld%lld",&xi,&zhi);
        if(t<zhi)break; // @@ Logic error: break condition incorrectly uses exponent increase to separate polynomials, but may fail for constant terms.
        x1=f(x1,xi,zhi);
        t=zhi;
    }
    aap g=NULL;
    for(g=x1;g!=NULL;g=g->next){ // @@ Logic error: this loop multiplies x1 only by the last read (xi,zhi), which is the first term of the second polynomial.
        x2=f(x2,(g->xi)*xi,(g->zhi)+zhi); // @@ Logic error: multiplying only by the first term of second polynomial; rest are processed later but this duplicates and may cause incorrect results.
    }
    while(scanf("%lld%lld",&xi,&zhi)!=EOF){
        for(g=x1;g!=NULL;g=g->next){
                x2=f(x2,(g->xi)*xi,(g->zhi)+zhi);
            }
    }
    for(g=x2;g!=NULL;g=g->next){
        if(g->xi!=0){
            printf("%lld %lld ",g->xi,g->zhi);
        }
    }
}