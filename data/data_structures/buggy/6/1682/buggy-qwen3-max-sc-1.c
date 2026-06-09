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
void main() // @@ [The 'main' function should return 'int', not 'void', as per standard C. Using 'void main()' is non-standard and may cause compilation errors or undefined behavior.]
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
        printf("No memory!"); // @@ [According to the problem, if a push is attempted when the stack is full, output "error ". However, this implementation uses a linked list with no capacity check against MAXSIZE=100. Also, it prints "No memory!" instead of "error ", which violates the output specification. Additionally, the program should continue processing after an error, but this message doesn't match expected output format.]
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
        printf("Error "); // @@ [The problem requires printing "error " (lowercase), but this prints "Error " (capital E). This case mismatch causes the output to differ from expected.]
    }
    else{
        p=top;
        item=top->num;
        top=top->next;
        free(p);
        printf("%d ",item);
    }
}