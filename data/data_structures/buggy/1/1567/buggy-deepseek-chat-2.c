#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [Error: function name 'printfa' is misspelled; should be 'printfa' but the function is defined as 'printfa' - actually the function is defined correctly, but the call uses 'printfa' which matches. However, the function 'change' is called but not declared before use, causing implicit declaration warning/error. Also, the function 'printfa' is called before its definition, which may cause issues in older C standards. The main error is that 'change' is used before it is defined.]
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i); // @@ [Error: function 'change' is called before it is defined. In C, functions must be declared or defined before use, otherwise implicit declaration leads to undefined behavior or compilation error.]
            pai(a,p+1,q);
            change(a,p,i); // @@ [Error: same as above: 'change' used before definition.]
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