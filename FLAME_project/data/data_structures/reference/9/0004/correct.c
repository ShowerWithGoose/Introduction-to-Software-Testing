# include<stdio.h>
# include <stdlib.h>
// # include <windows.h>
typedef struct line
    {
        int x1,x2,y1,y2;
        int flag;
    }Line;
int cmp(const void *a,const void *b)
{
    Line *aa = (Line *)a;
    Line *bb = (Line *)b;
    return (((aa->x1) > (bb->x1)) ? 1 : -1);
}
int main()
{
    Line l[105];
    int x,y;
    int n=0;
    int longestlen=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
        l[i].flag=0;
    }
    qsort(l, n, sizeof(l[0]), cmp);

    for (int i = 0;i < n-1; i++)
    {
        if(l[i].flag)
            continue;
        int tail_x=l[i].x2;
        int tail_y=l[i].y2;
        int k=1;
        for(int j=i+1;j<n;j++)
        {
            if(l[j].flag)
                continue;
  
            if((tail_x==l[j].x1)&&(tail_y==l[j].y1))
            {
                k++;
                tail_x=l[j].x2;
                tail_y=l[j].y2;
                l[j].flag=1;
            }
        }
        if(longestlen<k)
        {
            longestlen=k;
            x=l[i].x1;
            y=l[i].y1;
        }
    l[i].flag=1;
    }
    printf("%d %d %d",longestlen,x,y);
    // system("pause");
    return 0;
}
