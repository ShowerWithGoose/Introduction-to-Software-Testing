#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define clear(a) memset(a,0,sizeof(a));
struct line
{
    int x1,y1,x2,y2;
};
int cmp(const void *a,const void *b);
int main()
{
    struct line lin[100];
    int num,start[100]={0},max_location,max_number,check_x,check_y;
    int i1,i2,i3;
    scanf("%d",&num);
    for(i1=0;i1<num;i1++)
    {
        scanf("%d%d%d%d",&lin[i1].x1,&lin[i1].y1,&lin[i1].x2,&lin[i1].y2);
    }
    qsort(lin,num,sizeof(lin[0]),cmp);
    max_number=0;
    for(i2=0;i2<num;i2++)
    {
        start[i2]++;
        check_x=lin[i2].x2;
        check_y=lin[i2].y2;
        for(i3=i2+1;i3<num;i3++)
        {
            if(check_x==lin[i3].x1 && check_y==lin[i3].y1)
            {
                start[i2]++;
                check_x=lin[i3].x2;
                check_y=lin[i3].y2;
            }
        }
        if(start[i2]>max_number)
        {
            max_number=start[i2];
            max_location=i2;
        }
    }
    printf("%d %d %d",max_number,lin[max_location].x1,lin[max_location].y1);
    return 0;
}
int cmp(const void *a,const void *b)
{
    return (*(struct line *)a).x1>(*(struct line *)b).x1?1:-1;
}
