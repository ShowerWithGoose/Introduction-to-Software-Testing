#include<stdio.h>
#include<string.h>
#include<math.h>

void perm(int[],int,int);
void exchange(int[],int,int);
void huanyuan(int[],int,int);
void exchange(int a[],int m,int j)
{
    int temp = a[j],i;
    for(i = j - 1; i >= m; i--,j--)
    {
        a[j] = a[i];
    }
    a[m] = temp;
}
void huanyuan(int a[],int j,int m)
{
    int temp = a[m],i;
    for(i = m + 1; i <= j; i++,m++)
    {
        a[m] = a[i];
    }
    a[j] = temp;
}
void perm(int a[],int m,int n)
{
    int i, j;
    if(m == n)
    {
        for(i = 1; i <= n; i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    for(j = m; j <= n; j++)
    {
        exchange(a, m, j);
        perm(a, m + 1, n);
        huanyuan(a, j, m);
    }
}
int main()
{
    int a[20],n,i;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    perm(a,1,n);
}

