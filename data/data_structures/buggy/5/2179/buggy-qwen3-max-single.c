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
        if(t<zhi)break; // @@ [The logic to detect end of first polynomial is flawed. It assumes exponents are input in strictly descending order and breaks when a higher exponent appears, but the problem does not guarantee input order. Also, t starts as a large number, so the first term will always satisfy t>=zhi, but subsequent terms may not be read correctly if not descending. Moreover, this loop never reads the newline to detect end of line properly.]
        x1=f(x1,xi,zhi);
        t=zhi;
    }
    aap g=NULL;
    for(g=x1;g!=NULL;g=g->next){
        x2=f(x2,(g->xi)*xi,(g->zhi)+zhi); // @@ [At this point, 'xi' and 'zhi' hold values from the last iteration of the previous loop, which broke due to t<zhi. These are invalid leftovers and do not represent any term from the second polynomial. This loop incorrectly uses these stale values to multiply with the first polynomial before reading the second polynomial at all.]
    }
    while(scanf("%lld%lld",&xi,&zhi)!=EOF){ // @@ [This attempts to read the second polynomial, but the first polynomial reading already consumed part of the input incorrectly. Also, the condition !=EOF is wrong because the input ends with a newline, not EOF. The program should read until newline, not until EOF, causing it to hang or misread.]
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