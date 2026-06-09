#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ scanf returns the number of successfully read items (1), not -1. The loop condition should check for EOF and explicitly break when flag is -1.
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ The stack capacity is 100, so the condition should be i < 100. It also lacks the logic to print "error " when the stack is full.
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ» 
        {
            if(i==0)
            {
                printf("error\n");     // @@ The output format requires "error " followed by a space, not a newline character.
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