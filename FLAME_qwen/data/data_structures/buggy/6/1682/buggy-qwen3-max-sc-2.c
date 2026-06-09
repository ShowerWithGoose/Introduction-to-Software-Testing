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
void main() // @@ [The 'main' function should return 'int', not 'void', as per standard C. This causes a compilation error in strict environments.]
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
        printf("No memory!"); // @@ [According to the problem, when an operation fails (e.g., push on full stack), output "error ". However, this prints "No memory!" which does not match expected output format. Also, the stack has a max capacity of 100, but this implementation doesn't enforce it, leading to potential logic errors. But since the error type is Compilation Error, this line isn't the cause of compilation failure.]
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
        printf("Error "); // @@ [The problem expects "error " (lowercase), but this prints "Error " (capital E). However, this is a logic/output mismatch, not a compilation error. The actual compilation error stems from 'void main()'.]
    }
    else{
        p=top;
        item=top->num;
        top=top->next;
        free(p);
        printf("%d ",item);
    }
}