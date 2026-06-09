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
    for(k=0;k<n;k++) // @@ [Loop starts from k=0, but input data is stored from index 1 to n. This causes the search to check uninitialized point[0] and miss valid segments stored at indices 1..n. Should loop from k=1 to k<=n.]
    {
        if(point[k][0]==point[start][2] && point[k][1]==point[start][3]) // @@ [Uses global 'point' instead of parameter 'u', which breaks modularity and causes incorrect behavior if 'u' differs from 'point'. Should use u[k][0] and u[k][1]. Also, since k starts at 0 and point[0] is uninitialized, this may compare garbage values.]
        {
            return k;
        }
    }
    return 0; // @@ [Returns 0 to indicate "not found", but 0 is a valid array index in C. In the calling loop, j=0 terminates the while loop, which is correct logically, but combined with the off-by-one indexing (data in 1..n, search includes 0), it leads to missed connections and incorrect counts.]
}