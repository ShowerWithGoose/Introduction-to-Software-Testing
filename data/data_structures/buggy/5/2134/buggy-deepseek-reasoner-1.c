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
    scanf("%d%d",&p->coe,&p->exp);
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
    p3->coe=p3->exp=0;p3->next=NULL; // @@ This creates a term with zero coefficient and exponent, which will appear in the output even if the product does not have a constant term, causing an extraneous "0 0" at the end.
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
                    r->coe+=t->coe; // @@ After adding, if the coefficient becomes zero, the term should be removed from the list to avoid printing zero-coefficient terms, but no removal is performed.
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
                r=r->next; // @@ When the loop exits with r == NULL (i.e., the new term's exponent is smaller than all existing exponents), the term is never inserted, causing it to be lost.
            }
            l=l->next;
        }
        m=m->next;
    }
    while(p3!=NULL){
        printf("%d %d ",p3->coe,p3->exp); // @@ This prints all nodes including the initial zero-coefficient term (if still present) and does not skip zero coefficients, leading to incorrect output.
        p3=p3->next;
    }
    return 0;
}