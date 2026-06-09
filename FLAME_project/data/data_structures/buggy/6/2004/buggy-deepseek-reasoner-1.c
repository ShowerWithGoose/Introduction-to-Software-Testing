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
    
    nodeptr p; // @@ [Missing capacity check: stack may exceed max size 100. Should maintain a counter and reject push when full.]
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
    if(isempty()){printf("error "); // @@ [Missing return statement: after printing error, the function does not return a value, causing out to be uninitialized in main.]
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
    while(scanf("%d",&n)!=-1) // @@ [Loop condition should check n != -1 to stop on -1 input; scanf returns 1, not -1, so loop does not terminate when -1 is read, but only on EOF. Works for this specific input but is logically incorrect.]
    {
        switch(n)
        {
            case 1:scanf("%d",&item);push(item);break;
            case 0:out=pop();printf("%d ",out);break;
        }
    }
    return 0;
}