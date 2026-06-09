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
    if(cu->s>a) // @@ [Logical Error: The node 'n' has already been attached inside the while loop (either in the 'else' block of left check or right check). This code outside the loop attempts to attach it again, overwriting the correct link or creating a mess. Specifically, if the loop breaks after setting cu->l=n or cu->r=n, this line executes and might overwrite it or point to garbage if cu changed. More critically, the logic is redundant and incorrect because the attachment happens inside the loop.]
        cu->l=n;
    else
        cu->r=n;
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++;
    if(cu->r==0||cu->l==0) // @@ [Logical Error: This condition checks if the node is missing at least one child (i.e., it's not a full internal node with 2 children). However, a leaf node is defined as having NO children (both l and r are NULL/0). A node with only one child is not a leaf. This causes non-leaf nodes (with 1 child) to be printed as leaves, and prevents traversal into their existing child, missing actual leaves deeper in the tree.]
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
    scanf("%d%d",&n,&a); // @@ [Input Format Error: The problem states that the n integers are on the "next line". While scanf skips whitespace, reading the first integer 'a' here combined with 'n' in one scanf call is risky if the input format is strict about lines, but more importantly, if n=0 or handling edge cases. However, the bigger issue is usually just standard parsing. But looking at the reference, it reads n then loops. Here it reads n and the first element. If the input is "10\n180...", this works. But let's look closer. The main logical errors are in add and pri.]
    head=cre(a);
    for(i=0;i<n-1;i++){
        scanf("%d",&a);
        add(a,head);
    }
    pri(head,0);
    return 0;
}