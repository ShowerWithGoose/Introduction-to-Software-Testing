#include<stdio.h>
void lswap(int[],int,int);
void rswap(int[],int,int);
void perm(int[],int,int);
int a[]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    int N;
    scanf("%d",&N);
    perm(a,0,N-1);
    return 0;
}
void lswap(int a[],int j,int i)
{
    int sw,k;
    sw=a[i];
    for(k=i;k>j;k--)
    a[k]=a[k-1];
    a[j]=sw;
}
void rswap(int a[],int j,int i)
{
    int sw,k;
    sw=a[j];
    for(k=j;k<i;k++)
    a[k]=a[k+1];
    a[i]=sw;
}
void perm(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        for(i=0;i<=q;i++)
        {
            printf("%d ",a[i]);
        }
    printf("\n");
    }
    else 
    {
        for(i=p;i<=q;i++)
        {
            lswap(a,p,i);
            perm(a,p+1,q);
            rswap(a,p,i);
        }
    }
}
