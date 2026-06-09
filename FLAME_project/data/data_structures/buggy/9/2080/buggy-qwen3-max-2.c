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
    
    printf("%d %d %d",ans+1,ans_x,ans_y); // @@ [The logic assumes that 'line[i]' counts the number of connections, so adding 1 gives total segments. However, 'search' returns 0 when no next segment is found, and also uses 0-based indexing inconsistently with 1-based loop. Also, 'search' checks point[k] where k starts from 0, but input is stored from index 1, so it never checks valid segments correctly.]
    
    return 0;
}

int search(int u[][4],int n,int start)
{
    int k;
    for(k=0;k<n;k++) // @@ [Loop runs from k=0 to n-1, but input segments are stored from index 1 to n. So point[0] is uninitialized garbage, and valid segments (indices 1..n) are not fully or correctly checked because condition uses point[k] instead of u[k]. Also, 'start' is in 1..n range, but compared against point[k] which includes invalid index 0.]
    {
        if(point[k][0]==point[start][2] && point[k][1]==point[start][3]) // @@ [Uses global 'point' instead of parameter 'u', and compares against uninitialized point[0] due to k starting at 0. Should use u[k] and loop from k=1 to n or adjust indexing consistently.]
        {
            return k;
        }
    }
    return 0; // @@ [Returning 0 indicates "not found", but 0 is also a valid array index in C. In the calling loop, 'while(j)' treats 0 as false, which is okay, but since valid indices are 1..n, returning 0 is acceptable only if 0 is never a valid match — however, due to incorrect indexing, this causes missed matches.]
}