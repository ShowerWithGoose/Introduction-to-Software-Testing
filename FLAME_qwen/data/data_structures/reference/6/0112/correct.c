#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,max=0,n;
    int zhan[105];
    while(scanf("%d",&n))
    {
        if(n==1)
        {
            if(max>=100)
            {
                printf("error ");
            }
            else
            {
                max++;
                scanf("%d",&zhan[max]);
            }
        }
        if(n==0)
        {
            if(max<=0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",zhan[max]);
                max--;
            }
        }
        if(n==-1) break;
    }
    return 0;
}

