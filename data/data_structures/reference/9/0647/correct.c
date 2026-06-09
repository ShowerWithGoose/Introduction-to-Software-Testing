#include<stdio.h>
#include<stdlib.h>
int link[110][110];
int main()
{
    typedef struct LINE
    {
        int x1;
        int y1;
        int x2;
        int y2;
        //struct LINE *link;
    }line;
    line L[110];
    int n;
    for(int i=0;i<110;i++)
        for(int j=0;j<110;j++)
            link[i][j] = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&L[i].x1,&L[i].y1,&L[i].x2,&L[i].y2);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(L[j].x1 == L[i].x2 && L[j].y1 == L[i].y2)
                link[i][j] = 1;
        }
    }
    int j=0;
    int cnt = 0, max = 0;
    int maxx,maxy;
    for(int i=0; i<n; i++)
    {
        cnt =0; 
        int cmp = i;
        while(!(link[i][j]==0 && j==n-1))
        {
            if(link[i][j]==1) {i=j; j=0; cnt++;}
            else j++;
        }
        if(cnt > max) {max = cnt; maxx = L[cmp].x1; maxy = L[cmp].y1;}
        i=cmp; j=0;
    }
    printf("%d %d %d",max+1,maxx,maxy);
}
