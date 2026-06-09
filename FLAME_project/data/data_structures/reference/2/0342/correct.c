/*
 * @Author:
 * @Date: 2022-03-03 19:52:01
 * @LastEditors:
 * @LastEditTime: 2022-03-03 20:18:51
 * @FilePath: example1.c
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 10010
char S[MAXN],*p;
int stack[MAXN],top;
char op[MAXN];

void format()
{
    int i=0,j=0;
    for(;S[i]!='\0';++i)
    if(S[i] != ' ')
        S[j++] = S[i];
    S[j] = '\0';
    return;
}

int getnum()
{
    int ret = 0;
    for(;'0'<= *p && *p <='9';++p)
        ret = ret * 10 + *p - '0';
    return ret;
}

int Judge(char x)
{
    if(x == '+') return 0;
    if(x == '-') return 0;
    if(x == '*') return 1;
    if(x == '/') return 1;
}

int calc(int a,char p,int b)
{
    if(p == '+') return a + b;
    if(p == '-') return a - b;
    if(p == '*') return a * b;
    if(p == '/') return a / b;
}

int main()
{
    gets(S);
    format();
    p = S;
    if(*p == '-') 
    {
        ++p;
        stack[++top] = getnum();
    }
    else stack[++top] = getnum();
    while(*p != '=')
    {
        while(top>1 && Judge(op[top-1])>=Judge(*p))
        {
            --top;
            stack[top] = calc(stack[top],op[top],stack[top+1]);
        }
        op[top] = *p;
        ++p;
        stack[++top] = getnum();
    }
    while(top>1)
    {
        --top;
        stack[top] = calc(stack[top],op[top],stack[top+1]);
    }
    printf("%d",stack[top]);
    return 0;
}


