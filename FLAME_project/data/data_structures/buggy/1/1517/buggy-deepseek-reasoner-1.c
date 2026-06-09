#include<stdio.h>
int cun[10],pailie[10],mark[10];
int quanpailie(int num,int n)
{
    if(num!=n)
    {
        for(int i=0;i<n;i++)
        {
            if(mark[i]==0)
            {
                pailie[num]=cun[i];
                mark[i]=1;
                quanpailie(num+1,n);
                mark[i]=0;
            }
        }
    }
    else
    {
    for(int i=0;i<n;i++)
        printf("%d",pailie[i]); // @@ Missing space; should be printf("%d ",pailie[i]) to print numbers separated by spaces
    printf("\n");
}
}