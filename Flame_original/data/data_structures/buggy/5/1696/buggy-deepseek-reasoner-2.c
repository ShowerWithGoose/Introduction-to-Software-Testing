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
    for(p=head1->next;p!=NULL;p=p->next){ // @@ The loop advances p unconditionally, causing incomplete merging when multiple consecutive same exponents exist.
        if(p->next!=NULL){
            if(p->mi==p->next->mi){ // @@ After merging, the same p should be rechecked against the new next, but the for loop moves p forward.
                p->xishu+=p->next->xishu;
                p->next=p->next->next; // Does not free the removed node, but that is not a logic error.
            }
        }
    }
    for(p=head1->next;p!=NULL;p=p->next){
        printf("%d %d ",p->xishu,p->mi);
    }
    return 0; // @@ Missing newline after the output; a printf("\n") should be added before return.
}