#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    int xishu;
    int mi;
    struct Node *next;
};

int main(){
    typedef struct Node xn;
    int an,n;
    char c;
    xn *p,*q,*head;
    head=(xn*)malloc(sizeof(xn));
    head->next=NULL;
    do{
        scanf("%d %d%c",&an,&n,&c);
        q=(xn*)malloc(sizeof(xn));
        q->xishu=an;
        q->mi=n;
        q->next=NULL;
        if(head->next==NULL){
            head->next=p=q;
        }else{
            p->next=q;
            p=q;
        }
    }while(c!='\n');
    xn *p0,*p1,*q0,*head1;
    head1=(xn*)malloc(sizeof(xn));
    head1->next=NULL;
    do{
        scanf("%d %d%c",&an,&n,&c);
        q=(xn*)malloc(sizeof(xn));
        q->xishu=an;q->mi=n;q->next=NULL;
        for(p0=head->next;p0!=NULL;p0=p0->next){
            q0=(xn*)malloc(sizeof(xn));
            q0->xishu=an*p0->xishu;
            q0->mi=n+p0->mi;
            q0->next=NULL;
            if(head1->next==NULL){
                head1->next=q0;
                p1=q0;
            }else{
                p1->next=q0;
                p1=q0;
            }
            
        }
    }while(c!='\n');
    xn *tem;
    tem=(xn*)malloc(sizeof(xn));
    for(p=head1->next;p!=NULL;p=p->next){
        for(q=p->next;q!=NULL;q=q->next){
            if(q->mi>p->mi){
                tem->xishu=q->xishu;
                tem->mi=q->mi;
                q->xishu=p->xishu;
                q->mi=p->mi;
                p->xishu=tem->xishu;
                p->mi=tem->mi;
            }
        }
    }
    for(p=head1->next;p!=NULL;p=p->next){ // @@ The loop condition allows p to be the last node, but the logic inside requires p->next to exist. More importantly, when merging terms, if the resulting coefficient becomes 0 or if multiple terms have the same exponent, this single pass fails to merge all of them correctly (e.g., A->B->C where B and C match A, after merging B into A, A->C, but the loop moves to next which is C, skipping the check between new A and C). Also, it does not free the removed nodes.
        if(p->next!=NULL){
            if(p->mi==p->next->mi){
                p->xishu+=p->next->xishu;
                p->next=p->next->next; // @@ Memory leak: the skipped node is not freed. Logic error: if the next node also has the same exponent, it won't be merged in this single pass forward iteration.
            }
        }
    }
    for(p=head1->next;p!=NULL;p=p->next){
        printf("%d %d ",p->xishu,p->mi); // @@ Should check if p->xishu != 0 before printing, as per problem description "Only terms with non-zero coefficients will appear in the input" implies output should likely follow similar convention or standard polynomial representation which omits zero coefficients. The reference program checks for non-zero.
    }
    return 0;
}