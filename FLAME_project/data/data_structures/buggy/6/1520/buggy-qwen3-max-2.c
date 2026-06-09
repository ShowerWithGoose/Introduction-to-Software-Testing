#include<stdio.h>
#define MAXNUM 3
#define MINNUM 0
int warehouse[MAXNUM];
int num=MINNUM;
int check();

int main()
{
    int op;
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            int n;
            scanf("%d",&n);
            if(check()==-1)
            {
                printf("error ");
            }
            else
            {
                warehouse[num]=n;
                num++;
            }
        }
        if(op==0) // @@ [The condition for pop operation is checked after accessing warehouse[num-1], which may cause undefined behavior when stack is empty (num=0). Also, the check() function returns 0 for empty stack, but the code uses that return value incorrectly: it prints error only if check()==0, but by then 'n' has already been read from an invalid location.]
        {
            int n;
            n=warehouse[num-1]; // @@ [Accessing warehouse[-1] when num is 0 (empty stack), leading to undefined behavior and incorrect output. This line should be after the empty check.]
            if(check()==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",n);
                num--;
            }
        }
        if(op==-1)
        {
            break;
        }
    }
    return 0;
}

int check()
{
    if(MINNUM==num)
        return 0;
    if(MAXNUM==num)
        return -1;
    else
        return 1;
}