#include<stdio.h>
#include<math.h>
#include<string.h>
int jie[15],N,a[15];

int jiejie()
{
    jie[0]=1;
    int ji;
    for(ji=1;ji<10;ji++)
        jie[ji]=ji*jie[ji-1];
}

void xy()
{
    int i;
    for( i=N-2;i>=0;i--)
    {
        if(a[i]<a[i+1]) break;
    }
    int k=i+1;
    for(int j=i+1;j<N;j++)
    {
        if(a[j]>a[i] && a[j]<a[i+1])
            k=j;
    }
    int d=a[k];a[k]=a[i];a[i]=d;
    int jkl=N-1;
    for(int j=i+1;jkl>j;jkl--,j++)
    {
        int d=a[j];a[j]=a[jkl];a[jkl]=d;
    }
}

int main()
{
    scanf("%d",&N);
    jiejie();
    for(int i=0;i<N;i++)
    {
        a[i]=i+1;
    }
    for(int t=1;t<=N;t++)
        printf("%d ",t);
    printf("\n");
    for(int t=0;t<jie[N]-1;t++)
    {
        xy();
        for(int z=0;z<N;z++)
            printf("%d ",a[z]);
        if(N!=1)printf("\n");
    }
}

