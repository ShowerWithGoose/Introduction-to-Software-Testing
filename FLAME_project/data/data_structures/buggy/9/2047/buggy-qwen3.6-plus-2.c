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
        for(int j=0;j<n,j!=i;j++) // @@ The comma operator in the loop condition `j<n,j!=i` evaluates both expressions but only returns the result of the last one (`j!=i`). This means the loop continues as long as `j != i`, ignoring the `j < n` bound check, which can lead to out-of-bounds access or infinite loops if `i` is not encountered. It should be `j < n && j != i`. Furthermore, resetting `j=0` inside the loop combined with this logic is flawed for tracing a chain because it restarts the search from the beginning every time a connection is found, potentially counting segments incorrectly or missing the specific chain structure required. However, the primary syntax/logic error here is the loop condition.
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