#include <stdio.h>
#include <stdlib.h>
#define MAX 105
int point[MAX][4];
int line[MAX]; // @@ [Uninitialized array: should be initialized to zero, e.g., int line[MAX] = {0};]
int search(int u[][4],int n,int start);   //接收起始行，返回连续点的行数，没有返回0
int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d",&n);
    int i,ans=0,ans_x=0,ans_y=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&point[i][0],&point[i][1],&point[i][2],&point[i][3]);
    }
    
    for(i=1;i<=n;i++)
    {
        int j=search(point,n,i);
        while(j)
        {
            line[i]++;
            j=search(point,n,j);
        }
        if(line[i]>=ans)
        {
            ans=line[i];
            ans_x=point[i][0];
            ans_y=point[i][1];
        }
    }
    
    printf("%d %d %d",ans+1,ans_x,ans_y);
    
    return 0;
}

int search(int u[][4],int n,int start)
{
    int k;
    for(k=0;k<n;k++) // @@ [Loop indices should start from 1 and go to n because data is stored from index 1; also condition should be k<=n]
    {
        if(point[k][0]==point[start][2] && point[k][1]==point[start][3]) // @@ [Uses global point instead of parameter u; also indices wrong (k starting at 0, data at 1..n)]
        {
            return k;
        }
    }
    return 0;
}