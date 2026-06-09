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
    scanf("%d%d",&p->coe,&p->exp); // @@ [The first node is allocated but treated as a valid term; however, if input is empty (no terms), this leads to undefined behavior. Also, the loop condition assumes at least one term exists.]
    while(getchar()!='\n'){ // @@ [This consumes one character after the first term's exponent. If there are more terms, the next scanf may fail because the newline might have already been consumed or extra spaces remain. Also, it doesn't handle multiple spaces or EOF correctly.]
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
    p3->coe=p3->exp=0;p3->next=NULL; // @@ [Initializes result polynomial with a zero term (0x^0). This causes incorrect output if the actual product has no constant term or if all terms cancel out, and interferes with insertion logic.]
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
                else if(r->exp<t->exp){ // @@ [This condition assumes the list is sorted in descending order, but the insertion logic below does not maintain proper ordering. Also, comparing with '<' when trying to insert in descending order is backwards. Should be r->exp > t->exp for descending traversal.]
                    if(r==p3){
                        t->next=r;
                        p3=t;
                    }
                    else{
                        c=r->coe;e=r->exp;
                        t->next=r->next;
                        r->coe=t->coe;r->exp=t->exp;t->coe=c;t->exp=e; // @@ [Swapping contents instead of inserting node breaks structure and causes memory leaks; also logically flawed for polynomial addition.]
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
        printf("%d %d ",p3->coe,p3->exp);
        p3=p3->next;
    }
    return 0;
}