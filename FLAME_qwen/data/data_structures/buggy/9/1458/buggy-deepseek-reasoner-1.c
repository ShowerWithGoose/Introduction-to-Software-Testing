#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct _line
{
    int x1;
    int y1;
    int x2;
    int y2;
} Line,*Lineptr;

Line L[110]; // @@ Array size too small; may overflow for inputs with more than 110 segments (typical max is 150).
int arr[110][4]; // @@ Array size too small; may overflow for inputs with more than 110 segments.

int main()
{
    int i,j,n,k=0,flag=0,max=0,cnt=1,max_k=-1,cnt_i=0;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&arr[cnt_i][0],&arr[cnt_i][1],&arr[cnt_i][2],&arr[cnt_i][3]);
        if(arr[cnt_i][0]<arr[cnt_i][2])
        {
            cnt_i++;
        }
        // The condition reduces cnt_i when x1 >= x2, but constraints guarantee x1<x2.
        // However, later loops use n instead of cnt_i, causing potential access to uninitialized arr entries.
    }
    
    for(i=0;i<n;i++) // @@ Loop uses n, but arr may have only cnt_i valid entries (if any input violated x1<x2, which per constraints it does not, but the code still assumes n entries).
    {
        for(j=0;j<n;j++) // @@ Same issue: n used instead of actual number of stored segments.
        {
            if(i==j)
            {
                continue;
            }
            if(arr[i][0]==arr[j][2]&&arr[i][1]==arr[j][3])
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            L[k].x1=arr[i][0];
            L[k].y1=arr[i][1];
            L[k].x2=arr[i][2];
            L[k].y2=arr[i][3];
            k++;
        }
        flag=0;
    }
    
    for(i=0;i<k;i++)
    {
        cnt=1;
        for(j=0;j<n;j++) // @@ Uses n instead of actual segment count; also does not mark segments as used, which could lead to incorrect chaining.
        {
            if(flag==1)
            {
                j=0;
                flag=0;
            }
            if(L[i].x2==arr[j][0]&&L[i].y2==arr[j][1])
            {
                L[i].x2=arr[j][2];
                L[i].y2=arr[j][3];
                flag=1;
                cnt++;
            }
        }
        if(cnt>=max)
        {
            max=cnt;
            max_k=i;
        }
    }
    
    printf("%d ",max);
    printf("%d %d",L[max_k].x1,L[max_k].y1); // @@ If max_k remains -1 (when k=0), this accesses invalid memory.
    return 0;
}