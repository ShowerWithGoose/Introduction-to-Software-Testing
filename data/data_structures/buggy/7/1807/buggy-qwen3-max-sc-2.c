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
    if(cu->s>a) // @@ [This block is redundant and causes double insertion: after breaking from the loop, the code reassigns cu->l or cu->r again, overwriting the correct insertion done inside the loop.]
        cu->l=n;
    else
        cu->r=n; // @@ [Same as above: this else block runs even after successful insertion in the loop, leading to incorrect tree structure.]
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++; // @@ [The height is incremented before checking if the node is a leaf, but the root's height should be 1. However, the main issue is the leaf condition logic below.]
    if(cu->r==0||cu->l==0) // @@ [Incorrect leaf condition: a leaf must have BOTH children NULL, not just one. This causes non-leaf nodes with one child to be printed as leaves.]
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