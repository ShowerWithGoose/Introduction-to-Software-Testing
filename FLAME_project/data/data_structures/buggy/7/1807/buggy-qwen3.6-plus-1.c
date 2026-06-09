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
    if(cu->s>a) // @@ [Logic Error: The node 'n' has already been attached inside the while loop (either in the 'else' block of left check or right check). This code executes after the loop breaks, attempting to attach 'n' again, which overwrites the correct link or creates a logical inconsistency. Although the 'break' prevents infinite loop, this redundant assignment is incorrect and potentially dangerous if logic changes. More importantly, the primary issue causing WA is likely in `pri` or input reading, but this line is logically flawed as it re-assigns the child pointer after it was already set and broken out.]
        cu->l=n;
    else
        cu->r=n;
    //printf("%d",n->s);
}
void pri(y *head,int c){
    y *cu=head;
    c++;
    if(cu->r==0||cu->l==0) // @@ [Logic Error: This condition checks if the node is missing either a left OR a right child. A leaf node must have NEITHER left NOR right child (i.e., both are NULL). The current condition incorrectly identifies nodes with only one child as leaves, leading to incorrect output.]
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
    scanf("%d%d",&n,&a); // @@ [Input Format Error: The problem states that the n integers are on the next line. While scanf ignores whitespace, reading n and the first integer 'a' in one call is fragile if the input format strictly separates them or if there are newlines. However, standard scanf handles whitespace. The bigger issue is that if n=0, this reads garbage. But assuming n>=1, this is technically okay for space-separated inputs. The real error is usually logical. Let's look closer. Actually, the problem says "First, read an integer n... Then, read n integers". Using scanf("%d%d") consumes the first integer immediately. This is acceptable in C unless the input is malformed. However, combined with the logic errors in 'pri' and 'add', this contributes to the wrong answer. But strictly speaking, the format string isn't the primary bug compared to the leaf definition.]
    head=cre(a);
    for(i=0;i<n-1;i++){
        scanf("%d",&a);
        add(a,head);
    }
    pri(head,0);
    return 0;
}