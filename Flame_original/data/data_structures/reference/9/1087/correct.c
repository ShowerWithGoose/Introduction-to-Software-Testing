#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void sort(int a[100][4],int n)
{
    int i,j;
    int k;
    int tmp[4];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j][0]<a[i][0])
            {
                for(k=0;k<4;k++)
                tmp[k]=a[j][k];
                for(k=0;k<4;k++)
                a[j][k]=a[i][k];
                for(k=0;k<4;k++)
                a[i][k]=tmp[k];
            }
        }

    }
}
int main()//第一步是排序这样的话往后找点就会找到最长的如果不排序直接往后找就有可能会让前面某段丢掉
{
    int n;
    int i,j;
    int a[100][4];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    sort(a,n);
    int cnt=0;
    int max,x,y;
    for(i=0;i<n;i++)
    {
        int z=i;
        cnt=1;
        for(j=i+1;j<n;j++)
        {
            if(a[j][0]==a[z][2]&&a[j][1]==a[z][3])
            {
                cnt++;
                z=j;
            }
        }
        if(cnt>=max)
        {
            max=cnt;
            x=a[i][0];y=a[i][1];

        }

    }
    printf("%d %d %d",max,x,y);

    
    return 0;
}


