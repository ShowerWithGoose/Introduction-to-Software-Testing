#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
    char* base;
    char* top;
    int StackSize;
}toStack;
typedef struct
{
    int* base;
    int* top;
    int StackSize;
}Stack;
void toinitStack(toStack* s)
{
    s->base = (char *)malloc(100 * sizeof(char));
    if(!s->base)
        exit(0);
    s->top = s->base;
    s->StackSize = 100;
}
void initStack(Stack* s)
{
    s->base = (int *)malloc(100 * sizeof(int));
    if(!s->base)
        exit(0);
    s->top = s->base;
    s->StackSize = 100;
}
void toPush(toStack* s, char e)
{
    if(s->top - s->base >= s->StackSize)
    {
        s->base = (char *)realloc(s->base, (s->StackSize + 100) * sizeof(char));
        if(!s->base)
            exit(0);
        s->top = s->base + s->StackSize;
        s->StackSize = s->StackSize + 100;
    }
    *(s->top) = e;
    s->top++;    
}
void Push(Stack* s, int e)
{
    if(s->top - s->base >= s->StackSize)
    {
        s->base = (int *)realloc(s->base, (s->StackSize + 100) * sizeof(int));
        if(!s->base)
            exit(0);
        s->top = s->base + s->StackSize;
        s->StackSize = s->StackSize + 100;
    }
    *(s->top) = e;
    s->top++;    
}
void toPop(toStack* s, char *e)
{
    if(s->top == s->base)
        return;
    *e = *--(s->top);
}
void Pop(Stack* s, int *e)
{
    if(s->top == s->base)
        return;
    *e = *--(s->top);
}
int toLen(toStack* s)
{
    return s->top - s->base;
}
int Len(Stack* s)
{
    return s->top - s->base;
}
int prio(char op1, char op2)
{
    if((op1 == '/' || op1 == '*') && (op2 == '+' || op2 == '-'))
        return 1;
    else return 0;
}
char buff[100];
void Change(toStack s, char str[])
{
    int i = 0, j = 0;
    char e;
    while(str[i] != '=' && str[i] != '\0')
    {
        while(isdigit(str[i]))
        {
            buff[j++] = str[i++];
            if(!isdigit(str[i]))
                buff[j++] = ' ';
        }
        if(str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
        {
            if(!toLen(&s))
            {
                toPush(&s, str[i++]);
            }
            else if(prio(str[i], *(s.top-1)))
            {
                toPush(&s, str[i++]);
            }
            else
            {
                while(!prio(str[i], *(s.top-1)) && toLen(&s))
                {
                    toPop(&s, &e);
                    buff[j++] = e;
                    buff[j++] = ' ';
                }
                toPush(&s, str[i++]);
            }
        }
        
        /*if(str[i] == '*' || str[i] == '/')
        {
            toPush(&s, str[i++]);
        }
        else if(str[i] == '+' || str[i] == '-')
        {
            if(!toLen(&s))
            {
                toPush(&s, str[i++]);
            }
            else
            {
                while(toLen(&s))
                {
                    toPop(&s, &e);
                    buff[j++] = e;
                    buff[j++] = ' ';
                }
                toPush(&s, str[i++]);
            }
        }*/
        
        else
        {
            i++;
        }
    }
    while(toLen(&s))
    {
        toPop(&s, &e);
        buff[j++] = e;
        buff[j++] = ' ';
    }
    buff[j] = '\0';
}

void calc(Stack s)
{
    int i = 0, j = 0, e, d;
    char num[100];
    while(buff[i] != '\0')
    {
        if(isdigit(buff[i]))
        {
            j = 0;
            while(isdigit(buff[i]))
            {
                num[j++] = buff[i++];
            }
            e = atoi(num);
            Push(&s, e);
            memset(num, 0, sizeof(num));
        }
        else
        {
            switch (buff[i++])
            {
            case '+':
                Pop(&s, &d);
                Pop(&s, &e);
                Push(&s, d+e);
                break;
            
            case '-':
                Pop(&s, &d);
                Pop(&s, &e);
                Push(&s, e-d);
                break;
            case '*':
                Pop(&s, &d);
                Pop(&s, &e);
                Push(&s, d*e);
                break;
            case '/':
                Pop(&s, &d);
                Pop(&s, &e);
                Push(&s, e/d);
                break;
            }
        }
    }
    Pop(&s, &d);
    printf("%d", d);
}

int main()
{
    toStack s;
    toinitStack(&s);
    char str[100];
    gets(str);
    Change(s, str);
    Stack(ans);
    initStack(&ans);
    calc(ans);
    return 0;
}