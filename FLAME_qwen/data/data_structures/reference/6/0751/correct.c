#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 105
int top;
struct stack
{
    int data[MAXSIZE];
    int top;
};
void initStack( ) 
{
	top= -1;
}
int isempty(struct stack *s) 
{ 
  return s->top == -1; 
}
int isfull(struct stack *s) 
{
   return s->top == MAXSIZE - 1 ; 
}

int pushstack(struct stack *s, int a)
{
    if (isfull(s))
    {
        printf("error ");
        return 0;
    }
    s->data[++s->top] = a;
    return 1;
}

int popstack(struct stack *s, int a)
{
    if (s->top == -1)
    {
        printf("error ");
        return 0;
    }
    a = s->data[s->top--];
    printf("%d ", a);
    return 1;
}

int main()
{
	struct stack s;
	 s.top = -1; 
    int a,n;
    int i;
    initStack();
    while (scanf("%d", &a)!=EOF)
    {
        if (a == -1)
            break;
        else if (a == 0)
            popstack(&s, n);
        else if (a == 1)
        {
            scanf("%d", &i);
            pushstack(&s, i);
        }
    }
}

