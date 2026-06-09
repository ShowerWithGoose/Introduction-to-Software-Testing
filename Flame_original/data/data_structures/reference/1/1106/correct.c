#include <stdio.h>
#include <string.h>
char hashNum[11];
int result[11];
void recurArr(int n,int start,int end,int j)
{
    int i=0;
    if(n==0)
    {
        for(int k=0;k<j;k++)
            printf("%d ",result[k]);
        printf("\n");
        return;
    }
    for(i=start;i<=end;i++)
    {
        if(hashNum[i]==0)
        {
            hashNum[i]=1;
            result[j]=i;
            recurArr(n-1,start,end,j+1);
            hashNum[i]=0;
        }
    }
}
int main()
{
    int m;
    scanf("%d",&m);
    recurArr(m,1,m,0);
    return 0;
}
