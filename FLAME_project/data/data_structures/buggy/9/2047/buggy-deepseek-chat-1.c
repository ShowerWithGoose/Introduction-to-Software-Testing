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
        for(int j=0;j<n,j!=i;j++) // @@ The condition `j<n,j!=i` uses the comma operator, which evaluates to `j!=i`, causing an infinite loop when `j` equals `i` because the loop never increments `j` properly. It should be `j < n && j != i`.
        {
            if(x2==infor[j].x1 && y2==infor[j].y1) 
            {
                x2=infor[j].x2;
                y2=infor[j].y2;
                num[i]++;
                j=0; // @@ Resetting `j` to 0 after incrementing `num[i]` causes the inner loop to restart from the beginning each time a match is found, potentially leading to incorrect counting and infinite loops. The loop should continue scanning forward without resetting.
            }
        }
    }
    int max=num[0];
    for(int i=0;i<n;i++) if(num[max]<num[i]) max=i; // @@ The variable `max` is used both as the index and the value. `num[max]` compares the value at index `max` with `num[i]`, but `max` is initialized to 0, so it works only if the first element is the maximum. However, the logic is confusing and should use a separate variable for the maximum value.
    printf("%d %d %d",num[max]+1,infor[max].x1,infor[max].y1);
    return 0;
}