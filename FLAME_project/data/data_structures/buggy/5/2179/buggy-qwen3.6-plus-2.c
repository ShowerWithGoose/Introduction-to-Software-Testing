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
    if(p==head){
        r->next=p;
        head=r;
    }
    if(p!=NULL&&p->zhi==zhi){
        p->xi+=xi;
    }
    else{
        q->next=r; // @@ [Logical Error: If p==head and zhi != head->zhi, q is still NULL. Accessing q->next causes a segmentation fault or undefined behavior. Additionally, if p==head and we inserted at head, we should not execute this else block which tries to link via q.]
        r->next=p;
    }
    return head;
}
int main(){
    long long xi,zhi,t=9999999999;
    aap x1=NULL,x2=NULL;
    while(1){
        scanf("%lld%lld",&xi,&zhi);
        if(t<zhi)break; // @@ [Logical Error: The problem states exponents are in descending order. This condition `t < zhi` checks if the current exponent is greater than the previous one. Since input is descending, `zhi` should be <= `t`. This break condition is incorrect for detecting the end of the first polynomial. It relies on an invalid assumption about input order change or specific sentinel value logic which doesn't match the "newline separated" input format description properly without reading the newline character explicitly.]
        x1=f(x1,xi,zhi);
        t=zhi;
    }
    aap g=NULL;
    for(g=x1;g!=NULL;g=g->next){
        x2=f(x2,(g->xi)*xi,(g->zhi)+zhi); // @@ [Logical Error: `xi` and `zhi` here hold the values from the LAST term read in the previous while loop. The multiplication logic is fundamentally flawed. It attempts to multiply the entire first polynomial `x1` by only the last term of the first polynomial (stored in xi/zhi) instead of reading the second polynomial and multiplying term-by-term. Also, this loop runs before reading the second polynomial.]
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