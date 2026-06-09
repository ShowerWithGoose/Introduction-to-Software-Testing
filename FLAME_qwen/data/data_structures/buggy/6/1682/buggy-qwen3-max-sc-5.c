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
void main() // @@ [The return type of 'main' should be 'int', not 'void', as per standard C. This causes a compilation error in many environments.]
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
        printf("No memory!"); // @@ [According to the problem, when the stack is full (which for a linked list implementation isn't bounded by N unless explicitly checked), it should print "error ". However, this implementation uses a linked list with no capacity check against N=100, so it never reports "error " on push when full. But more critically, the problem expects "error " (lowercase) and a space, but this prints "No memory!" which doesn't match expected output format. However, since the error type is Compilation Error, this line is not the cause of compilation failure.]
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
        printf("Error "); // @@ [The problem expects "error " (all lowercase), but this prints "Error " (capital E). However, this is a logic/output mismatch, not a compilation error. The actual compilation error stems from 'void main()'.]
    }
    else{
        p=top;
        item=top->num;
        top=top->next;
        free(p);
        printf("%d ",item);
    }
}