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
    scanf("%d%d",&p->coe,&p->exp); // @@ [The first node is created without checking if input succeeded; also, the loop condition using getchar() may consume part of the next input or fail to detect end-of-line correctly when multiple spaces exist]
    while(getchar()!='\n'){ // @@ [This loop consumes one character after each term pair, but if there are trailing spaces or multiple spaces between numbers, it may not correctly detect the newline, leading to incorrect parsing or infinite loop]
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
    p3->coe=p3->exp=0;p3->next=NULL; // @@ [Initializing result polynomial with a zero term (0x^0) causes incorrect accumulation during multiplication, as it adds an extra term that shouldn't be there initially]
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
                else if(r->exp<t->exp){ // @@ [This condition assumes the list is sorted in descending order, but insertion logic below does not maintain proper ordering; also, comparing with '<' here is inconsistent with typical descending-order traversal]
                    if(r==p3){
                        t->next=r;
                        p3=t;
                    }
                    else{
                        c=r->coe;e=r->exp;
                        t->next=r->next;
                        r->coe=t->coe;r->exp=t->exp;t->coe=c;t->exp=e; // @@ [Swapping values instead of inserting node breaks structure and leads to incorrect polynomial representation; this is logically flawed and causes data corruption]
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