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
        for(int j=0;j<n,j!=i;j++) // @@ [Error: The loop condition uses comma operator, which evaluates to j!=i, ignoring j<n. This causes an infinite loop when j!=i, and the loop never terminates because j is reset to 0 inside.]
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; // @@ [Error: Resetting j to 0 causes the loop to restart from the beginning each time a match is found, leading to potential infinite loops and incorrect counting.]
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i; // @@ [Error: Using num[max] as index is incorrect; max should be compared with i, not num[max]. This will cause undefined behavior or incorrect max selection.]
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}