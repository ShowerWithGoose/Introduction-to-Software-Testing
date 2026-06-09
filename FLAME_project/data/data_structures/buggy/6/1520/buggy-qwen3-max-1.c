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
        if(op==0) // @@ [The pop operation uses the value before checking if the stack is empty, leading to undefined behavior when stack is empty. Also, the condition in check() for empty stack returns 0, but the code checks `if(check()==0)` after already accessing `warehouse[num-1]`, which is invalid when num==0.]
        {
            int n;
            n=warehouse[num-1]; // @@ [Accessing warehouse[-1] when num is 0 (empty stack), causing undefined behavior. This should only happen after confirming the stack is not empty.]
            if(check()==0) // @@ [The logic of check() is flawed: it returns 0 when stack is empty (num==MINNUM==0), but this check happens after already reading from an invalid index. Moreover, the condition should be checked BEFORE accessing the array.]
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