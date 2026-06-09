#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int date;
    struct node *link;
}node;
typedef struct node *nodeptr;
nodeptr top;  
void inti(){
    top = NULL;
}
nodeptr isempty() // @@ [Function should return int, not nodeptr. The return type is incorrect; it should be int to match the usage in pop().]
{
    return top == NULL;
}
void push(int item)
{
    
    nodeptr p;
    if((p=(nodeptr)malloc(sizeof(node)))==NULL){
        printf("error ");
        
    }else{
        p->date=item;
        p->link=top;
        top=p;
    }
}
int pop()
{
    nodeptr p;
    int item;
    if(isempty()){printf("error ");
    }else{p=top;
    item=top->date;
    top=top->link;
    free(p);
    return item;
    }
}
int main()
{
    int n,item,out;
    inti();
    while(scanf("%d",&n)!=-1) // @@ [The loop condition should check for -1 to terminate, but the input format uses -1 as end marker. However, scanf returns EOF on end of file, not -1. The condition should be while(scanf("%d",&n)==1 && n!=-1) to properly handle the -1 termination.]
    {
        switch(n)
        {
            case 1:scanf("%d",&item);push(item);break;
            case 0:out=pop();printf("%d ",out);break; // @@ [When pop() prints "error " due to empty stack, it does not return a value, so out is uninitialized. This leads to undefined behavior. The pop() function should not print "error " itself; instead, it should return a sentinel value or the main function should handle the error.]
        }
    }
    return 0;
}