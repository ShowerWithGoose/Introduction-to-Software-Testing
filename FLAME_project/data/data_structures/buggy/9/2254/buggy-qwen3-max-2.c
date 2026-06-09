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
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i].x1>a[j].x2)
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    } // @@ [The sorting logic is incorrect. It compares a[i].x1 with a[j].x2 and swaps based on that, which does not sort the segments in any meaningful order for chaining. The correct approach is to sort by x1 (or x2) consistently to enable proper chaining from left to right.]
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