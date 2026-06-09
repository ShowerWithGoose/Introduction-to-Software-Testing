#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 10000
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

int num, x, y, z, i, j, k, point[200][4], sym[4], n, max;
int main()
{
    scanf("%d", &n);
    for(i=0;i<n;i++)
        scanf(" %d %d %d %d", &point[i][0], &point[i][1], &point[i][2], &point[i][3]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(point[i][0] > point[j][0])
            {
                for(k=0;k<4;k++)
                    sym[k] = point[i][k];
                for(k=0;k<4;k++)
                    point[i][k] = point[j][k];
                for(k=0;k<4;k++)
                    point[j][k] = sym[k];
            }
        }
    }

    for(i=0;i<n;i++)
    {
        z=i;
        num=0;
        for(j=i+1;j<n;j++)
        {
            if (point[z][2] == point[j][0])
            {
                if (point[z][3] == point[j][1])
                {
                    num++;
                    z=j;
                }
            }
        }
        if (num > max)
        {
            max=num;
            x=point[i][0];
            y=point[i][1];
        }
    }
    printf("%d %d %d", max + 1, x, y);
    return 0;
}

