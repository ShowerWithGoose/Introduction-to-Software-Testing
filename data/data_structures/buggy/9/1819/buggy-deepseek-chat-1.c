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
                if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
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
                e1=e1->next;
                len++;
            }
            a[i].lon=len;
        }
        max=max>len?max:len; // @@ The variable `len` may be uninitialized when `a[i].s != 0`, leading to undefined behavior. It should be initialized to 1 before the if block, but the current code only sets `len=1` at the start of the loop, which is correct. However, the logic for updating `max` uses `len` which is only updated inside the `if` block; if `a[i].s != 0`, `len` remains 1 from the initialization, which is fine. The actual error is that the program does not correctly handle the case where segments are connected in reverse order (e.g., a[i].x1 == a[j].x2 and a[i].y1 == a[j].y2), because it sets `a[i].s=1` and `a[j].next=&a[i]`, but then later when checking `a[i].s==0`, it will skip `a[i]` even though `a[i]` might be the start of a chain. This causes incorrect chain detection and potentially wrong `max` value. Additionally, the program does not ensure that the x-coordinates are strictly increasing along the chain, as required by the problem.
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