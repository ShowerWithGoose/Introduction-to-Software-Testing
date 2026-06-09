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
nodeptr isempty()
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
    while(scanf("%d",&n)!=-1) // @@ The loop condition should check for -1 as the end-of-operations marker, but scanf returns the number of items read, not the value. The correct condition should be `while(scanf("%d",&n) == 1 && n != -1)` to properly detect the end of input.
    {
        switch(n)
        {
            case 1:scanf("%d",&item);push(item);break;
            case 0:out=pop();printf("%d ",out);break; // @@ When pop() returns due to an empty stack (error case), it does not return a value, so `out` is uninitialized. This causes an extra garbage value to be printed after "error". The pop function should handle the error case without returning an undefined value.
        }
    }
    return 0;
}