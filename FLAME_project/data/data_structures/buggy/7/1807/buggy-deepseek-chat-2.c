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
    if(cu->s>a) // @@ [Error: After the while loop, cu points to the parent node where the new node was attached, but the condition cu->s>a may be incorrect because cu may have been updated to a child node. This redundant code incorrectly tries to attach the node again, causing duplicate or incorrect links.]
        cu->l=n;
    else
        cu->r=n;
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++;
    if(cu->r==0||cu->l==0) // @@ [Error: The condition should be AND (&&) not OR (||). A leaf node has both children NULL. Using OR incorrectly treats any node with at least one NULL child as a leaf, printing non-leaf nodes.]
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
    scanf("%d%d",&n,&a); // @@ [Error: The input format specifies first reading n, then reading n integers. This line reads two integers at once, incorrectly consuming the first integer of the sequence as part of n. It should be scanf("%d",&n); followed by reading the first element separately.]
    head=cre(a);
    for(i=0;i<n-1;i++){ // @@ [Error: Because n was read incorrectly, the loop count is wrong. Additionally, the first element was already read as 'a', so the loop should run n-1 times, but the initial read of n is incorrect.]
        scanf("%d",&a);
        add(a,head);
    }
    pri(head,0);
    return 0;
}