#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1)
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
                printf("error "); // @@ [The expected output requires "error " followed by a space on the same line as other outputs, not "error\n" which adds a newline and breaks the single-line output format. Also, the reference logic suggests all outputs should be space-separated on one line.]
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