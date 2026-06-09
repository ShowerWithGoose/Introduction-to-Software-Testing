#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100
int s[MAX];
int top;


int main()
{
    top = -1;
    int a, n;
    while (~scanf("%d ", &a))
    {
        if (a == 1)
        {
            scanf("%d ", &n);
            if (top == MAX)
            {
                printf("error ");
            }
            else
                s[++top] = n;
        }
        if (a == 0)
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
                printf("%d ", s[top--]);
        }
        if (a == -1)
        {
            break;
        }
    }
    return 0;
}
