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
    while(scanf("%d%d%d%d",&a[n++].x1,&a[n++].x2,&a[n++].y1,&a[n++].y2)!=EOF); // @@ [Multiple increments of n in scanf arguments cause incorrect indexing and ignore the first input integer (number of segments). Also reads coordinates into wrong members (x1, x2, y1, y2 vs expected x1, y1, x2, y2). This leads to data corruption.]
    struct line *b[100];
    for(int i=0;i<n;i++)
    {
        b[i]=&a[i];
        for(int j=0;j<n;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1) // @@ [Due to corrupted data, many entries are zero, causing false matches and creation of cycles in the linked list. Infinite loops may occur in f().]
            {
                a[i].next=&a[j];
                break;
            }
        }
    }
    struct line max1=a[0]; // @@ [Copying a[0] by value; the next pointer still refers to original array. The starting point of the longest chain is not correctly captured.]
    int max=f(a[0]);
    for(int i=0;i<n;i++)
    {
        if(max<f(a[i])) // @@ [f(a[i]) returns the length from segment i, but i may not be the head of the chain. This fails to find the full length of the longest continuous line because the chain could start earlier.]
        {
            max=f(a[i]);
            max1=a[i];
        }
    }
    printf("%d %d %d",max,max1.x1,max1.y1); // @@ [max1.x1 and max1.y1 may not be the starting point of the longest chain; output coordinates are incorrect.]
    return 0;
}
int f(struct line a)
{
    struct line *b=&a;
    int n=0;
    while(b->next!=NULL) // @@ [If next pointers form a cycle (due to false matches above), this loop runs forever, causing Time Limit Exceeded.]
    {
        b=b->next;
        n++;
    }
    return n+1;
}