#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ The condition should be !=EOF instead of !=-1, as scanf returns EOF on end of input, not -1.
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ The condition i<99 is incorrect; the stack capacity is 100, so the maximum index is 99, but the check should be i<100 to allow pushing when i is 99 (the 100th element). Also, the problem requires outputting "error" if push is attempted when stack is full.
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ»  // @@ The condition i>=0 is always true; it should check if the stack is empty (i==0) before attempting pop. Also, the pop logic is incorrect: it should decrement i first, then output the element, but only if stack is not empty.
        {
            if(i==0)
            {
                printf("error\n"); // @@ Should output "error " (with a space, not newline) as per problem specification.
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