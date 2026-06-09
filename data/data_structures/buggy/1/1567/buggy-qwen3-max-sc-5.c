#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [function 'printfa' is called but not declared before use; also, the function name is misspelled (should be 'print' or similar standard name, but more critically, it's undefined at point of call)]
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i); // @@ [function 'change' is called but not declared before use]
            pai(a,p+1,q);
            change(a,p,i); // @@ [function 'change' is called but not declared before use]
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
    
    int i,a[10]; // @@ [array size is fixed to 10, but N can be up to 10, so a[10] is sufficient; however, no error here. The real issue is missing function declarations causing compilation error]
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}