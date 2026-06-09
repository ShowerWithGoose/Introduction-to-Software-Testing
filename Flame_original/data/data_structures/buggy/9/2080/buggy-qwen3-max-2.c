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
    for(k=0;k<n;k++) // @@ [Loop starts from index 0, but input data is stored starting from index 1. This causes the first segment (index 1) to be skipped during search, and index 0 (uninitialized) is incorrectly checked.]
    {
        if(point[k][0]==point[start][2] && point[k][1]==point[start][3]) // @@ [Uses global 'point' instead of parameter 'u', which breaks modularity and causes incorrect behavior when the function is intended to work on the passed array. Also, comparing against uninitialized point[0] when k=0 leads to undefined behavior.]
        {
            return k; // @@ [Returns 0 when no match is found, but 0 is also a valid index in C. However, in this program, valid segments are stored from index 1, so returning 0 is used as "not found". But the loop includes k=0 which is invalid, and returning 0 could falsely indicate a match with uninitialized data. Moreover, the calling code treats 0 as "not found", but if by chance point[0] matched, it would incorrectly use garbage data.]
        }
    }
    return 0;
}