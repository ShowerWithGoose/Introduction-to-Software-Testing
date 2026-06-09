#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct stack
{
    int num[150];
    int top;
};
struct stack a;
int main()
{
    int i, n, m;
    a.top = 0;
    while(1)
    {
        scanf("%d ",&n);
        if(n == 1)
        {
            scanf("%d ", &m);
            if(a.top > 100)
                printf("error ");
            else
            {
                a.num[++a.top] = m;
            }
        }

        else if(n == 0)
        {
            if(a.top <= 0)
                printf("error ");
            else
            {
                printf("%d ",a.num[a.top]);
                a.top--;
            }
        }
        else if(n == -1)
            break;
    }
    return 0;
}

