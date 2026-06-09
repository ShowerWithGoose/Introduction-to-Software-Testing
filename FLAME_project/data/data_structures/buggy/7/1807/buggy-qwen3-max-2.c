#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct y{
    struct y *l;
    int s;
    struct y *r;
}y;
y *cre(int s){
    y *n=(y*)malloc(sizeof(y));
    n->s=s;
    n->l=0;
    n->r=0;
    return n;
}
void add(int a, y *head){
    y *cu=head,*n=cre(a);
    while(1){
    if(cu->s>a){
        if(cu->l!=0)
            cu=cu->l;
        else{
            cu->l=n;
            break;
        }
    }
    else
        if(cu->r!=0)
            cu=cu->r;
        else{
            cu->r=n;
            break;
        }
    }
    if(cu->s>a)@@ // @@ This block duplicates the insertion logic already handled in the while loop, causing incorrect tree structure (overwriting previously set child pointers).
        cu->l=n;
    else
        cu->r=n;@@ // @@ Same as above: redundant assignment after break leads to wrong links.
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++;@@ // @@ Height is incremented before checking if node is leaf; root starts at height 0 passed from main, so becomes 1 correctly, but logic for leaf detection is flawed.
    if(cu->r==0||cu->l==0)@@ // @@ Incorrect leaf condition: a node is a leaf only if BOTH children are NULL, not just one. This causes internal nodes with one child to be printed as leaves.
        printf("%d %d\n",cu->s,c);
    else{
        if(cu->l!=0)
            pri(cu->l,c);
        if(cu->r!=0)
            pri(cu->r,c);
    }
}

int main(){
    int n,i,a;
    y *head;
    scanf("%d%d",&n,&a);@@ // @@ Only reads first integer after n on same line; problem states all n integers are on the next line, but this assumes first value is on same line as n. However, input format says: first read n, then read n integers in the next line. This may cause misreading if input has newline. But more critically, the main issue is in `pri` and `add`.
    head=cre(a);
    for(i=0;i<n-1;i++){
        scanf("%d",&a);
        add(a,head);
    }
    pri(head,0);
    return 0;
}