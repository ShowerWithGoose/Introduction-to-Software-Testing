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
        for(int j=0;j<n,j!=i;j++) // @@ [Error: The loop condition uses comma operator, which evaluates to j!=i, but j never gets reset properly when j reaches n, causing infinite loop or incorrect behavior. Also, the inner loop should start from j=0 each time, but the reset j=0 inside the loop combined with j++ in the for statement causes j to become 1 after reset, skipping index 0.]
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; // @@ [Error: Setting j=0 here, but the for loop's j++ will increment it to 1, so index 0 is always skipped after the first match.]
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i; // @@ [Error: Should compare num[max] with num[i], but max is initialized as num[0] (an integer value), not an index. This causes incorrect comparison and potential array out-of-bounds access.]
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}