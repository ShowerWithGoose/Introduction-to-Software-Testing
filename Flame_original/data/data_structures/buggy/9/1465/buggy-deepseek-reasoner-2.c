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
        scanf("%d%d%d%d",&A[i].x1,&A[i].y1,&A[i].x2,A[i].y2); // @@ Missing & before A[i].y2, causing undefined behavior.
    }
    qsort(A,n,sizeof(A[0]),cmp); // @@ Missing #include<stdlib.h> for qsort; implicit declaration is a compilation error.
    int m=1; // @@ m should be reset to 1 at the start of each outer loop iteration, not initialized globally.
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
            m=1; // @@ Resetting m only here is insufficient; m must be reset to 1 at the beginning of the loop for each new i.
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
    if((a->x1)>(b->x1)) return 1; // @@ Comparison function must return negative, zero, positive; this never returns -1 when a->x1 < b->x1.
    return 0; // @@ Should return -1 when a->x1 < b->x1 to ensure correct sorting order.
}