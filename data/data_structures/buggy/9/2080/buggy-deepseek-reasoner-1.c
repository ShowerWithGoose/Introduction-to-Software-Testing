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
int line[MAX]; // @@ not initialized; should be initialized to 0.
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
        int j=search(point,n,i); // @@ The search function uses global point and index from 0, causing mismatch. Also, if a match is at index 0, it will be treated as no match.
        while(j) // OK, but if j were 0 from a match at index 0, loop would break incorrectly.
        {
            line[i]++; // @@ line[i] may be uninitialized. Should be set to 0 initially.
            j=search(point,n,j); // @@ Same issue as line 17.
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
    for(k=0;k<n;k++) // @@ Error: should be k=1 to <=n to match indexing used in main. Also 0-indexing leads to uninitialized point[0] and failing to find matches.
    {
        if(point[k][0]==point[start][2] && point[k][1]==point[start][3]) // @@ Uses global point instead of parameter u; also indexing mismatch as k goes from 0.
        {
            return k;
        }
    }
    return 0; // @@ 0 is a valid index, but used as sentinel for no match. Could conflict if a match is at index 0.
}