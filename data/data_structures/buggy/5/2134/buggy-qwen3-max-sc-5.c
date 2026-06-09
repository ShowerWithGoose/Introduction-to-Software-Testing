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
    scanf("%d%d",&p->coe,&p->exp); @@ [The first node is allocated but treated as part of the list; however, if input is empty (no terms), this leads to undefined behavior. Also, getchar() after scanf may not correctly detect end-of-line due to leftover whitespace.]
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
    p3->coe=p3->exp=0;p3->next=NULL; @@ [Initializing result polynomial with a zero term is incorrect—it should start empty or handle merging properly. This zero term interferes with correct polynomial multiplication and output.]
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
            } @@ [If no existing term matches and t has the smallest exponent so far, it's never appended to the end of the list—loop exits without inserting t.]
            l=l->next;
        }
        m=m->next;
    }
    while(p3!=NULL){
        printf("%d %d ",p3->coe,p3->exp); @@ [Printing includes the initial zero term even if it shouldn't be there, and terms may not be in strictly descending order due to flawed insertion logic.]
        p3=p3->next;
    }
    return 0;
}