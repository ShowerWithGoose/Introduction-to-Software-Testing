#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ The loop never breaks when flag is -1; should break on flag==-1 to stop reading.
    {
        if(flag==1&&i<99)//入栈  // @@ Condition i<99 is incorrect; should be i<100 to allow full stack capacity (indices 0-99).
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//出栈 
        {
            if(i==0)
            {
                printf("error\n"); // @@ Should print "error " with a space, not newline, to match expected output format.
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