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
nodeptr isempty() // @@ Error: return type should be int, not nodeptr; the function returns a boolean but is declared as pointer, causing a compilation error.
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
    if(isempty()){printf("error "); // @@ Error: when the stack is empty, the function prints "error " but does not return a value, leading to undefined behavior. The function is declared to return int, so a return statement is required here.
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
    while(scanf("%d",&n)!=-1) // @@ Error: scanf returns the number of items read, not the value read. When -1 is input, scanf returns 1, so the loop never terminates correctly. Should be `while(scanf("%d",&n)==1 && n!=-1)`.
    {
        switch(n)
        {
            case 1:scanf("%d",&item);push(item);break;
            case 0:out=pop();printf("%d ",out);break; // @@ Error: even when pop() prints "error " (empty stack), this line still prints `out`, which contains an undefined value. The program should not print anything after an error.
        }
    }
    return 0;
}