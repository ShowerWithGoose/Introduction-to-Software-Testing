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
void main() // @@ [The 'main' function should return 'int', not 'void', as per standard C. This causes a compilation error in many environments.]
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
    return 0;
}
void push(int item)
{
    nodeptr p;
    if((p=(nodeptr)malloc(sizeof(node)))==NULL){
        printf("No memory!"); // @@ [According to the problem, when an operation fails (e.g., push on full stack), it should print "error ", but this prints "No memory!" which does not match expected output format. However, since the stack is implemented with linked list and has no fixed capacity check against N=100, this also violates the max capacity constraint of 100. But the immediate compilation issue is in 'main'.]
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
        printf("Error "); // @@ [The problem expects "error " (lowercase), but this prints "Error " (capital E), causing output mismatch. However, this is a runtime logic error, not compilation. The only compilation error is 'void main'.]
    }
    else{
        p=top;
        item=top->num;
        top=top->next;
        free(p);
        printf("%d ",item);
    }
}