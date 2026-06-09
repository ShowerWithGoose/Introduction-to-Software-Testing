#include<stdio.h>
#include<string.h> // @@ [should include <stdlib.h> for qsort]
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
        scanf("%d%d%d%d",&A[i].x1,&A[i].y1,&A[i].x2,A[i].y2); // @@ [missing & before A[i].y2]
    }
    qsort(A,n,sizeof(A[0]),cmp);
    int m=1; // @@ [should be placed inside the outer loop to reset m for each starting segment]
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
            m=1; // @@ [resets m only when new max is found; should be unconditional at the start of the outer loop]
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
    return 0; // @@ [comparison function must also return negative when a->x1 < b->x1 and 0 when equal]
}