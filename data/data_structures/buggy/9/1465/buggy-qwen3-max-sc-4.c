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
        scanf("%d%d%d%d",&A[i].x1,&A[i].y1,&A[i].x2,A[i].y2); // @@ [Missing '&' before A[i].y2 causes undefined behavior as scanf expects a pointer]
    }
    qsort(A,n,sizeof(A[0]),cmp);
    int m=1;
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
            m=1;
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
    return 0; // @@ [Incorrect comparison function: should return negative, zero, or positive; returning only 0 or 1 breaks qsort ordering]
}