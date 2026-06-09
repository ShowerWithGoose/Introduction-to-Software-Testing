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
    if(cu->s>a) // @@ [This block is redundant and causes double insertion: after breaking from the loop, the code again assigns n to cu->l or cu->r, overwriting the correct child pointer set inside the loop.]
        cu->l=n;
    else
        cu->r=n; // @@ [Same as above: this else block executes even after successful insertion in the loop, leading to incorrect tree structure.]
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++; // @@ [The increment should happen before checking if it's a leaf, but more critically, the leaf condition is wrong: a node is a leaf only if both children are NULL, not if either is NULL.]
    if(cu->r==0||cu->l==0) // @@ [Incorrect leaf condition: using OR instead of AND. This prints internal nodes that have only one child as if they were leaves.]
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