#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [function 'printfa' is called but not declared before use; also, standard library function 'printf' is used without including <stdio.h> properly (though it is included, the real issue is undeclared function in C89 mode)]
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i); // @@ [function 'change' is called before its declaration; in C, this can cause implicit declaration error or type mismatch]
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
    
    int i,a[10]; // @@ [if N is 10, a[10] has indices 0..9, which is correct, but array size should be at least 10; however, the real compilation error is due to missing function declarations before use]
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}