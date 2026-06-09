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
    scanf("%d%d",&p->coe,&p->exp); // @@ [The first node is allocated but treated as part of the list; however, if input is empty (no terms), this leads to undefined behavior. Also, getchar() after scanf may not correctly detect end-of-line due to leftover whitespace.]
    while(getchar()!='\n'){ // @@ [This loop condition assumes that after reading two integers, the next character is either space or newline. However, if there's trailing space or multiple spaces, getchar() may consume non-newline whitespace and break prematurely or loop incorrectly.]
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
    p3->coe=p3->exp=0;p3->next=NULL; // @@ [Initializing result polynomial with a zero term (0x^0) is incorrect because it introduces an artificial term that may interfere with merging or output, especially if final result has no constant term or should be zero polynomial.]
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
                else if(r->exp<t->exp){ // @@ [This condition attempts to insert in descending order, but logic is flawed: it swaps content instead of inserting node properly. Also, it only checks immediate position and doesn't handle insertion at end correctly.]
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
        printf("%d %d ",p3->coe,p3->exp); // @@ [If the result polynomial is zero (all coefficients cancel out), this will still print the initial 0 0 term, which is wrong. Also, terms may not be in correct descending order due to flawed insertion logic.]
        p3=p3->next;
    }
    return 0;
}