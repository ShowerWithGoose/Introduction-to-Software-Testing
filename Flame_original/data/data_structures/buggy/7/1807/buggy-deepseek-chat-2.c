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
    if(cu->s>a) // @@ [Error: After the while loop, cu points to the parent node where the new node was inserted, but the code incorrectly tries to link the new node again, causing duplicate insertion and potential memory issues. The break statements already set the link, so this extra if-else is redundant and wrong.]
        cu->l=n;
    else
        cu->r=n;
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++;
    if(cu->r==0||cu->l==0) // @@ [Error: This condition incorrectly treats nodes with only one child as leaf nodes. A leaf node should have both children NULL (cu->r==0 && cu->l==0). Using || means any node missing at least one child is considered a leaf, which is wrong.]
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