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
        if(t<zhi)break; // @@ [The logic for detecting end of first polynomial input is flawed. It assumes exponents are strictly decreasing and uses an arbitrary initial t, but input may not follow this pattern or may have equal exponents (though problem says non-zero terms only, order isn't guaranteed to be strictly descending in practice for breaking condition). Also, after the first polynomial ends, xi and zhi retain last values and are reused incorrectly in the next loop.]
        x1=f(x1,xi,zhi);
        t=zhi;
    }
    aap g=NULL;
    for(g=x1;g!=NULL;g=g->next){
        x2=f(x2,(g->xi)*xi,(g->zhi)+zhi); // @@ [Uses stale 'xi' and 'zhi' from the last read of the first polynomial as if they belong to the second polynomial. This is completely wrong: the second polynomial hasn't been read yet at this point.]
    }
    while(scanf("%lld%lld",&xi,&zhi)!=EOF){ // @@ [This attempts to read the second polynomial, but the previous loop already tried to process multiplication using uninitialized second polynomial data. Also, EOF detection doesn't match the problem's input format which uses newline-terminated lines, not EOF. On many systems, interactive input won't trigger EOF easily, causing infinite loop or undefined behavior.]
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