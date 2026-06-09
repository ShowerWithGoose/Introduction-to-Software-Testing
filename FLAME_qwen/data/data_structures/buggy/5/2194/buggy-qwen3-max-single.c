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
            tp->next->a+=p->a; // @@ [The code incorrectly updates tp->a instead of tp->next->a when merging terms with the same exponent]
            free(p); // @@ [Memory leak: allocated node 'p' is not freed when its coefficient is merged into an existing term]
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
    scanf("%d %d",&m,&n);
    head2= createNode(m,n);
    p=head2;
    while(scanf("%d%d",&m,&n)!=EOF){ // @@ [This loop condition may cause infinite loop or undefined behavior because it doesn't check for newline termination like the first polynomial input]
        q= createNode(m,n);
        p->next=q;
        p=q;
    }
    Node *p1=head1,*p2=head2;
    while(p1){
        p2=head2;
        while(p2){
            Node *tmp= createNode(p1->a*p2->a,p1->n+p2->n);
            head3=insert(tmp,head3);
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