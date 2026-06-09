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
    for(k=0;k<n;k++) // @@ [Loop starts from k=0 but input data is stored from index 1; this causes the first segment (index 1) to be skipped during search, and index 0 (uninitialized) is incorrectly checked. Should loop from k=1 to k<=n.]
    {
        if(point[k][0]==point[start][2] && point[k][1]==point[start][3]) // @@ [Uses global 'point' instead of parameter 'u'; this is inconsistent and may cause confusion, though not a direct bug since 'point' is global. However, it breaks modularity and could lead to errors if 'u' were different.]
        {
            return k;
        }
    }
    return 0; // @@ [Returns 0 to indicate "not found", but 0 is a valid array index in C. Since the main loop uses 1-based indexing, returning 0 correctly breaks the while loop, but this design is fragile. More critically, when k=0 is searched (which contains uninitialized data), it may falsely match or miss matches. The core error is the 0-based loop over a 1-based data structure.]
}