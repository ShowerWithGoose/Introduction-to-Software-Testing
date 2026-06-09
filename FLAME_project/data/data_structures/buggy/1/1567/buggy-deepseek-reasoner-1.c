#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1);
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i); // @@ [Error: Simple swap does not preserve lexicographic order for larger N; should use cyclic shift]
            pai(a,p+1,q);
            change(a,p,i); // @@ [Error: Same issue; restore operation should also be cyclic shift]
        }
    }
}

void change(int a[],int p,int i) // @@ [Error: This function performs a direct swap, which does not maintain the original order of the remaining elements required for lexicographic permutation generation; should implement cyclic left/right shift as in reference]
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