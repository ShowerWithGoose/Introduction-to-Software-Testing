#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{
  int data;
  struct node *next;
}node;

typedef struct stack
{
 node *top;
 node *buttom;
}stack;

void initial(stack * s)
{
s->top = (node*)malloc(sizeof(node));
s->buttom = s->top;
s->buttom->next= NULL;
return ;
}

void push(stack *s,int elem)
{
 node *pushed=(node*)malloc(sizeof(node));
 pushed->data=elem;
 pushed->next=s->top;
 s->top=pushed;
 return;
}

int empty(stack *s)
{
    if(s->top==s->buttom)
        return 1;
    else
        return 0;
}

void pop(stack *s,int *elem)
{

node *q=s->top;
 *elem=s->top->data;
 s->top=s->top->next;
free(q);
return;
}
int main()
{
int i=0;int number=0;
int po=0;
int a[101]={0};
int *p=a;
stack s;
initial(&s);
while(number!=-1)
{
  scanf("%d",&number);
  a[i++]=number;
}

while (*p!=-1)
{
    if(*p==1)
    {
        push(&s,*(p+1));
        p=p+2;
    }
    else if(*p==0)
    {
       if(empty(&s))
        printf("error ");

      else{

        pop(&s,&po);
        printf("%d ",po);
      }
      p=p+1;
    }
}
return 0;
}



