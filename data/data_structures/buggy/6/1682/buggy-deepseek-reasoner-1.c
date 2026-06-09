#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100
struct stack
{
    int num;
    struct stack *next;
};
typedef struct stack *nodeptr;
typedef struct stack node;
void push(int item);
void pop();
nodeptr top;
void main() // @@ should be int main() to comply with C standard; returning 0 from void is invalid
{
    int j,n;
    top=NULL;
    while(scanf("%d",&n)&&n!=-1){
        if(n==1){
            scanf("%d",&j);
            push(j);
        }
        if(n==0){
            pop();
        }
    }
    return 0; // @@ invalid return in void function
}
void push(int item) // @@ missing capacity check: stack should have max 100
{
    nodeptr p;
    if((p=(nodeptr)malloc(sizeof(node)))==NULL){
        printf("No memory!");
    }
    else{
        p->num=item;
        p->next=top;
        top=p;
    }
}
void pop()
{
    nodeptr p;
    int item;
    if(top==NULL){
        printf("Error "); // @@ should output "error " (lowercase) per problem specification
    }
    else{
        p=top;
        item=top->num;
        top=top->next;
        free(p);
        printf("%d ",item);
    }
}