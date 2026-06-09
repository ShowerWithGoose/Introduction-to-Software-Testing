#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define Max 100
struct stack
{
    int data[Max];
    int top;
};
struct stack s;
void push(struct stack s, int x)
{
    ;
}
int pop(struct stack s)
{
    int x;
    if (s.top == -1)
        return 0;
    x = s.data[s.top--];
    return x;
}
int a[200], k, tape, value, j, flag;
int main()
{
    s.top = -1;
    char sb[500];
    gets(sb);
    for (j = 0; j < 500; j++)
    {
        if (sb[j] >= '0' && sb[j] <= '9')
        {
            a[k] = a[k] * 10 + sb[j] - '0';
            if (sb[j - 1] == '-')
                flag++;
            if (flag == 1 && !isdigit(sb[j + 1]))
            {
                a[k] = a[k] * (-1);
                flag = 0;
            }
        }
        else
        {
            if (sb[j] == '-')
                continue;
            k++;
            continue;
        }
    }
    for (int i = 0; a[i] != -1; i++)
    {
        if (a[i] == 1)
        {
            if (s.top == Max - 1)
                printf("error ");
            else
            {
                s.data[++s.top] = a[i + 1];
                i++;
            }
        }
        if (a[i] == 0)
        {
            if (s.top == -1)
                printf("error ");
            else
            {
                tape = pop(s);
                s.top--;
                printf("%d ", tape);
            }
        }
    }
}

