#include <stdio.h>
#include <math.h> // @@ Unused header, may trigger compilation warnings/errors in strict environments.
#include <string.h> // @@ Unused header, may trigger compilation warnings/errors in strict environments.
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
                    break; // @@ Prematurely exits the inner loop, potentially skipping the check for a predecessor connection in the same iteration. This can lead to incomplete chain formation depending on input order.
                }
                if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
                {
                    a[i].s=1;
                    a[j].next=&a[i];
                    break; // @@ Same as above; breaks early and may miss establishing the correct successor link if the predecessor link is found first.
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
                e1=e1->next;
                len++;
            }
            a[i].lon=len;
        }
        max=max>len?max:len; // @@ Updates max even when a[i].s != 0 (where len is artificially 1), which is logically redundant and could mask issues if max should strictly track valid chain starts.
    }
    printf("%d ",max); // @@ Trailing space may cause output format mismatch; standard practice is to separate values with single spaces without trailing whitespace.
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