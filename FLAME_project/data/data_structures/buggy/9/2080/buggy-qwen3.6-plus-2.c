//
//  main.c
//  1363
//
//  Created by  on 2024/3/19.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 105
int point[MAX][4];
int line[MAX];
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
    for(k=1;k<=n;k++) // @@ The loop index k should start from 1 and go up to n (inclusive) because the points are stored in indices 1 to n in the main function. Using k=0 accesses uninitialized data or index 0 which is not used, and stopping at k<n misses the last element if n is the count. Also, the array 'point' is global, so passing 'u' is redundant but the logic error is the loop bounds matching the 1-based indexing used in main.
    {
        if(point[k][0]==point[start][2] && point[k][1]==point[start][3])
        {
            return k;
        }
    }
    return 0;
}