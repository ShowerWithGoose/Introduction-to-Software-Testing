#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [function 'printfa' is not declared before use; also, the standard library function is 'printf', but 'printfa' is user-defined and should be declared before main or before its first use]
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i); // @@ [function 'change' is not declared before use; in C, functions must be declared or defined before being called unless using implicit declaration (which is invalid in modern C standards)]
            pai(a,p+1,q);
            change(a,p,i); // @@ [same as above: 'change' used without prior declaration]
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
    
    int i,a[10]; // @@ [if N is 10, then a[10] is out of bounds since valid indices are 0-9; array size should be at least 11 to support N=10 as per problem constraint 1<=N<=10]
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}