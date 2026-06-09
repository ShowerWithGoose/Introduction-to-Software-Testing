#include <stdio.h>
#include <string.h>
int a[101][4], temp[4], n, max, num, g, h, z;
int i,j,k,l=1;
void replace( int a[101][4],int  n, int temp[4])
{
    for ( i = 0; i < n; i++)
    {
        for ( j = i + 1; j < n; j++)
        {
            if (a[i][0] > a[j][0])
            {
                for ( k = 0; k < 4; k++)
                {
                    temp[k] = a[i][k];
                }
                for ( k = 0; k < 4; k++)
                {
                    a[i][k] = a[j][k];
                }
                for ( k = 0; k < 4; k++)
                {
                    a[j][k] = temp[k];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++);
}
int a[101][4], temp[4], n, max, num, g, h, z;
	int i,j,k; 
int main()
{

    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf(" %d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }

    replace(a, n, temp);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++);
    for ( i = 0; i < n; i++)
    {
        z = i;
        num = 0;
        for ( j = i + 1; j < n; j++)
        {
            if (a[z][2] == a[j][0])
            {
                if (a[z][3] == a[j][1])
                {
                    num++;
                    z = j;
					for(l=0;l<n;l++);
                }
            }
        }
        if (num > max)
        {
            max = num;
            g = a[i][0];
            h = a[i][1];
        }
    }
    for(i=0;i<n;i++)
    for(j=0;j<n;j++);
    printf("%d %d %d", max + 1, g, h);
    return 0;
}







