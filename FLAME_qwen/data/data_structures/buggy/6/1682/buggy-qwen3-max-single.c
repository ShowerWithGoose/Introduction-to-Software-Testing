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
void main() // @@ [The 'main' function should return 'int', not 'void', as per standard C specification. This causes a compilation error in many compilers.]
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
        printf("No memory!"); // @@ [The problem expects "error " (lowercase) for any error condition, but this prints "No memory!" which does not match expected output format. However, since the error type is Compilation Error, this is not the primary issue. The main compilation issue is with 'void main'.]
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
        printf("Error "); // @@ [The problem expects "error " (lowercase), but this prints "Error " (capital E). While this would cause a wrong answer, it's not a compilation error. The only compilation error is 'void main'.]
    }
    else{
        p=top;
        item=top->num;
        top=top->next;
        free(p);
        printf("%d ",item);
    }
}