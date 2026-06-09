#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [scanf returns the number of successfully read items, not -1 on EOF; should compare with EOF or check return value properly]
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
                printf("error\n");    // @@ [should output "error " with a space and no newline to match expected output format]
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