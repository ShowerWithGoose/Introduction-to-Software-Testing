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
nodeptr isempty() // @@ Return type mismatch: function is declared to return nodeptr (pointer) but returns a boolean/int expression. Should be int.
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
    if(isempty()){printf("error "); // @@ Missing return statement in this branch. The function is declared to return int, so all control paths must return a value, causing a compilation error.
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