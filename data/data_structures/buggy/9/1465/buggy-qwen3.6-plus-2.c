#include<stdio.h>
#include<string.h>
int i,j,k;
int cmp(const void*p1,const void*p2);
typedef struct _xianduan{
    int x1;
    int y1;
    int x2;
    int y2;
}xian,*pxian;
xian A[101];

int main()
{
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&A[i].x1,&A[i].y1,&A[i].x2,A[i].y2); // @@ Missing '&' operator for A[i].y2 in scanf, causing undefined behavior and potential compilation/runtime errors.
    }
    qsort(A,n,sizeof(A[0]),cmp);
    int m=1; // @@ Variable m should be initialized to 1 at the start of each outer loop iteration to correctly count the chain length for the current segment.
    int t=1;
    int X,Y;
    for(i=0;i<n;i++)
    {
        int x=A[i].x2;
        int y=A[i].y2;
        for(j=i+1;j<n;j++)
        {
            if(A[j].x1==x&&A[j].y1==y)
            {
                x=A[j].x2;
                y=A[j].y2;
                m++;
            }
        }
        if(m>t)
        {
            t=m;
            m=1; // @@ Resetting m here only occurs when a new maximum is found; it must be reset to 1 at the beginning of every i iteration.
            X=A[i].x1;
            Y=A[i].y1;
        }
    }
    printf("%d %d %d",t,X,Y);
    return 0;
}

int cmp(const void*p1,const void*p2)
{
    pxian a=(pxian)p1;
    pxian b=(pxian)p2;
    if((a->x1)>(b->x1)) return 1;
    return 0; // @@ qsort comparison function must return negative, zero, or positive values; returning 0 for a->x1 <= b->x1 violates the comparison contract and causes incorrect sorting.
}