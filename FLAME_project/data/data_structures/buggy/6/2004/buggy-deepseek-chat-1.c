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
    while(scanf("%d",&n)!=-1) // @@ The loop condition is incorrect. scanf returns the number of items read, not -1 on end-of-file. The input ends with -1 as a value, not EOF, so this loop will never terminate correctly. It should check if n == -1 after reading.
    {
        switch(n)
        {
            case 1:scanf("%d",&item);push(item);break;
            case 0:out=pop();printf("%d ",out);break; // @@ When pop() returns due to empty stack, it does not return a value (undefined behavior), and then this line prints an undefined value. The pop function should not print "error " and should instead signal failure, or the main function should check if the stack is empty before calling pop.
        }
    }
    return 0;
}