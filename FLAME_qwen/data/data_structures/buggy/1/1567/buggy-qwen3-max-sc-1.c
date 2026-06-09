#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [Function 'printfa' is not declared before use; also, the standard library function is 'printf', but 'printfa' is a user-defined function that is defined later, which may cause implicit declaration warning/error in strict compilation modes. However, the main issue is that the array size in main is too small for N=10.]
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
    
    int i,a[10]; // @@ [Array size is 10, but when N=10, indices 0 to 9 are used, which is okay. However, the problem states N can be up to 10, so a[10] is sufficient. But note: in the reference program, aa[11] is used. The real error causing compilation failure is likely missing function declaration or definition order, but in C, if functions are defined after use without prior declaration, it may compile with warnings but not necessarily fail. However, the actual compilation error shown ("gcc: not found") is environmental, not code-related. But since the problem says "Compilation Error" and provides this code, the likely intended error is that 'printfa' is used before being declared/defined, and in strict C standards (like C99+), implicit function declarations are not allowed, leading to compilation error. Also, the array size should be at least 11 to match the problem's 1<=N<=10 safely, though 10 is technically enough for N=10 (0..9). However, the primary compilation error reason is the undeclared function 'printfa'.]
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}