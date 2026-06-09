#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [The condition should check for EOF, not -1. scanf returns EOF on failure/end-of-input, not -1. This causes the loop to never terminate properly when input ends.]
    {
        if(flag==1&&i<99)//ÈëÕ» // @@ [The condition i<99 is incorrect; it should be i<100 to allow pushing up to 100 elements (indices 0 to 99). This prevents using the full capacity of the stack.]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ» // @@ [The condition i>=0 is always true since i starts at 0 and is only decremented after checking. The real check for empty stack should be done inside, but the logic here is flawed because it allows pop even when i==0 without proper handling in all cases. Also, the error message uses newline instead of space.]
        {
            if(i==0)
            {
                printf("error\n");    // @@ [The problem requires outputting "error " with a space, not a newline. This formatting mismatch causes incorrect output.]
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