#include<stdio.h>
#define MAXNUM 3 @@ [The maximum capacity of the stack should be 100 as per the problem description, not 3.]
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
            n=warehouse[num-1]; @@ [Accessing warehouse[num-1] before checking if the stack is empty leads to undefined behavior or incorrect logic when the stack is empty. The check for emptiness should happen before accessing the element.]
            if(check()==0) @@ [The check function returns 0 when the stack is empty (num == MINNUM). However, the code accesses warehouse[num-1] before this check. Also, the logic for error handling on pop is inverted or misplaced relative to the access.]
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