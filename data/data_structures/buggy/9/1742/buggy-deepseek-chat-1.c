#include<stdio.h>
int main()
{
    int z;
    int arr[105][5]={0},a[105]={0};
    scanf("%d",&z);
    for(int i=0;i<z;i++)
    {
        for(int j=1;j<5;j++)
        scanf("%d",&arr[i][j]);
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
    printf("%d %d %d",c,arr[c][1],arr[c][2]); // @@ The output should be the maximum number of segments (a[c]), not the index c. Also, the starting point should be from the first segment of the chain, not necessarily arr[c][1] and arr[c][2] which are the start of segment c itself.
    return 0;
}