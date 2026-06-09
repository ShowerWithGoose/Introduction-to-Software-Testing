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
        q->next=r;
        r->next=p;
    }
    return head;
}
int main(){
    long long xi,zhi,t=9999999999;
    aap x1=NULL,x2=NULL;
    while(1){
        scanf("%lld%lld",&xi,&zhi);
        if(t<zhi)break; // @@ [The logic to detect end of first polynomial input is flawed. It assumes exponents are strictly decreasing and uses an arbitrary large t, but input may not follow this pattern or may have equal exponents. Also, the condition breaks too early if a higher exponent appears later, which shouldn't happen in valid input, but more critically, it doesn't check for newline or EOF properly, leading to incorrect parsing.]
        x1=f(x1,xi,zhi);
        t=zhi;
    }
    aap g=NULL;
    for(g=x1;g!=NULL;g=g->next){
        x2=f(x2,(g->xi)*xi,(g->zhi)+zhi); // @@ [Here, 'xi' and 'zhi' are from the last read of the first polynomial loop, not from the second polynomial. This line incorrectly uses stale values instead of reading the second polynomial properly. The entire approach to reading the second polynomial is broken.]
    }
    while(scanf("%lld%lld",&xi,&zhi)!=EOF){ // @@ [This loop attempts to read the second polynomial, but the previous block already used stale 'xi','zhi' to partially build x2. Moreover, the first polynomial reading loop breaks based on exponent order, not actual input termination (like newline), so the file pointer may be in an unknown state. Also, standard input is line-buffered and the problem specifies two lines, but this code doesn't handle line-based input correctly.]
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