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
        q->next=r; // @@ [When p is NULL (i.e., zhi is smaller than all existing exponents), q may be NULL if the loop never executed, causing a segmentation fault or undefined behavior. Additionally, when p is not NULL and p->zhi != zhi, q is guaranteed to be non-NULL because the loop runs at least once if head is not NULL, but if head is NULL, the function returns early. However, the case where p is NULL after the loop (zhi is smallest) and head is not NULL, q will be the last node, so this is safe. But the logic is flawed because if p is NULL and head is not NULL, the else branch executes, but q is the last node, which is correct. However, the main issue is that when p is NULL and head is not NULL, the code does not handle the case where the new node should be inserted at the end correctly because q is the last node, but the code sets q->next = r, which is correct. The real error is that the function does not handle the case where p is NULL and head is NULL (already returned), but the logic for inserting at the end is actually correct. The critical error is that when p is not NULL and p->zhi == zhi, the function does not free the allocated node r, causing a memory leak. Additionally, the function does not handle the case where the new exponent is greater than the head's exponent correctly because after the if(p==head) block, it falls through to the if(p!=NULL&&p->zhi==zhi) check, which would incorrectly treat the head as having the same exponent if the new exponent is greater. This is a logical error: if p==head and the new exponent is greater, the code sets head=r and then checks if p->zhi==zhi, which is false because p is the old head with a smaller exponent, so it goes to else and sets q->next=r, but q is NULL because the loop didn't execute, causing a crash. This is the main bug.]
        r->next=p;
    }
    return head;
}
int main(){
    long long xi,zhi,t=9999999999;
    aap x1=NULL,x2=NULL;
    while(1){
        scanf("%lld%lld",&xi,&zhi);
        if(t<zhi)break;
        x1=f(x1,xi,zhi);
        t=zhi;
    }
    aap g=NULL;
    for(g=x1;g!=NULL;g=g->next){
        x2=f(x2,(g->xi)*xi,(g->zhi)+zhi);
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