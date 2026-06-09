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
            if((infor[i].x1<infor[j].x1)||(infor[i].x1==infor[j].x1 && infor[i].y1 < infor[j].y1)) @@ // Sorting condition and algorithm are incorrect; this reordering destroys the original relationship between segments, causing chain detection to fail.
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
        for(int j=0;j<n,j!=i;j++) @@ // Comma operator makes loop condition 'j!=i', ignoring array size bound; causes out-of-bounds access and undefined behavior.
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; @@ // Resetting j to 0 inside a loop with a defective condition may cause infinite loop or missed matches.
            }
        }
    }
    int max=num[0]; @@ // 'max' should be initialized to index 0, not to the count value. This leads to later out-of-bounds access.
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i; @@ // Using 'num[max]' with 'max' as a count (not index) causes invalid memory access and incorrect comparison.
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1); @@ // 'max' is not a valid index; prints incorrect starting point and segment count.
    return 0;
}