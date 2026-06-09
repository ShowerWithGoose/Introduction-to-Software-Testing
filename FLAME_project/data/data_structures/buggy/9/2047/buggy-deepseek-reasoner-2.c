#include<stdio.h>
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
int main(){
    struct line infor[105];
    int num[105]={0};
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d %d %d %d",&infor[i].x1,&infor[i].y1,&infor[i].x2,&infor[i].y2);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++) 
        {
            if((infor[i].x1<infor[j].x1)||(infor[i].x1==infor[j].x1 && infor[i].y1 < infor[j].y1)) 
            {
                struct line tamp;
                tamp=infor[i];
                infor[i]=infor[j];
                infor[j]=tamp;
            }
        }
    }
    int x2,y2;
    for(int i=0;i<n;i++)
    {   
        x2=infor[i].x2;
        y2=infor[i].y2;
        for(int j=0;j<n,j!=i;j++) @@ // The loop condition uses comma operator, causing j to potentially exceed n, leading to out-of-bounds access. Should be `j<n && j!=i`.
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; @@ // Setting j=0 after incrementing num[i] does not restart the loop from the beginning because the loop's increment statement will execute next, making j=1. To restart scanning from index 0, should set j = -1 so that after increment it becomes 0.
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i;
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}