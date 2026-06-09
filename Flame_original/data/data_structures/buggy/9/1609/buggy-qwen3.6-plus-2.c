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
    return (a1->start_x - b1->start_x); // @@ [Comparator only compares start_x. It should also compare start_y as a secondary key to ensure deterministic ordering, similar to the reference program.]
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

    line a[25]; // @@ [Array size 25 is likely too small for the input constraints and may cause buffer overflow. It should be increased (e.g., to 2000).]

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
                a[i].end_x=a[j].end_x;
                a[i].end_y=a[j].end_y;
                a[i].count++;

                for(k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];
                }
                n--;
                i--;
                break;
            }
        }
    }
    qsort(a,n,sizeof(line),cmp2);
    
    printf("%d %d %d\n",a[n-1].count,a[n-1].start_x,a[n-1].start_y);

    return 0;
}