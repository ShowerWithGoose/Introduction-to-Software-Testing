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
    if(cu->s>a) // @@ [This block duplicates insertion logic already handled in the while loop, causing incorrect overwriting of child pointers]
        cu->l=n;
    else
        cu->r=n; // @@ [This block duplicates insertion logic already handled in the while loop, causing incorrect overwriting of child pointers]
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++; // @@ [Incrementing c before checking leaf condition causes root height to start at 1 but is applied even when node is not a leaf, and logic for leaf detection is flawed]
    if(cu->r==0||cu->l==0) // @@ [Condition incorrectly identifies nodes with only one child as leaves; a leaf must have both children NULL]
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