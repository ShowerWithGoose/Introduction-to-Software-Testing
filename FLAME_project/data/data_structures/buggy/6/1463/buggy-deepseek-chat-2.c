#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ The loop condition should check for -1 to terminate, not compare with -1; also the input may not end with EOF
    {
        if(flag==1&&i<99)//ÈëÕ» 
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ» 
        {
            if(i==0)
            {
                printf("error\n"); // @@ Should print "error " (with a space) instead of "error\n" (with newline)
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