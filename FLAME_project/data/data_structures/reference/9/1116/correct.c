#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct Line
{
    int startx,starty,endx,endy;
}l[101];
int cmp(const void*e,const void*f)
{
    struct Line ee = *(struct Line *)e;
    struct Line ff = *(struct Line *)f;
    if((ee.startx-ff.startx)<0) return -1;
    else if((ee.startx-ff.startx)==0)
    {
        if((ee.starty-ff.starty)<0)
        return -1;
        else
        return 1;
    }
    else return 1;
}
int main()
{
    int n,maxx,maxy,end0x,end0y,number=0,max=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&l[i].startx,&l[i].starty,&l[i].endx,&l[i].endy);
    }
    qsort(l+1,n,sizeof(l[1]),cmp);
    for(int i=1;i<=n;i++)
    {
        number=1;
        end0x=l[i].endx;
        end0y=l[i].endy;
        for(int j=i+1;j<=n;j++)
        {
            if(l[j].startx==end0x&&l[j].starty==end0y)
            {
                number++;
                end0x=l[j].endx;
                end0y=l[j].endy;
            }
        }
        if(max<number)
        {
            max=number;
            maxx=l[i].startx;
            maxy=l[i].starty;
        }
    }
    printf("%d %d %d",max,maxx,maxy);
    return 0;
}
