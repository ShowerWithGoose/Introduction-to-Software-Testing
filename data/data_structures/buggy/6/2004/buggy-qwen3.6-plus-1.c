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
nodeptr isempty() // @@ Return type should be int, as the function returns a boolean expression (top == NULL), not a pointer.
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
    if(isempty()){printf("error "); // @@ Missing return statement for the error case in a non-void function, which causes a compilation error.
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
    while(scanf("%d",&n)!=-1)
    {
        switch(n)
        {
            case 1:scanf("%d",&item);push(item);break;
            case 0:out=pop();printf("%d ",out);break;
        }
    }
    return 0;
}