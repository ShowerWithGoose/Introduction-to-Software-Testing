#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [Function 'printfa' is called but not declared before use; also, the logic for generating all permutations requires handling the base case when p > q or p == q correctly, but more critically, the function 'printfa' is defined later and missing a declaration, which may cause compilation issues in strict C standards (though some compilers allow it). However, the main error is that the base case should trigger when p == q+1 or similar depending on indexing. But the actual critical error causing failure is likely the undeclared function call in older C standards.]
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i);
            pai(a,p+1,q);
            change(a,p,i);
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
    
    int i,a[10]; // @@ [Array size is fixed to 10, but N can be up to 10, so a[10] is sufficient (indices 0-9). However, if N=10, a[10] is okay since we use indices 0 to 9. So this is not an error. The real issue is elsewhere.]
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}