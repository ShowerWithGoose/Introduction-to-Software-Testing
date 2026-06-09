#include <stdio.h>
#include <string.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
int main()
{
    struct line inf[150];
    int n,i,j,cmax=1,x1max=0,y1max=0,x2,y2,count=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d %d %d %d",&inf[i].x1,&inf[i].y1,&inf[i].x2,&inf[i].y2);
    struct line tmp;
    for(i=0;i<n;i++)
    for(j=i;j<n;j++)
	{
        if(inf[i].x1>inf[j].x1)
        {
            tmp=inf[i];
            inf[i]=inf[j];
            inf[j]=tmp;
        }
    }
    for(i=0;i<n;i++)
    {
        count=1;
        x2=inf[i].x2;
        y2=inf[i].y2;
        for(j=i+1;j<n;j++)
        {
            if(x2==inf[j].x1&&y2==inf[j].y1)
            {
                count++;
                x2=inf[j].x2;
                y2=inf[j].y2;
            }
        }
        if(count>cmax)
        {
            cmax=count;
            x1max=inf[i].x1;
            y1max=inf[i].y1;
        }
    }   
    printf("%d %d %d\n",cmax,x1max,y1max);
    return 0;
}


