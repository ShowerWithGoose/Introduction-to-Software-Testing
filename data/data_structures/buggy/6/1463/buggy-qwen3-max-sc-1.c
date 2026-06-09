#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [scanf returns EOF (typically -1) on end-of-file or error, but condition should check for EOF, not != -1; however, the real issue is that the loop doesn't break on -1 operation as required by problem]
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ [condition i<99 is incorrect; stack has capacity 100, so valid indices are 0..99, meaning push allowed when i<100, not i<99]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ»  // @@ [condition i>=0 is always true since i starts at 0 and only decremented after check; also, pop on empty stack (i==0) should print "error ", not "error\n"]
        {
            if(i==0)
            {
                printf("error\n");    // @@ [should output "error " with space, not newline; also missing handling for -1 termination]
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