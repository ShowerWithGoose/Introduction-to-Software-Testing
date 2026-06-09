#include<stdio.h>
#define MAXNUM 3 // @@ The maximum capacity of the stack should be 100 as per the problem description, not 3. This causes premature "error" outputs when the stack isn't actually full.
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
        if(op==0)
        {
            int n;
            n=warehouse[num-1]; // @@ This line accesses warehouse[num-1] before checking if the stack is empty. If the stack is empty (num==0), this accesses warehouse[-1], which is undefined behavior. The check for emptiness happens after this access.
            if(check()==0) // @@ The check function returns 0 when the stack is empty (num==MINNUM). However, the logic here is flawed because 'n' was already accessed potentially out of bounds. Also, the condition should ideally prevent the access entirely.
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