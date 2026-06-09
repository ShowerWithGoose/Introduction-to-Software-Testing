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
    scanf("%d%d",&p->coe,&p->exp); // @@ [The first node is read into the head node, but subsequent nodes are appended after it. However, the loop condition `while(getchar()!='\n')` consumes one character after each term pair, which may skip necessary input or cause misalignment because `scanf` leaves a space or newline in the buffer. More critically, the head node is treated as a data node, but the insertion logic for subsequent terms inserts *after* the current node, leading to incorrect list structure and possible loss of terms.]
    while(getchar()!='\n'){ // @@ [This loop condition reads one character and checks if it's a newline, but after reading the first pair with `scanf("%d%d", ...)`, there may be a space or newline left. If it's a space, `getchar()` consumes it and continues, but if multiple spaces exist or input ends without trailing newline, this logic fails. Also, it assumes exactly one whitespace character between term pairs, which is not guaranteed. This can cause premature termination or infinite loop.]
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
    p3->coe=p3->exp=0;p3->next=NULL; // @@ [This initializes p3 with a dummy term (0x^0), which will interfere with polynomial multiplication. When combining like terms, this zero term may absorb non-zero coefficients or cause incorrect merging. The result should only contain non-zero terms, but this initial zero term violates that and leads to wrong output.]
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
                else if(r->exp<t->exp){ // @@ [This condition attempts to insert `t` in descending order, but the logic inside is flawed. When inserting at the head (`r == p3`), it sets `t->next = r` and `p3 = t`, which is correct. However, in the `else` block, instead of inserting `t` before `r`, it swaps the contents of `r` and `t`, then links `r->next = t`. This creates a cycle or duplicates nodes and corrupts the list structure. Moreover, if `t->exp` is greater than all existing exponents, this loop never triggers insertion, and `t` is leaked.]
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
        printf("%d %d ",p3->coe,p3->exp); // @@ [Because p3 was initialized with a zero term and the insertion/merging logic is flawed, the output may include zero-coefficient terms or miss terms entirely. Additionally, the problem requires only non-zero terms in the output, but this prints all terms in the list regardless of coefficient value.]
        p3=p3->next;
    }
    return 0;
}