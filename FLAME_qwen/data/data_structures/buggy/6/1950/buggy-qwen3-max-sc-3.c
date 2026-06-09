#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
    struct node *pre;
} node;

typedef struct stack
{
    int size;
    node *top;
} stack;

int empty(stack *temp);
void push(stack *temp,int new_num);
void pop(stack *temp);

int main ()
{
    int op,flag=0;
    stack My_stack;
    My_stack.size=0;
    My_stack.top=NULL;
    stack *my_stack=&My_stack;
    while(1)
    {
        if(flag)
        {
            break;
        }
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            int num; // @@ [Variable declaration inside switch-case without proper scoping in older C standards (e.g., C89) may cause compilation error. In C90, declarations must precede statements in a block.]
            scanf("%d",&num);
            push(my_stack,num);
            break;
            case 0:
            pop(my_stack);
            break;
            case -1:
            flag=1;
            break;
        }
    }
    return 0;
}

// stack *initi()
// {
//     stack my_stack;
//     my_stack.size=0;
//     my_stack.top=NULL;
//     return &my_stack;
// }

int empty(stack *temp)
{
    if(temp->size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *temp,int new_num)
{
    if(temp->size==100)
    {
        printf("error ");
    }
    else 
    {
        node *new=(node *)malloc(sizeof(node));
        new->next=NULL;
        new->pre=NULL;
        new->num=new_num;

        if(empty(temp))
        {
            temp->top=new;
        }
        else
        {
            temp->top->next=new;
            new->pre=temp->top;
            temp->top=new;
        }
        temp->size++;
    }
}

void pop(stack *temp)
{
    if(empty(temp))
    {
        printf("error ");
    }
    else
    {
        int huan_cun=temp->top->num;
        node *oprate=temp->top;
        if(temp->size==1)
        {
            temp->top=NULL;
        }
        else
        {
            temp->top=temp->top->pre;
            temp->top->next=NULL;
        }
        free(oprate);
        temp->size--;
        printf("%d ",huan_cun);
    }
}