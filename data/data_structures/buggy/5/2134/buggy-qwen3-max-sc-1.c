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
    scanf("%d%d",&p->coe,&p->exp); // @@ [The first node is treated as a valid term, but the loop condition using getchar() may not correctly detect end-of-line after the first pair, leading to incorrect input parsing or infinite loop. Also, if input has only one term, getchar() consumes '\n' and exits, but for multiple terms, it may consume space or newline inconsistently.]
    while(getchar()!='\n'){ // @@ [This loop condition reads one character after each term and checks if it's '\n'. However, after reading the last term of a multi-term polynomial, there may be no trailing space, and getchar() might read the newline immediately, causing the loop to exit prematurely or behave unpredictably depending on input formatting. Moreover, it doesn't handle cases where input ends without a newline.]
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
    p3->coe=p3->exp=0;p3->next=NULL; // @@ [Initializing result polynomial with a zero term (0x^0) is problematic because it interferes with coefficient accumulation. When multiplying terms, if a term with exponent 0 is generated, it will add to this existing zero term, but if no such term exists, this dummy node remains and gets printed, which violates the requirement to only output non-zero terms.]
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
                else if(r->exp<t->exp){ // @@ [This condition assumes the list is sorted in descending order, but insertion logic below does not maintain proper ordering. Also, when inserting at head (r == p3), it replaces p3's content instead of prepending properly, corrupting the dummy node.]
                    if(r==p3){
                        t->next=r;
                        p3=t; // @@ [This changes p3 to point to new node, but original p3 node (with 0,0) is now leaked or lost, and subsequent iterations may miss terms. Also, if multiple insertions happen at front, logic fails to maintain full list integrity.]
                    }
                    else{
                        c=r->coe;e=r->exp;
                        t->next=r->next;
                        r->coe=t->coe;r->exp=t->exp;t->coe=c;t->exp=e; // @@ [Swapping contents instead of inserting node breaks list structure and causes incorrect term storage. This approach modifies existing node instead of inserting new one, leading to data corruption and loss of original term.]
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
        printf("%d %d ",p3->coe,p3->exp); // @@ [Prints all terms including zero-coefficient terms (like initial dummy node if not overwritten), violating problem requirement to output only non-zero terms. Also, if multiplication results in zero polynomial, it should output nothing, but this prints "0 0".]
        p3=p3->next;
    }
    return 0;
}