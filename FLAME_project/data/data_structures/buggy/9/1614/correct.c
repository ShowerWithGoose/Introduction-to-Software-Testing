#include <stdio.h>
#include <stdlib.h>
typedef struct _line
{
    int xf,yf;
    int xb,yb;
}lines,*pline;
lines line[101];
int cmp(const void* p1,const void*p2)
{
    int ans;
    pline line1=(pline)p1;
    pline line2=(pline)p2;
    ans=line1->xf-line2->xf;
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&line[i].xf,&line[i].yf,&line[i].xb,&line[i].yb);
    }
    qsort(line,n,sizeof(line[0]),cmp);
    int j=0;
    int xt,yt,xz,yz,xz1,yz1;
    int m,num=1,num1=1;
    while(n>0)
    {
        i=0;
        m=0;
        xt=line[0].xb;
        yt=line[0].yb;
        xz=line[0].xf;
        yz=line[0].yf;
            for(j=1;j<n;j++)
            {
                if(xt==line[j].xf && yt==line[j].yf)
                {
                    num++;
                    xt=line[j].xb;
                    yt=line[j].yb;
                }
                else
                {
                    line[m].xb=line[j].xb;
                    line[m].yb=line[j].yb;
                    line[m].xf=line[j].xf;
                    line[m].yf=line[j].yf;
                    m++;
                }
            }
        if(num>num1)
        {
            xz1=xz;
            yz1=yz;
            num1=num;
        }
        n=m;
        num=1;
    }
    printf("%d %d %d",num1,xz1,yz1);
    return 0;
}

