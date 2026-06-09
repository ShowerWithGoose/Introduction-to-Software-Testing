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
    if(p!=NULL&&p->zhi==zhi){ // @@ [Logical Error: When merging coefficients (p->zhi == zhi), the newly allocated node 'r' is leaked. More importantly, if this condition is met inside the loop logic or subsequent checks, it doesn't handle the list structure correctly relative to the previous 'if'. However, the critical TLE cause is below.]
        p->xi+=xi;
    }
    else{
        q->next=r; // @@ [Runtime Error/Logical Error: If p==head was true and we didn't enter the merge block, q is still NULL. Accessing q->next causes a segmentation fault. But primarily, the TLE is caused by the input parsing logic.]
        r->next=p;
    }
    return head;
}
int main(){
    long long xi,zhi,t=9999999999;
    aap x1=NULL,x2=NULL;
    while(1){
        scanf("%lld%lld",&xi,&zhi);
        if(t<zhi)break; // @@ [Logical Error: The problem states exponents are in descending order. This condition `t < zhi` implies breaking if the current exponent is larger than the previous one. Since input is descending, `zhi` will always be `<= t`. This loop will never break based on this condition unless the input format changes or an error occurs. It relies on `scanf` failure or infinite loop. Actually, since input is descending, `zhi` decreases. `t` starts huge. `t < zhi` is false. Loop continues. It reads the whole first polynomial. How does it stop? It doesn't detect the newline. It keeps reading into x1 until scanf fails or memory runs out, consuming x2's input as well if not careful. But wait, `scanf` reads whitespace. It will read the second polynomial's numbers into `xi` and `zhi` and add them to `x1` because there is no mechanism to switch to `x2`. This is the primary cause of TLE/WA: it treats the entire input stream as the first polynomial.]
        x1=f(x1,xi,zhi);
        t=zhi;
    }
    aap g=NULL;
    for(g=x1;g!=NULL;g=g->next){
        x2=f(x2,(g->xi)*xi,(g->zhi)+zhi); // @@ [Logical Error: `xi` and `zhi` here hold the last values read in the previous loop. This attempts to multiply x1 by the last term of x1 (or garbage if loop broke differently), not x2. The second polynomial hasn't been read into a separate structure properly.]
    }
    while(scanf("%lld%lld",&xi,&zhi)!=EOF){ // @@ [Logical Error: Since the first loop consumed all input (because it didn't stop at newline), this loop likely executes 0 times or behaves unexpectedly depending on buffer state. Even if it did run, the logic of multiplying x1 by each term of x2 is implemented by calling f repeatedly, which is O(N*M) insertions. Each insertion in `f` traverses the list. If the result list grows large, this becomes O((N*M)^2). For large exponents/degrees, this is slow. But the primary issue is the input parsing.]
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