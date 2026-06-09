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
    if(cu->s>a) // @@ [This block is redundant and incorrect: after breaking from the loop, cu already points to the parent where n was attached; reassigning cu->l or cu->r overwrites the just-inserted node, potentially causing memory leak or incorrect tree structure.]
        cu->l=n;
    else
        cu->r=n; // @@ [Same as above: this else block duplicates insertion logic already handled inside the while loop, leading to double assignment and logical error.]
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++; // @@ [Incrementing c at the start means root's height becomes 1 only if initial call uses 0, but logic for leaf detection is flawed: condition `if(cu->r==0||cu->l==0)` incorrectly treats nodes with one child as leaves.]
    if(cu->r==0||cu->l==0) // @@ [This condition is wrong: a leaf must have both left and right children NULL. Using OR causes non-leaf nodes (with one child) to be printed as leaves.]
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
    scanf("%d%d",&n,&a);
    head=cre(a);
    for(i=0;i<n-1;i++){
        scanf("%d",&a);
        add(a,head);
    }
    pri(head,0);
    return 0;
}