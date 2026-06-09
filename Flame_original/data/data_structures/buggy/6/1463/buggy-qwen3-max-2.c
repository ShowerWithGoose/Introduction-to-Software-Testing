#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [scanf returns EOF (typically -1) on end-of-file or error, but the loop condition should check for EOF, not != -1. However, more critically, the program does not handle the termination condition (-1) correctly—it continues looping instead of breaking when flag == -1.]
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ [The condition i<99 limits pushes to 99 elements, but the stack capacity is 100 (indices 0–99). It should allow i < 100 to fill the entire stack. This causes premature "error" omission on the 100th push. Also, it fails to print "error " when stack is full.]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ»  // @@ [The condition i>=0 is always true since i starts at 0 and is never negative here. More importantly, when i==0 (empty stack), it prints "error\n" with a newline, but expected output requires "error " with a space and no newline. Also, after printing error, it doesn't adjust i properly (though i isn't decremented in this branch, so it's okay), but the format is wrong.]
        {
            if(i==0)
            {
                printf("error\n");    // @@ [Should output "error " (with space, not newline) to match expected output format.]
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