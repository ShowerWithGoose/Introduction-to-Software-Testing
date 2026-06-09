#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define maxn 200000

char buf[maxn];
int buf_d;
int stack[maxn], top;

char get_c()
{
    return buf[buf_d++];
}

void withdraw()
{
    --buf_d;
    return ;
}

int get_int()
{
    int res = 0;
    char ch;
    while((ch = get_c()) == ' ');
    withdraw();
    while(isdigit(ch = get_c()))
        res = res * 10 + ch - '0';
    withdraw();
    return res;
}

int get_op()
{
    char ch;
    do
    {
        ch = get_c();
    } while (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '=');
    switch (ch)
    {
        case '+': return 1;
        case '-': return -1;
        case '*': return 3;
        case '/': return 4;
        case '=': return 5;
        default: return 0;
    }
    return 0;
}

int op_first()
{
    for(int i = 1; buf[i] != '\0'; ++i)
    {
        if(isblank(buf[i])) continue;
        else if(buf[i] == '+') return 1;
        else if(buf[i] == '-') return -1;
        else if(isdigit(buf[i])) return 0;
    }
}

int main()
{
    buf[0] = ' ';
    gets(buf+1);
    int flag = op_first();
    if(flag == 0) buf[0] = '+';
    while(1)
    {
        int op = get_op();
        if(op == 5) break;
        int num = get_int();
        if(op < 2)  stack[++top] = op * num;
        else if(op == 3) stack[top] *= num;
        else if(op == 4) stack[top] /= num;
    }
    int ans = 0;
    for(int i = 1; i <= top; ++i)
        ans += stack[i];
    printf("%d", ans);
    return 0;
}
