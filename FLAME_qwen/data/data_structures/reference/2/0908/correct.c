#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#define LIFO_MAX_LENGTH 1002
#define LIFO_Type long

typedef struct
{
    LIFO_Type data[LIFO_MAX_LENGTH];
    bool dataType[LIFO_MAX_LENGTH]; //0 stands operation while 1 stands number
    int top; //default: -1
}LIFO;

bool LIFO_Push(LIFO *src,const LIFO_Type value);
bool LIFO_Pop(LIFO *src,LIFO_Type *answer);
int judgePriority(const char a,const char b);

int main()
{
    LIFO stack,operation;
    stack.top = -1;
    operation.top = -1;
    long tempTrash;
    char temp[100];
    char calc[100]={0};
    gets(temp);
    int length = 0;
    for(int i=0;temp[i]!='\0';i++)
    {
        if(temp[i]==' ')continue;
        if(temp[i]=='=')continue;
        calc[length++] = temp[i];
    }
    calc[length] = '\0';
    for(int i=0;i<length;i++)
    {
        if(calc[i]=='(')
        {
            LIFO_Push(&operation,calc[i]);
        }
        else if(calc[i]=='*'||calc[i]=='/'||calc[i]=='+'||calc[i]=='^'||calc[i]=='-')
        {
            while(operation.top>=0&&judgePriority(calc[i],operation.data[operation.top])<=0)
            {
                LIFO_Push(&stack,operation.data[operation.top]);
                stack.dataType[stack.top] = 0;
                LIFO_Pop(&operation,&tempTrash);
            }
            if(calc[i]=='-'&&(i==0||calc[i-1]=='('))
            {
                LIFO_Push(&stack,0);
                stack.dataType[stack.top] = 1;
            }
            LIFO_Push(&operation,calc[i]);
        }
        else if(calc[i]==')')
        {
            while(operation.data[operation.top]!='(')
            {
                LIFO_Push(&stack,operation.data[operation.top]);
                stack.dataType[stack.top] = 0;
                LIFO_Pop(&operation,&tempTrash);
            }
            LIFO_Pop(&operation,&tempTrash);
        }
        else
        {
            int tempNum;
            tempNum = atoi(calc+i);
            LIFO_Push(&stack,tempNum);
            stack.dataType[stack.top] = 1;
            while(i+1<length&&calc[i+1]<='9'&&calc[i+1]>='0')i++;

        }

    }
    //printf("#");
    while(LIFO_Pop(&operation,&tempTrash))
    {
        LIFO_Push(&stack,tempTrash);
        stack.dataType[stack.top] = 0;
    }
    operation.top = -1;
    for(int i=0;i<=stack.top;i++)
    {
        if(stack.dataType[i])
        {
            LIFO_Push(&operation,stack.data[i]);
        }
        else
        {
            LIFO_Pop(&operation,&tempTrash);
            switch(stack.data[i])
            {
            case '+':
                operation.data[operation.top] += tempTrash;
                break;
            case '-':
                operation.data[operation.top] -= tempTrash;
                break;
            case '*':
                operation.data[operation.top] *= tempTrash;
                break;
            case '/':
                operation.data[operation.top] /= tempTrash;
                break;
            case '^':
                operation.data[operation.top] = pow(operation.data[operation.top],tempTrash);
                break;
            default:
                break;
            }
        }
    }
    printf("%ld",operation.data[0]);
    return 0;
}

bool LIFO_Push(LIFO *src,const LIFO_Type value)
{
    if(src->top == LIFO_MAX_LENGTH - 1)
    {
        return false;
    }
    else
    {
        src->data[++src->top] = value;
        return true;
    }
    return false;
}

bool LIFO_Pop(LIFO *src,LIFO_Type *answer)
{
    if(src->top == -1)
    {
        return false;
    }
    else
    {
        *answer = src->data[src->top];
        src->data[src->top--] = 0;
        return true;
    }
}

int judgePriority(const char a,const char b)
{
    if(b=='(')return 1;
    if(a=='^')return 1;
    if(a==b)return 0;
    else if(a=='+'||a=='-')
    {
        if(b=='+'||b=='-')return 0;
        else return -1;
    }
    else if(a=='*'||a=='/')
    {
        if(b=='+'||b=='-')return 1;
        else if(b=='^')return -1;
        else return 0;
    }
}



