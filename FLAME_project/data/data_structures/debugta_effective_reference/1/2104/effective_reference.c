#include<stdio.h>
void lswap(int[],int,int);
void rswap(int[],int,int);
void perm(int[],int,int);
int P[]={1,2,3,4,5,6,7,8,9,10};
int main()
{
    int N;
    scanf("%d",&N);
    perm(P,0,N-1);
    return 0;
}
void lswap(int P[],int j,int i)
{
    int sw,k;
    sw=P[i];
    for(k=i;k>j;k--)
    P[k]=P[k-1];
    P[j]=sw;
}
void rswap(int P[],int j,int i)
{
    int sw,k;
    sw=P[j];
    for(k=j;k<i;k++)
    P[k]=P[k+1];
    P[i]=sw;
}
void perm(int P[],int n,int N)
{
    int i;
    if(n==N)
    {
        for(i=0;i<=N;i++)
        {
            printf("%d ",P[i]);
        }
    printf("\n");
    }
    else 
    {
        for(i=n;i<=N;i++)
        {
            lswap(P,n,i);
            perm(P,n+1,N);
            rswap(P,n,i);
        }
    }
}
