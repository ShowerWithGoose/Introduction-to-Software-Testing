#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int i,j,k,a[100][4],n,tmp[4],same,max=0, num,x0,y0;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i][0]>a[j][0])
            {

                for (k=0;k<4;k++)
                {
                    tmp[k]=a[i][k];
                    a[i][k]=a[j][k];
                    a[j][k]=tmp[k];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        same=i;
        num=0;
        for(j=i+1;j<n;j++)
        {
            if(a[same][2]==a[j][0]&&a[same][3]==a[j][1])
            {
                num++;
                same=j;
            }
        }
        if(num>max)
        {
            max=num;
            x0=a[i][0];
            y0=a[i][1];
        }
    }
    printf("%d %d %d",max+1,x0,y0);
    return 0;
}



