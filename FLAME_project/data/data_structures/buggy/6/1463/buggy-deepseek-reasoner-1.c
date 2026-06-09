#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [The loop condition should stop when flag==-1, not when scanf returns -1. This causes an extra iteration that ignores the -1 operation, and if there were additional numbers after -1, they would be processed incorrectly. The proper condition is while(scanf("%d",&flag)==1 && flag!=-1).]
    {
        if(flag==1&&i<99) // @@ [The stack capacity is 100, so push should be allowed when i<100, not i<99. This error effectively reduces usable capacity to 99, and also fails to produce an "error" when the stack is full (i==100).]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ» 
        {
            if(i==0)
            {
                printf("error\n"); // @@ [Output format requires "error " (with space, no newline). The newline causes the output to be split into multiple lines, leading to wrong answer.]
            } 
            else{
                    i--;
                printf("%d ",zhan[i]);
//                printf(" %d\n",i);
            }
        }
//        else
//        {
//            printf("error\n");
//        }
    }
    return 0;
}