#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[200][10]={},b[4]={},i,j,k,n,x,l,max,a1,a2;
void paiXu(int a[200][10],int n,int b[4]);
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	paiXu(a,n,b);
	for(i=0;i<n;i++)
    {
        x=i,l=0;
        for(j=i+1;j<n;j++)
        {
            if(a[x][2]==a[j][0])
            {
                if(a[x][3]==a[j][1])
                {
                    l++;
                    x=j;
                }
            }
        }
        if(l>max)
        {
            max=l;
            a1=a[i][0];
            a2=a[i][1];
        }
    }
    printf("%d %d %d",max+1,a1,a2);
    return 0;
}
void paiXu(int a[200][10],int n, int b[4])
{
	for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i][0]>a[j][0])
            {
                for(k=0;k<4;k++)
                {
                    b[k] = a[i][k];
                }
                for(k=0;k<4;k++)
                {
                    a[i][k]=a[j][k];
                }
                for(k=0;k<4;k++)
                {
                    a[j][k]=b[k];
                }
            }
        }
    }
}

