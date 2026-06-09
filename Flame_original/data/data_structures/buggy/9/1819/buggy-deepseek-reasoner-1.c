#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct location{
    int s;
    int x1;
    int y1;
    int x2;
    int y2;
    int lon;
    struct location* next;
}loc;
int main()
{
    loc a[300];
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        a[i].s=0,a[i].lon=1;
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        a[i].next=NULL;
    }
    int k=0;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(j!=i)
            {
                if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
                {
                    a[j].s=1;
                    a[i].next=&a[j];
                    break;
                }
                if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2) // @@ This connection would create equal x coordinates (x1_i == x2_j), violating the strict increasing x order required for a continuous line segment.
                {
                    a[i].s=1;
                    a[j].next=&a[i];
                    break;
                }
            }
        }
    }
    int max=1;
    for(int i=0;i<num;i++)
    {
        int len=1;
        if(a[i].s==0)
        {
            loc* e1=a[i].next;
            while(e1!=NULL)
            {
                e1=e1->next; // @@ Moving e1 before counting len results in skipping the first connected segment.
                len++; // @@ This should be placed before moving e1: len++; e1 = e1->next;
            }
            a[i].lon=len;
        }
        max=max>len?max:len; // @@ This line updates max even for segments that are not starting points (s!=0), which may incorrectly count a single segment as a chain.
    }
    printf("%d ",max);
    for(int i=0;i<num;i++)
    {
        if(a[i].s==0&&a[i].lon==max)
        {
            printf("%d %d\n",a[i].x1,a[i].y1);
            break;
        }
    }
     return 0;
}