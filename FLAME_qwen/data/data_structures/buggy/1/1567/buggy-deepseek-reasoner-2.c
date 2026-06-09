#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1);@@ // @@ Implicit declaration of 'printfa' (used before definition)
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i);@@ // @@ Implicit declaration of 'change' (used before definition)
            pai(a,p+1,q);
            change(a,p,i);@@ // @@ Implicit declaration of 'change' (used before definition)
        }
    }
    
    
}

void change(int a[],int p,int i)
{
    int temp;
    temp=a[p];
    a[p]=a[i];
    a[i]=temp;
}

void printfa(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d",&N);
    
    int i,a[10];
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}