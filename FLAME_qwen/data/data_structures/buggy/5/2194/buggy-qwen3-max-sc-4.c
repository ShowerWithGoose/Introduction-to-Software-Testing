#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct NODE{
    int a,n;
    struct NODE *next;
} Node,*Nop;
Node *head1,*head2,*head3;
Node *createNode(int m,int n){
    Node *tmp=(Node*) malloc(sizeof (Node));
    tmp->a=m;
    tmp->n=n;
    tmp->next=NULL;
    return tmp;
}

Node *insert(Node *p,Node *head){
    if(head3==NULL){
        head3= createNode(p->a,p->n);
        return head3;}
    Node *tp=head;
    while(1){
        if(tp->next==NULL || tp->next->n<p->n){
            p->next=tp->next;
            tp->next=p;
            break;
        }
        else if(tp->next->n>p->n){
            tp=tp->next;}
        else if(tp->next->n==p->n){
            tp->a+=p->a; // @@ [Incorrectly updating `tp->a` instead of `tp->next->a`; should add to the existing term's coefficient, not the previous node's]
            break;}
    }
    return head;
}
int main() {
    Nop p,q;
    int m,n;
    char c;
    scanf("%d %d",&m,&n);
    head1= createNode(m,n);
    p=head1;
    scanf("%c",&c);
    while(c!='\n'){
        scanf("%d %d",&m,&n);
        q= createNode(m,n);
        p->next=q;
        p=q;
        scanf("%c",&c);
    }
    scanf("%d %d",&m,&n); // @@ [This assumes there is at least one term in the second polynomial; if input ends immediately after first polynomial, this will fail or read garbage]
    head2= createNode(m,n);
    p=head2;
    while(scanf("%d%d",&m,&n)!=EOF){ // @@ [Relies on EOF to terminate second polynomial input, but problem states input ends with newline; may overread or miss last term]
        q= createNode(m,n);
        p->next=q;
        p=q;
    }
    Node *p1=head1,*p2=head2;
    while(p1){
        p2=head2;
        while(p2){
            Node *tmp= createNode(p1->a*p2->a,p1->n+p2->n);
            head3=insert(tmp,head3); // @@ [`insert` function has logic errors: uses global `head3` inconsistently and modifies wrong node during coefficient merge]
            p2=p2->next;
        }
        p1=p1->next;
    }
    Node *p3=head3;
    while(p3){
        printf("%d %d ",p3->a,p3->n);
        p3=p3->next;
    }
    return 0;
}