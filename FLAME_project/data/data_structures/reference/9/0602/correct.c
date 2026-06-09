#include<stdio.h>

int main()
{
    int start[105][2]={{0}},end[105][2]={{0}},num,i,j,count[105],max=0,ans;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d %d %d %d",&start[i][0],&start[i][1],&end[i][0],&end[i][1]);
    }
    for(i=0;i<num;i++)
    {
        count[i]=1;
    }
    for(i=0;i<num;i++)
    {
        for(j=0;j<num;j++)
        {
            if(j==i)
            {
                continue;
            }
            if(end[i][0]==start[j][0]&&end[i][1]==start[j][1])
            {
                count[i]+=count[j];
                end[i][0]=end[j][0];
                end[i][1]=end[j][1];
                start[j][0]=start[i][0];
                start[j][1]=start[i][1];
                count[j]=count[i];
            }
        }
    }
    for(i=0;i<num;i++)
    {
        if(count[i]>max)
        {
            max=count[i];
            ans=i;
        }
    }
    printf("%d %d %d",max,start[ans][0],start[ans][1]);
}

