#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [The condition `!= -1` is incorrect for detecting end-of-input; `scanf` returns EOF on failure/end, not -1. Also, the problem specifies that -1 in input means end of operations, but this loop condition confuses input value -1 with EOF.]
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ [The condition `i<99` incorrectly limits stack size to 99 elements instead of 100. Since the stack has capacity 100, valid indices are 0 to 99, so push should be allowed when `i < 100`.]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ»  // @@ [The condition `i>=0` is always true since `i` starts at 0 and is never negative here. More importantly, it doesn't check if the stack is empty (`i == 0`) before popping, leading to underflow if pop is called on empty stack. However, inside the block there is a check for `i==0`, but the logic is flawed because it prints "error\n" (with newline) instead of "error " (with space), violating output format.]
        {
            if(i==0)
            {
                printf("error\n");    // @@ [Output uses newline `\n` instead of space ` `. Problem requires all outputs (including "error") to be followed by a space, not a newline.]
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