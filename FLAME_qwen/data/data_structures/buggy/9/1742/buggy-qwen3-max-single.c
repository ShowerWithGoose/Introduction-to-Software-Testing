#include<stdio.h>
int main()
{
    int z;
    int arr[105][5]={0},a[105]={0};
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        for(int j=1;j<5;j++)
        scanf("%d",&arr[i][j]); // @@ [The loop reads into arr[i][1] to arr[i][4], but the problem states each segment has two endpoints (x1,y1,x2,y2), so 4 values. However, indexing from 1 skips arr[i][0], which is fine, but later logic assumes arr[i][1]=x1, arr[i][2]=y1, arr[i][3]=x2, arr[i][4]=y2. This is consistent, so not an error by itself.]
    }
    for(int i=0;i<z;i++)
    {
        int m,n,p=1;
        m=arr[i][3],n=arr[i][4]; // @@ [This sets (m,n) to the ENDPOINT (x2,y2) of segment i, which is correct for trying to extend forward.]
        for(int d=0;d<z;d++)
        {
            for(int j=0;j<z;j++)
            {
                    if(m==arr[j][1]&&n==arr[j][2]) // @@ [This checks if endpoint (m,n) matches STARTPOINT (x1,y1) of segment j, which is correct.]
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
    printf("%d %d %d",c,arr[c][1],arr[c][2]); // @@ [Error: Should print f (the max count), not c (the index). Also, the starting point of the longest chain is arr[c][1], arr[c][2], which is correct, but the first number printed is wrong. Expected: "max_count x_start y_start", but this prints "index x_start y_start".]
    return 0;
}