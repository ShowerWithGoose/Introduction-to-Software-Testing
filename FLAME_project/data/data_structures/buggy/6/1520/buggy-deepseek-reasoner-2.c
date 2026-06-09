#include<stdio.h>
#define MAXNUM 3 // @@ should be 100 to match the problem's maximum capacity of 100; with only 3 spaces, many pushes fail.
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
            n=warehouse[num-1]; // @@ access occurs before checking if stack is empty; when num==0, this reads warehouse[-1] causing undefined behavior.
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