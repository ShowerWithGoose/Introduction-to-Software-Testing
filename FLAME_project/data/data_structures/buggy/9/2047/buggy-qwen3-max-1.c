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
    } // @@ [Sorting logic is incorrect: it attempts to sort in descending order but uses a flawed comparison and loop bounds, leading to inconsistent ordering. Also, the inner loop should start from i+1 for proper selection sort.]
    int x2,y2;
    for(int i=0;i<n;i++)
    {   
        x2=infor[i].x2;
        y2=infor[i].y2;
        for(int j=0;j<n,j!=i;j++) // @@ [Syntax error: comma operator used instead of logical AND; condition 'j<n,j!=i' always evaluates to 'j!=i' after j<n, causing undefined behavior when j>=n. Should be 'j<n && j!=i'. Also, resetting j=0 inside loop causes infinite loop or missed segments.]
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; // @@ [Resetting j to 0 inside the loop breaks the iteration logic and may cause infinite loops or incorrect traversal; it prevents checking all possible next segments in a chain properly.]
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i; // @@ [Incorrect comparison: compares num[max] (value) with num[i], but max is an index; should compare num[i] > num[max] to find the index with maximum count.]
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}