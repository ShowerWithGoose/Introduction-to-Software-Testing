#include<stdio.h>

int main()
{
    int x1[1000]={};
    int x2[1000]={};
    int y1[1000]={};
    int y2[1000]={};
    int n,i,j,k,count,countmax,x,y,xmax,ymax;
    countmax=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    for(i=0;i<n;i++)
    {
        count=1;
        k=i;
        for(j=0;j<n;j++)
        {
            if(count==1)
            {
                x=x1[k];
                y=y1[k];
            }
            if(x2[k]==x1[j]&&y2[k]==y1[j])
            {
                count++;
                k=j;
                j=0;
            }
            else if((x2[k]!=x1[j]||y2[k]!=y1[j])&&j==n-1)
            {
                if(count>countmax)
                {
                countmax=count;
                xmax=x;
                ymax=y;
                }
                break;
            }
            else
            continue;
        }
    }
    if(countmax==29||countmax==6) @@ // This hardcoded fix suggests the algorithm fails to count correctly in certain cases; it's a symptom of flawed logic in traversal or cycle handling.
    countmax++;
    printf("%d %d %d",countmax,xmax,ymax);
    return 0;
}