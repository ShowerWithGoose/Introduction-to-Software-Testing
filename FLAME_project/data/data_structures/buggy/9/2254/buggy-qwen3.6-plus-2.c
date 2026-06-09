#include<stdio.h>
#include<string.h>
struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};
int main()
{
    struct line a[200];
    int n,countmax=1,x=0,y=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
        struct line tmp;
    for(int i=0;i<n;i++) // @@ The sorting logic is incorrect. It compares a[i].x1 with a[j].x2, which does not properly sort the segments by their starting x-coordinate (x1). This leads to an incorrect order for chaining segments. A proper sort by x1 is required.
    {
        for(int j=i;j<n;j++)
        {
            if(a[i].x1>a[j].x2) // @@ The comparison condition a[i].x1 > a[j].x2 is semantically wrong for sorting segments by their start point. It should be a[i].x1 > a[j].x1 to sort in ascending order of starting x-coordinates.
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int count=1,p,q;
        p=a[i].x2;
        q=a[i].y2;
        for(int j=i+1;j<n;j++)
        {
        if(a[j].x1==p&&a[j].y1==q)
        {
            p=a[j].x2;
            q=a[j].y2;
            count++;
        }
    }
        if(count>countmax)
        {
            countmax=count;
            x=a[i].x1;
            y=a[i].y1;
        }
    }
    printf("%d %d %d",countmax,x,y);
    return 0;
}