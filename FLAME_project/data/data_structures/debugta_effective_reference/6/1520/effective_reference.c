#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAXNUM 100

int stack[MAXNUM];
int num=-1;

int main()
{
    int op,n;
    while(scanf("%d",&op)!=EOF)
    {
        if(op==-1)
        {
            system("pause");
            return 0;
        }
        else if(op==1)
        {
            scanf("%d",&n);
            if(num==MAXNUM-1)
            {
                printf("error ");
            }
            else
            {
                stack[++num]=n;
            }
        }
        else if(op==0)
        {
            if(num==-1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",stack[num--]);
            }
        }
    }
    return 0;
}
