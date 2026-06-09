#include<stdio.h>
#define MAXNUM 3 // @@ 栈最大容量应为100，而非3
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
            n=warehouse[num-1]; // @@ 当栈为空时，num=0，num-1=-1，导致数组越界访问；应先检查栈是否为空再取值
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