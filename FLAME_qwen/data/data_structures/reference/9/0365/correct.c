#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void re(int a[101][4], int n, int temp[4]);
int a[101][4], kop[4], n, max, num, first_x, first_y, z;

int main()
{
    scanf("%d", &n);
    int i; 
    for (i=0;i<n;i++)
    {
        scanf(" %d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    }

    re(a,n,kop);
	int j;
    for (i=0;i<n;i++)
    {
        z=i;
        num=0;
        for (j=i+1;j<n;j++)
        {
            if (a[z][2] == a[j][0]&&a[z][3]==a[j][1])
            {
                    num++;
                    z = j;
            }
        }
        if (num>max)
        {
            max=num;
            first_x = a[i][0];
            first_y = a[i][1];
        }
    }

    printf("%d %d %d", max+1,first_x,first_y);
    return 0;
}

void re(int a[101][4],int n,int temp[4])
{	int i,j,k;	
	k=0;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (a[i][0]>a[j][0])
            {
                while(k<4){
                	temp[k]=a[i][k];
                	a[i][k]=a[j][k];
                	a[j][k]=temp[k];
                	k++;
				}
				k=0;
            }
        }
    }
}

