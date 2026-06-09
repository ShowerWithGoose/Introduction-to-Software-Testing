#include<stdio.h>
#include<string.h>
#include<ctype.h>
int N;
int i,j,k,m;
int a[10];
int print()
{
    for(i=0;i<N-1;i++)
        printf("%d ",a[i]);
        printf("%d\n",a[i]);
}
int find()
{
    for(i=N-2;i>=0;i--)
        if(a[i+1]>a[i])
    {
       break;
    }
    k=i;
    j=i+1;
    for(i=k+1;i<N;i++)
    {
        if(a[i]>a[k]&&a[i]<a[k+1])
            j=i;
    }
    m=a[k];
    a[k]=a[j];
    a[j]=m;
    for(j=k+1,i=N-1;i>j;i--,j++)
    {
        m=a[i];
        a[i]=a[j];
        a[j]=m;
    }
}
int nc()
{
    for(i=1,j=1;i<=N;i++)
    {
        j=j*i;
    }
    return j;
}
int main()
{   int n;
    scanf("%d",&N);
       for(i=0;i<N;i++)
       {
           a[i]=i+1;
       }
            print();
            for(n=1;n<nc();n++)
            {
                find();
                print();
            }

    return 0;
}

