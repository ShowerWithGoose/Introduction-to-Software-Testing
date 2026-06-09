#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) @@ // Error: The loop condition should check for EOF or break on -1. Using !=-1 will not stop when flag is -1; also should use !=EOF for standard practice.
    {
        if(flag==1&&i<99)//ÈëÕ» @@ // Error: The condition i<99 prevents pushing when the stack has 99 elements, but the capacity is 100 (indices 0-99). It should be i<100 or no restriction, and handle overflow by printing error.
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ» 
        {
            if(i==0)
            {
                printf("error\n"); @@ // Error: Should output "error " (with space) instead of "error\n" to match expected output format.
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