#include <stdio.h>
#include <string.h>
int main()
{
    int nline;
    int sx,sy,m,ex,ey;
    int stx,sty,max=0;
    int x1[100]={0},y1[100]={0},x2[100]={0},y2[100]={0};
    int line[100]={0};
    scanf("%d",&nline);
    for(int i=0;i<nline;i++)
    {
        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    for(int i=0;i<nline;i++)
    {
        if(line[i]==0)
        {   m=1;
            line[i]=1;
            sx=x1[i];
            sy=y1[i];
            ex=x2[i];
            ey=y2[i];
        for(int j=0;j<nline;j++)
        {
            if(line[j]==0)
            {
                if(sx==x2[j]&&sy==y2[j])
                {
                    sx=x1[j];
                    sy=y1[j];
                    line[j]++;
                    m++;
                    j=0;
                }
                if(ex==x1[j]&&ey==y1[j])
                {
                    ex=x2[j];
                    ey=y2[j];
                    line[j]++;
                    m++;
                    j=0; 
                }
            }
        }
        }
        if(m>max)
        {
            max=m;
            stx=sx;
            sty=sy;
        }
    }
    printf("%d %d %d\n",max,stx,sty);
    return 0;
}

