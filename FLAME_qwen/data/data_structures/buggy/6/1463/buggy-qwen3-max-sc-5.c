#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [The condition `!= -1` is incorrect for detecting end-of-file or input failure; `scanf` returns the number of successfully read items, and EOF is typically -1, but the loop should break on EOF or when `-1` operation is read. Also, this fails to detect the `-1` operation properly because it continues looping even after reading -1 as `flag`.]
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ [The condition `i<99` incorrectly restricts pushes to only 99 elements, leaving one slot unused. The stack capacity is 100, so it should allow `i < 100`.]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ»  // @@ [The condition `i>=0` is always true since `i` starts at 0 and is never negative here. More importantly, it doesn't handle underflow correctly: when `i==0`, the stack is empty, so pop should output "error ", but the current logic prints "error\n" (wrong format). Also, the loop doesn't break on `flag == -1`.]
        {
            if(i==0)
            {
                printf("error\n");    // @@ [The problem requires outputting "error " (with a space, not newline). Using `\n` violates the output format.]
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