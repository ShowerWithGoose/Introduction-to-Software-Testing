#include<stdio.h>
int a[10],book[10];
int put[10];
int main()
{
    int n;
    scanf("%d",&n);
    int i=0,j=0,k=0;
    for (int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[1]=i;
            if(n==1)
    {
        for(int i=1;i<n-1;i++)
        printf("%d ",a[i] );
        printf("%d\n",a[n]);
    }


    for (int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[2]=i;
            if(n==2)
    {
        for(int i=1;i<n;i++)
        printf("%d ",a[i] );
        printf("%d\n",a[n]);
    }


    for (int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[3]=i;
            if(n==3)
    {
        for(int i=1;i<n;i++)
        printf("%d ",a[i] );
        printf("%d\n",a[n]);
    }


    for (int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[4]=i;
            if(n==4)
    {
        for(int i=1;i<n;i++)
        printf("%d ",a[i] );
        printf("%d\n",a[n]);
    }


    for (int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[5]=i;
            if(n==5)
    {
        for(int i=1;i<n;i++)
        printf("%d ",a[i] );
        printf("%d\n",a[n]);
    }


    for (int i=1;i<=n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[6]=i;
            book[i]=0;
        }
    }
            book[i]=0;
        }
    }
            book[i]=0;
        }
    }
            book[i]=0;
        }
    }
            book[i]=0;
        }
    }
            book[i]=0;
        }
    }
    return 0;
}

