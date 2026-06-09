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
            if((infor[i].x1<infor[j].x1)||(infor[i].x1==infor[j].x1 && infor[i].y1 < infor[j].y1)) // @@ Logical error: Sorting condition is reversed (descending order). Should sort in ascending order of x1 to correctly chain segments.
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
        for(int j=0;j<n,j!=i;j++) // @@ Syntax/Logical error: Comma operator used instead of logical AND (&&) in loop condition. This evaluates to j!=i, ignoring j<n, and may cause compilation warnings or incorrect loop behavior.
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0;
            }
        }
    }
    int max=num[0]; // @@ Logical error: max is initialized to the value num[0] instead of the index 0. Should be int max=0;
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i; // @@ Logical error: max is used as an array index but holds a value from num[0], leading to incorrect comparisons and potential out-of-bounds access.
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}