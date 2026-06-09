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
    scanf("%d%d",&p->coe,&p->exp); // @@ [The first node is read into the head node, but subsequent nodes are inserted after it. However, the loop condition `while(getchar()!='\n')` consumes one character after the first pair, which may skip part of the next input or cause incorrect parsing when there's only one term. Also, if the input has only one term, `getchar()` reads the newline immediately and skips creating any further nodes — which is correct — but the logic for inserting new nodes is flawed: it inserts between p and p->next, but p starts as phead, so the list becomes reversed and the head is overwritten incorrectly in later logic.]
    while(getchar()!='\n'){
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
    p3->coe=p3->exp=0;p3->next=NULL; // @@ [This initializes p3 with a dummy term (0x^0), which will interfere with multiplication results. For example, multiplying two polynomials should not start with a zero term unless necessary. This causes extra terms like "0 0" to appear in output.]
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
        printf("%d %d ",p3->coe,p3->exp); // @@ [Because p3 was initialized with a dummy zero term, and during insertion logic this term may remain (especially if no term with exponent 0 is generated), it leads to printing an extra "0 0" at the end. Additionally, the insertion logic does not handle the case where t->exp is greater than all existing exponents correctly — it only checks for equality and less-than, but never appends at the end if t->exp is smaller than all. However, in this specific test case, the dummy node remains and causes the wrong output.]
        p3=p3->next;
    }
    return 0;
}