#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define N 100
int stk[N], top = -1;
void Push()
{
    if(top < N - 1)
    {
        scanf("%d", &stk[top + 1]);
        top ++;
    }
    else
        printf("error ");
}
int Pop()
{
    if(top > -1)
    {
        printf("%d ", stk[top]);
        top --;
    }
    else
        printf("error ");
}
int main()
{
    int op, f = 0;
    while(1)
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            Push();
            break;
        case 0:
            Pop();
            break;
        default:
            f = 1;
            break;
        }
        if(f)
            break;
    } 
    return 0;
}
