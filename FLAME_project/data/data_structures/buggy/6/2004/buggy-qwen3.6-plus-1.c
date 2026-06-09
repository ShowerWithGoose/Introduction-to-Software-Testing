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
    while(scanf("%d",&n)!=-1) // @@ The loop condition is incorrect. scanf returns the number of successfully read items, not the value read. It should check if n != -1 after reading. Also, when scanf fails or reaches EOF, it doesn't return -1 necessarily in the way intended here for stopping on -1 input. The correct logic is to read n, then check if n == -1 to break.
    {
        switch(n)
        {
            case 1:scanf("%d",&item);push(item);break;
            case 0:out=pop();printf("%d ",out);break; // @@ When pop() encounters an empty stack, it prints "error " but does not return a valid value. The variable 'out' remains uninitialized or holds garbage/previous value, which is then printed. This causes the wrong output (e.g., printing 6 instead of skipping or handling error correctly). The print statement should only execute if pop was successful.
        }
    }
    return 0;
}