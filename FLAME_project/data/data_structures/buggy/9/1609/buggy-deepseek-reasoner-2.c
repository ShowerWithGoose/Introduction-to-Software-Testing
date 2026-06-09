#include <stdio.h>
#include <stdlib.h>

typedef struct _line{
    int count;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
}line,*lline;

int cmp1(const void *a,const void *b)
{
    lline a1 = (lline)a;
    lline b1 = (lline)b;
    return (a1->start_x - b1->start_x);
}
int cmp2(const void *a,const void *b)
{
    lline a1 = (lline)a;
    lline b1 = (lline)b;
    return (a1->count - b1->count);
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);

    line a[25]; // @@ Array size 25 is too small for n=30, causing stack smashing and out-of-bounds access.

    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i].start_x,&a[i].start_y,&a[i].end_x,&a[i].end_y);
        a[i].count = 1;
    }

    qsort(a,n,sizeof(line),cmp1);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((a[i].end_x==a[j].start_x)&&(a[i].end_y==a[j].start_y))
            {
                a[i].end_x=a[j].end_x; // @@ Updating a[i]'s end coordinates, but the inner loop continues with j, potentially missing other segments that could connect to the new end because j only goes forward.
                a[i].end_y=a[j].end_y; // @@ Same issue as above.
                a[i].count++;

                for(k=j;k<n-1;k++) // @@ Shifting array elements corrupts the ordered list and index positions, making future merges unpredictable.
                {
                    a[k]=a[k+1];
                }
                n--;
                i--; // @@ Combined with shifting, this may cause the outer loop to skip elements or enter an infinite loop.
                break;
            }
        }
    }
    qsort(a,n,sizeof(line),cmp2); // @@ Sorting by count after merging may not correctly place the longest chain's start point; the start coordinates should come from the first segment of the chain, not necessarily the last element of the sorted array.
    
    printf("%d %d %d\n",a[n-1].count,a[n-1].start_x,a[n-1].start_y); // @@ If the merging logic is incorrect, the printed start coordinates may not correspond to the actual start of the longest chain.

    return 0;
}