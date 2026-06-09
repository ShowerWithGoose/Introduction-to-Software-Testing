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
        head3= createNode(p->a,p->n); // @@ [Logic Error: The function receives a node 'p' but ignores it, creating a new node instead. This causes memory leaks and loses the calculated coefficient/exponent from the caller. It should assign head3 = p or copy values to p.]
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
            tp->a+=p->a; // @@ [Logic Error: When exponents match, it adds the coefficient of the new node 'p' to the existing node 'tp'. However, since the first branch creates a new node for head3 instead of using 'p', and subsequent inserts pass 'p' which might be intended to be merged, this logic is partially correct for merging but fails because the initial insertion didn't use 'p'. More critically, if tp->next matches, we merge into tp->next? No, tp is the current node. If tp->next->n == p->n, we should add to tp->next->a. Here it adds to tp->a, which is wrong. It should be tp->next->a += p->a.]
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
    while(scanf("%d%d",&m,&n)!=EOF){ // @@ [Input Error: The second polynomial input loop does not check for newline character to stop. It reads until EOF, which means it will hang or fail if the input is provided line-by-line in a standard test environment where EOF is not immediately sent after the second line. It should check for '\n' similar to the first polynomial.]
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