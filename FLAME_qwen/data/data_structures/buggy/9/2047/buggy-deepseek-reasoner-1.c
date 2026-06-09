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
            if((infor[i].x1<infor[j].x1)||(infor[i].x1==infor[j].x1 && infor[i].y1 < infor[j].y1)) // @@ Sorting condition reversed; should be `>` for ascending order.
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
        for(int j=0;j<n,j!=i;j++) // @@ Comma operator in loop condition; should use `&&` instead of `,`. Also missing bound check for j<n.
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; // @@ Resetting j to 0 can cause infinite loop or out-of-bounds access; should use a proper method to continue the chain.
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i;
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}