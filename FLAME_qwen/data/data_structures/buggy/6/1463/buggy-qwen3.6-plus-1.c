#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ The loop lacks a break statement when flag == -1 to terminate operations as specified, and should ideally check for EOF.
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ The condition i<99 incorrectly limits stack capacity to 99 instead of 100, and it fails to print "error " when the stack is full.
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ» 
        {
            if(i==0)
            {
                printf("error\n");    // @@ Should print "error " followed by a space instead of a newline to maintain the required single-line output format.
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