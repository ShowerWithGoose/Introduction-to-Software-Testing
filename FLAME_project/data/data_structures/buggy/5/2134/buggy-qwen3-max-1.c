#include<stdio.h>
#include<stdlib.h>
typedef struct poly{
    int coe;
    int exp;
    struct poly *next;
}polynode,* polylist;
polylist createnew(){
    polylist phead=(polylist)malloc(sizeof(polynode));
    if(phead==NULL){
        return NULL;
    }
    phead->next=NULL;
    polylist p,n;
    p=phead;
    scanf("%d%d",&p->coe,&p->exp); // @@ [The first node is treated as a valid term, but the loop condition `while(getchar()!='\n')` may not correctly handle input with only one term. Also, after reading the first pair, `getchar()` consumes the next character (which might be space or newline), leading to incorrect parsing when there's only one term.]
    while(getchar()!='\n'){ // @@ [This loop condition assumes that after each term there's a non-newline character, but for single-term input, the first `scanf` reads the two integers and leaves a newline; then `getchar()` immediately returns '\n', so the loop doesn't run — which is correct for single term. However, for multi-term input, this approach fails because `scanf` leaves whitespace (including spaces) in the buffer, and `getchar()` only checks one character. It may incorrectly stop early or skip terms. The logic for reading multiple terms is flawed.]
        n=(polylist)malloc(sizeof(polynode));
        if(n==NULL){
            return NULL;
        }
        scanf("%d%d",&n->coe,&n->exp);
        n->next=p->next;
        p->next=n;
        p=p->next;
    }
    return phead;
}
int main(){
    polylist p1,p2,p3,m,l,r,s;
    int c,e;
    p3=(polylist)malloc(sizeof(polynode));
    p3->coe=p3->exp=0;p3->next=NULL; // @@ [Initializing p3 with a dummy node (0 0) causes an extra zero term to appear in output if no term cancels it. This leads to incorrect output like "120 2000000000 0 0" instead of just "120 2000000000".]
    p1=createnew();
    p2=createnew();
    m=p1;
    while(m!=NULL){
        l=p2;
        while(l!=NULL){
            polylist t=(polylist)malloc(sizeof(polynode));
            t->coe=m->coe*l->coe;
            t->exp=m->exp+l->exp;
            r=p3;
            while(r!=NULL){
                if(r->exp==t->exp){
                    r->coe+=t->coe;
                    break;
                }
                else if(r->exp<t->exp){
                    if(r==p3){
                        t->next=r;
                        p3=t;
                    }
                    else{
                        c=r->coe;e=r->exp;
                        t->next=r->next;
                        r->coe=t->coe;r->exp=t->exp;t->coe=c;t->exp=e;
                        r->next=t;
                    }
                    break;
                }
                r=r->next;
            }
            l=l->next;
        }
        m=m->next;
    }
    while(p3!=NULL){
        printf("%d %d ",p3->coe,p3->exp); // @@ [Because p3 was initialized with a (0,0) dummy node, and if no term with exponent 0 is produced by multiplication (as in the test case), this zero term remains and gets printed, causing the extra "0 0" in output.]
        p3=p3->next;
    }
    return 0;
}