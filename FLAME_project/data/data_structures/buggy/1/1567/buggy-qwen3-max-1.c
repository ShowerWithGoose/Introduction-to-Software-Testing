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
            change(a,p,i);
            pai(a,p+1,q);
            change(a,p,i); // @@ [The backtracking step incorrectly swaps back using the same indices, but after the recursive call, the array state has changed. This leads to incorrect restoration of the original array state, causing permutations to be generated in the wrong order or duplicated. The standard way is to swap before recursion and swap back immediately after, but only if the swap operation is symmetric (which it is), however, the loop variable 'i' changes during recursion so restoring with 'i' is invalid because 'i' may not point to the original element anymore.]
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