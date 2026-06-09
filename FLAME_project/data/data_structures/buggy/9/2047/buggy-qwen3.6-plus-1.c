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
            if((infor[i].x1<infor[j].x1)||(infor[i].x1==infor[j].x1 && infor[i].y1 < infor[j].y1)) // @@ The sorting condition is incorrect. It sorts in descending order or inconsistent order because it swaps when the current element is "smaller" than the candidate, effectively pushing smaller elements to later indices or mixing them up. To sort by starting point (x1, then y1) in ascending order, we should swap if infor[i] > infor[j]. Here, if infor[i].x1 < infor[j].x1, it swaps, putting the larger x1 at index i. This results in a descending sort by x1.
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
        for(int j=0;j<n,j!=i;j++) // @@ Syntax error in for loop condition. The comma operator evaluates both expressions but returns the value of the last one. So 'j<n,j!=i' is equivalent to 'j!=i'. The loop will continue as long as j!=i, ignoring the bound j<n, which leads to out-of-bounds access and infinite loops or undefined behavior. It should be 'j<n && j!=i'.
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
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i;
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}