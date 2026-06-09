#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [Error: function name 'printfa' is misspelled; should be 'printfa' but the function is defined as 'printfa' later, so this is actually correct. However, the function 'printfa' is called before it is declared, which may cause a compilation error in C89/C90. Add a forward declaration or move the function definition before 'pai'.]
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i); // @@ [Error: function 'change' is called before it is declared. In C, functions must be declared or defined before use, otherwise implicit declaration rules apply, which may cause compilation errors or warnings. Add a forward declaration or move the definition before 'pai'.]
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
    
    int i,a[10];
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}