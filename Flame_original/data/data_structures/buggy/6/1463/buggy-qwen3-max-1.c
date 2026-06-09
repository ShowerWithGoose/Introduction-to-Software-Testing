#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [scanf returns EOF (typically -1) on end-of-file or error, but comparing != -1 may not correctly detect EOF on all systems; should use != EOF for portability and correctness. Also, the loop does not break on -1 operation as required by problem.]
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ [Condition i<99 is incorrect: stack has capacity 100, so valid indices are 0 to 99; push should be allowed when i < 100, not i < 99. This prevents pushing the 100th element.]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ»  // @@ [Condition i>=0 is always true since i starts at 0 and is never negative here; more importantly, pop should check if stack is empty (i == 0), but the logic below handles that partially. However, the bigger issue is missing handling for -1 termination.]
        {
            if(i==0)
            {
                printf("error\n");    // @@ [Problem requires output "error " (with space, no newline); using \n instead of space violates output format. Also, after printing error, program should continue processing, but this is acceptable. However, multiple errors may mix newlines and spaces incorrectly.]
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