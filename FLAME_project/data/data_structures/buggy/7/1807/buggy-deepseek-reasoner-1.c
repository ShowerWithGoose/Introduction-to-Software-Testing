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
    if(cu->s>a) // @@ This line and the else block below are erroneous: they unconditionally overwrite the child pointer after the while loop, causing duplicate linking and corrupting the tree structure. The loop already correctly set the pointer and broke; these extra lines should be removed.
        cu->l=n;
    else
        cu->r=n;
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++;
    if(cu->r==0||cu->l==0) // @@ The condition should be logical AND (both children null) to correctly identify leaf nodes. Using OR prints any node with at least one null child, which incorrectly treats non-leaf nodes as leaves and stops traversal.
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