#include<stdio.h>
int main()
{
    int z;
    int arr[105][5]={0},a[105]={0};
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        for(int j=1;j<5;j++)
        scanf("%d",&arr[i][j]); // @@ [Reading starts from index 1, so arr[i][0] remains uninitialized and unused; this causes the first endpoint (x1,y1) to be stored in arr[i][1], arr[i][2], and second endpoint (x2,y2) in arr[i][3], arr[i][4]. However, later logic assumes correct storage but misses that input order must respect x1 < x2 — though problem guarantees it. The real error is in output: printing 'c' (index) instead of segment count 'f'.]
    }
    for(int i=0;i<z;i++)
    {
        int m,n,p=1;
        m=arr[i][3],n=arr[i][4];
        for(int d=0;d<z;d++)
        {
            for(int j=0;j<z;j++)
            {
                    if(m==arr[j][1]&&n==arr[j][2])
                    {
                        p++;
                        m=arr[j][3],n=arr[j][4];
                        break;
                    }
            }
        }
        a[i]=p;
    }
    for(int i=0;i<z;i++)
    printf("%d ",a[i]);
    printf("\n");
    int f=a[0],c=0;
    for(int i=0;i<z;i++)
    {
        if(a[i]>f)
        {
            f=a[i];
            c=i;
        }
    }
    printf("%d %d %d",c,arr[c][1],arr[c][2]); // @@ [Should print 'f' (the maximum number of segments), not 'c' (the index). This causes wrong output format and incorrect value.]
    return 0;
}