#include<stdio.h>
struct line
{
    int x1;
    int x2;
    int y1;
    int y2;
    struct line *next;
};
int f(struct line);
int main()
{
    struct line a[100]={{0,0,0,0,NULL}};
    int n=0;
    while(scanf("%d%d%d%d",&a[n++].x1,&a[n++].x2,&a[n++].y1,&a[n++].y2)!=EOF);@@ // Error: Incorrect reading algorithm; should first read n, then read each segment's four coordinates into a single element. The multiple post-increments cause mismatched indices and data corruption, leading to undefined behavior and potentially infinite loops.
    struct line *b[100];
    for(int i=0;i<n;i++)@@ // Error: n is not the correct number of segments due to misread; this iterates over invalid data.
    {
        b[i]=&a[i];
        for(int j=0;j<n;j++)@@ // Error: Same issue with n; the linking logic operates on corrupted data.
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].next=&a[j];
                break;
            }
        }
    }
    struct line max1=a[0];
    int max=f(a[0]);
    for(int i=0;i<n;i++)@@ // Error: n is incorrect; also, the maximum chain start should be determined by checking which segment has no predecessor, not by taking the first occurrence.
    {
        if(max<f(a[i]))
        {
            max=f(a[i]);
            max1=a[i];
        }
    }
    printf("%d %d %d",max,max1.x1,max1.y1);
    return 0;
}
int f(struct line a)
{
    struct line *b=&a;
    int n=0;
    while(b->next!=NULL)@@ // Error: Due to corrupted data from improper reading, the linked list may contain cycles, causing this loop to never terminate (infinite loop).
    {
        b=b->next;
        n++;
    }
    return n+1;
}